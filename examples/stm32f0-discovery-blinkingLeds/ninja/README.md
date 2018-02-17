## Why Ninja?
Because I did not want to pollute the repo with various build-system specific files and and I failed to make Make or CMake work with source files scattered in various directories with relative paths. Besides, Ninja is cool and the synthax actually makes sense without spending a lot of time getting to understand it. And is fast (not that it matters in this particular case).

## Prerequisites
This directory contains a ninja file that can be used to build the demo project. It requires the following installed:
1. An arm-gcc compiler - For example one from https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
2. OpenOCD - Tested with a build from https://github.com/gnu-mcu-eclipse/openocd/releases but probably anythig newer than 0.10 will be OK.
3. Ninja - any reasonably new version will work.

## Building
Make sure the toolchain executables are available on PATH. For example, in *fish*(current shell of choice):
```
ivan@debian-xps ~/W/Z/g/c/e/s/ninja> set -gx PATH $PATH ~/Work/toolchains/gcc-arm-none-eabi-7-2017-q4-major/bin/
```

Then simply invoke Ninja:
```
ivan@debian-xps ~/W/Z/g/c/e/s/ninja> ninja -v -f cocoOS_stm32f0_blink.ninja
```
In a few seconds, the demo project should be built.

## Running
Start OpenOCD:
```
ivan@debian-xps ~/W/Z/g/c/e/s/ninja> ~/opt/gnu-mcu-eclipse/openocd/0.10.0-7-20180123-1217/bin/openocd -f ../common/debug/STLink_OpenOCD.cfg
```

Then start GDB: 
```
ivan@debian-xps ~/W/Z/g/c/e/s/ninja> arm-none-eabi-gdb cocoOS_stm32f0_blink.elf
...
Reading symbols from cocoOS_stm32f0_blink.elf...done.
(gdb) target remote localhost:3333
Remote debugging using localhost:3333
0x00000000 in ?? ()
(gdb) monitor reset halt
adapter speed: 1000 kHz
target halted due to debug-request, current mode: Thread
xPSR: 0xc1000000 pc: 0x08000110 msp: 0x20002000
(gdb) load
Loading section .isr_vector, size 0x118 lma 0x8000000
Loading section .inits, size 0x14 lma 0x8000118
Loading section .text, size 0x9a0 lma 0x800012c
Loading section .data, size 0x4 lma 0x8000acc
Start address 0x80000d4, load size 2768
Transfer rate: 8 KB/sec, 692 bytes/write.
(gdb) tbreak main
(gdb) tbreak main.c:112
Temporary breakpoint 1 at 0x80008b0: file ../common/src/main.c, line 141.
(gdb) c
Continuing.
Temporary breakpoint 2, led_blink_task () at ../common/src/main.c:112
112             task_wait(OS_MS_TO_TICKS(LED_TICK_PERIOD));
```

That's it!
