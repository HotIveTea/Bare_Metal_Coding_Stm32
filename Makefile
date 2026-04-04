# Toolchain 
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy 
SZ = arm-none-eabi-size
# Flags
CFLAGS = -mcpu=cortex-m3 -mthumb -O0 -Wall -g -IInc
# Read more in GCC Manual - ARM Option - Options That Control Optimization - Options to Request or Suppress Warnings - Options for Debugging Your Program
LDFLAGS = -T stm32f103.ld -nostdlib -Wl,-Map=project.map
SRC = Src/main.c Inc/gpio.c startup.c 
OBJ = $(SRC:.c=.o) # Set các file .c thành file .o
TARGET = project
all: $(TARGET).bin $(TARGET).hex # file bin va file hex
$(TARGET).bin: $(TARGET).elf # Tao file bin tu file .elf
		$(OBJCOPY) -O binary $< $@
$(TARGET).hex: $(TARGET).elf # Tao file hex tu file .elf
		$(OBJCOPY) -O ihex $< $@
$(TARGET).elf: $(OBJ) # Link cac file lai voi nhau 
		$(CC) $(LDFLAGS) $^ -o $@
		$(SZ) $@
%.o : %.c 
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: flash
flash: $(TARGET).elf
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program $< verify reset exit"
.PHONY: clean
clean:
	rm -rf *.o *.elf *.bin *.hex *.map