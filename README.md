# Bare-Metal Coding: STM32 From Scratch

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Build](https://img.shields.io/badge/Build-Make-orange.svg)
![MCU](https://img.shields.io/badge/MCU-STM32F108-green.svg)
![Status](https://img.shields.io/badge/Status-Active_Learning-success.svg)

## Project Overview

This project is a deep dive into **bare-metal firmware engineering**, focusing on the STM32F108 microcontroller. The goal is to strip away high-level hardware abstraction layers (HAL) and standard peripheral libraries to understand what happens at the silicon level.

By building everything from the ground up, this project serves as a foundational guide to understanding microcontrollers, bridging the gap between hardware architecture and low-level C programming.

> _"This project will teach you how to use bare-metal on any microcontroller and use your imagination to build anything you want. This is a learning process, so don't be afraid to make mistakes."_

## Key Objectives

- **STM32 Architecture:** Understand the internal bus matrix, memory map, clock tree, and core peripherals of the ARM Cortex-M architecture.
- **Boot Process & Startup Code:** Write the `startup.c/s` from scratch, defining vector tables, initializing data/bss segments, and handing over control to `main()`.
- **Linker Scripts (`.ld`):** Design custom linker scripts to precisely control memory allocation for Flash and SRAM.
- **Build Systems:** Master `Makefile` to compile, assemble, and link the project using the GNU Arm Embedded Toolchain.
- **Register-Level Programming:** Control GPIOs, Timers, and communication protocols by directly manipulating memory-mapped registers.

## Project Structure

_(Adjust the tree below based on your actual repository structure)_

```text
📦 bare-metal-stm32
 ┣ 📂 .vscode
 ┣ 📂 Inc               # Header files, register maps, macros
 ┣ 📂 Src               # Source C files (main.c, peripheral drivers)
 ┣ 📂 Build         # Contains files.o, .elf, .map
 ┣ 📜 Makefile          # Build automation
 ┣ 📜 stm32f103.ld    # Linker script for memory layout
 ┗ 📜 README.md         # Project documentation
```

## Prerequisites & Tools

To build and flash this project, you will need the following tools:

- **Compiler:** [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm) (`arm-none-eabi-gcc`)
- **Build System:** `Make`
- **Flashing/Debugging:** OpenOCD & ST-Link v2 (or your preferred debugger)

## Quick Start

1. Clone the repository:
   ```bash
   git clone [https://github.com/HotIveTea/Bare_Metal_Coding_Stm32.git](https://github.com/HotIveTea/Bare_Metal_Coding_Stm32.git)
   cd Bare_Metal_Coding_Stm32
   ```
2. Build the project:
   ````bash
   make all
   or
   ```bash
   mingw32-make
   ````
3. Flash the firmware to the board:
   ````bash
   make flash
   or
   ```bash
   mingw32-make flash
   ````

## Developer's Diary

I document my daily progress, bugs encountered, and architectural concepts learned on Notion. Feel free to follow along with my thought process:
[text](https://www.notion.so/Bare-metal-coding-32f984656d2c80aa8312f05e2aaa0d0b?source=copy_link)

## Philosophy

Bare-metal programming can be unforgiving, but it is deeply rewarding. A hard fault or a segmentation fault is just a stepping stone to fully mastering embedded systems. Keep tinkering, keep breaking things, and keep learning.
