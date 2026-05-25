# EMCOD

WORK IN PROGRESS

> [!NOTE]
>This repo is partly based on [STM32N6-GettingStarted-ObjectDetection](https://github.com/STMicroelectronics/STM32N6-GettingStarted-ObjectDetection)

> [!WARNING]
> Third-party components under `Middlewares/`, 'Application/STM32CubeIDE/' and `STM32Cube_FW_N6/`, are not covered by the MIT License. They remain subject to their own respective license terms.

## Compilation
within the application folder run
```bash
make -j8
```
Once the compilation is done, run
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
and in a seperate terminal upload the code via
```bash
arm-none-eabi-gdb build/Application/Project.elf
```
```bash
target remote :61234
monitor reset
load
continue
```