# EMCOD

WORK IN PROGRESS

> [!NOTE]
>This repo was initially based on [STM32N6-GettingStarted-ObjectDetection](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection)

> [!WARNING]
> Third-party components under `Middlewares/`, `Application/STM32CubeIDE/` and `STM32Cube_FW_N6/`, are not covered by the MIT License. They remain subject to their own respective license terms.

## Table of Contents

- [contributing](#contributing)
- [dependencies](#dependencies)
- [build and run](#build-and-run)
- [useful gdb commands](#useful-gdb-commands)

## contributing

please read our [coding guidelines](./coding-guidelines.md) before contributing

commit to your own branch

```bash
git checkout -b nickname
```

or if the branch already exists

```bash
git checkout nickname
```

then pull request to main. Remember to ```git pull origin main``` after your repository was merged

## dependencies

install cmake
install screen
ensure the subfolders of [STM32CubeCLT](https://www.st.com/en/development-tools/stm32cubeclt.html) below are in path
```
GNU-tools-for-STM32/bin
STLink-gdb-server/bin
STM32CubeProgrammer/bin
```

## build and run

the instructions below assume that STM32CubeCLT, `arm-none-eabi-gdb`, and `screen` are installed and available in your shell.

### 1. build the application

from the `Application` directory, run:

```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake
cmake --build build --parallel
```

this builds the ELF file at:

```bash
Application/build/Application/Project.elf
```

### 2. start the ST-LINK GDB server

open a new terminal and run:

```bash
ST-LINK_gdbserver \
  -p 61234 \
  -l 1 \
  -d \
  -s \
  -cp STM32CubeProgrammer/bin \
  -m 1 \
  -g
```

keep this terminal open while debugging or flashing the board.

### 3. open the UART monitor

open another terminal and run:

```bash
screen /dev/ttyACM0 115200
```

for linux, the devide can be found via 
```bash
ls /dev/ttyACM*
```

for mac os, the device can be found via
```bash
ls /dev/cu.usbmodem*
```

this listens to the board's UART output at 115200 baud.

to exit `screen`, press:

```text
ctrl+A, then K, then Y
```

### 4. flash and run the application

open a third terminal from the `Application` directory and start GDB:

```bash
arm-none-eabi-gdb build/Application/Project.elf
```

inside the GDB prompt, run:

```gdb
target remote :61234
monitor reset
load
continue
```

the application should now be running with screen displaying UART output.

## useful gdb commands

set a breakpoint at a function:

```gdb
break function_name
```

continue execution:

```gdb
continue
```

step into the next line or function:

```gdb
step
```

step over the next line:

```gdb
next
```

print a variable:

```gdb
print variable_name
```

show a backtrace:

```gdb
backtrace
```