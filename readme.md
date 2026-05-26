# EMCOD

WORK IN PROGRESS

> [!NOTE]
>This repo was initially based on [STM32N6-GettingStarted-ObjectDetection](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection)

> [!WARNING]
> Third-party components under `Middlewares/`, `Application/STM32CubeIDE/` and `STM32Cube_FW_N6/`, are not covered by the MIT License. They remain subject to their own respective license terms.

## contributing

> [!NOTE]
>Remember to `\r` before `\n` when using printf.

commit to your own branch

```bash
git checkout -b nickname
```

or if the branch already exists

```bash
git checkout nickname
```

Then pull request to main. Remember to ```git pull origin main``` after your repository was merged

## mac os dependencies

Install [STM32CubeCLT](https://www.st.com/en/development-tools/stm32cubeclt.html)

Apple build basics
```bash
xcode-select --install
```

Make and ARM embedded compiler/toolchain
```bash
brew install git make
brew install arm-none-eabi-gcc
```

## Build and Run

The instructions below assume that STM32CubeCLT, `arm-none-eabi-gdb`, and `screen` are installed and available in your shell.

### 1. Build the application

From the `Application` directory, run:

```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake
cmake --build build --parallel
```

This builds the ELF file at:

```bash
Application/build/Application/Project.elf
```

### 2. Start the ST-LINK GDB server

Open a new terminal and run:

```bash
ST-LINK_gdbserver \
  -p 61234 \
  -l 1 \
  -d \
  -s \
  -cp /opt/st/stm32cubeclt_1.21.0/STM32CubeProgrammer/bin \
  -m 1 \
  -g
```

Keep this terminal open while debugging or flashing the board.

### 3. Open the UART monitor

Open another terminal and run:

```bash
screen /dev/ttyACM0 115200
```

This listens to the board's UART output at 115200 baud.

To exit `screen`, press:

```text
Ctrl+A, then K, then Y
```

### 4. Flash and run the application

Open a third terminal from the `Application` directory and start GDB:

```bash
arm-none-eabi-gdb build/Application/Project.elf
```

Inside the GDB prompt, run:

```gdb
target remote :61234
monitor reset
load
continue
```

The application should now be running with screen displaying UART output.

## Useful gdb commands

Set a breakpoint at a function:

```gdb
break function_name
```

Continue execution:

```gdb
continue
```

Step into the next line or function:

```gdb
step
```

Step over the next line:

```gdb
next
```

Print a variable:

```gdb
print variable_name
```

Show a backtrace:

```gdb
backtrace
```