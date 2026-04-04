TARGET = project
BUILD_DIR = Build
# Toolchain 
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy 
SZ = arm-none-eabi-size
# Flags
CPU = -mcpu=cortex-m3
MCU = $(CPU) -mthumb
OPT = -O0
CFLAGS = $(MCU) $(OPT) -Wall -g
CFLAGS += -IInc
# Read more in GCC Manual - ARM Option - Options That Control Optimization - Options to Request or Suppress Warnings - Options for Debugging Your Program
LDSCRIPT = stm32f103.ld
LDFLAGS = $(MCU) -T$(LDSCRIPT) -nostdlib -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections
C_SOURCES = $(wildcard Src/*.c)
OBJECTS = $(patsubst Src/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES)) # Set các file .c thành file .o
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin# file bin va file hex
# 1. Liên kết các file .o thành file chạy .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) | $(BUILD_DIR)
		$(CC) $(OBJECTS) $(LDFLAGS) -o $@
		$(SZ) $@
# 2. Tạo file .hex từ file .elf
$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
		$(OBJCOPY) -O ihex $< $@
# 3. Tạo file .bin từ file .elf
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
		$(OBJCOPY) -O binary -S $< $@
# 4. Biên dịch từng file .c thành file .o
$(BUILD_DIR)/%.o: Src/%.c | $(BUILD_DIR)
		$(CC) -c $(CFLAGS) $< -o $@
# 5. Tự động tạo thư mục Build nếu chưa có (lệnh này chạy mượt trên Windows)
$(BUILD_DIR):
		if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
.PHONY: clean flash
flash: $(BUILD_DIR)/$(TARGET).elf
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program $< verify reset exit"
clean:
	-rmdir /s /q $(BUILD_DIR)