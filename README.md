# Bare Metal coding examples

A repo with coding examples used for a bare metal coding course using:

- CPUlator de1soc simulator - https://cpulator.01xz.net/?sys=arm-de1soc
- Wokwi Raspberry Pi Pico simulator - https://wokwi.com/pi-pico
- and a real Raspberry Pi Pico version 1, RP2040

## Run in a GitHub codespace?

From this GitHub repo - open a codespace, then try these commands:

    $ sudo apt update
    $ sudo apt install build-essential gcc-arm-none-eabi gdb-multiarch

## Run in a Docker container?

Try something like this:

    $ git clone https://github.com/olvemaudal/baremetal.git
    $ cd baremetal
    $ docker build -t devbox .
    $ docker run --rm -it -v  ${PWD}:/workspace devbox

## Compile and run the display demo app on the de1soc simulator

To create a small demo app for the de1soc, try some of these commands:

    $ cat de1soc-display-demo.S
    $ make de1soc-display-demo
    $ arm-none-eabi-objdump -d de1soc-display-demo.elf

Then download the .elf file, to your disk, and upload it to the CPUlator.

## Upload source code to the CPUlator editor

While experimenting with the CPUlator you may just write or paste stuff directly into the editor. Eg, try to paste

    de1soc-shownumber.c

into the editor and click compile and load, and then continue.

## 