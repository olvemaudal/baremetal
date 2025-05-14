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
    $ docker run --rm -it -v ${PWD}:/workspace devbox

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

## Bare metal coding on the RP2040

We will now use a public github repo to demonstrate how to create a simple blinky app on the Raspberry Pi Pico RP2040. Try these commands:

    $ git clone https://github.com/vxj9800/bareMetalRP2040.git
    $ cd bareMetalRP2040
    $ git submodule update --init
    $ cd 01_bootupBlinky/
    $ make
    $ ls -al boot2Blinky.uf2

Plug in the Pico to your USB port while holding the BOOTSEL button so that it shows up as a USB storage. Then copy the uf2 file onto the drive, and watch the Pico reboot and start to blink.

## Compile, link and run primedemo

This is an attempt to show a complete C program, including testing and linking. Try these commands:

    $ gcc -c primelib.c
    $ gcc primelib_tests.c primelib.o
    $ ./a.out
    All tests passed
    $ gcc -o primedemo primedemo.c primelib.o
    $ ./primedemo

## Links and resources

- HackadayU: Raspberry Pi Pico and RP2040 (YouTube)
- RP2040 - Introduction to Assembly Language (YouTube)
- https://github.com/raspberrypi/pico-bootrom-rp2040
- https://github.com/raspberrypi/pico-sdk
- https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf
- https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf
- https://cpulator.01xz.net/?sys=arm-de1soc
- https://fpgacademy.org/Downloads/DE1-SoC_Computer_ARM.pdf
- https://developer.arm.com/documentation/dui0662/latest/
- Assembly Language Programming with ARM  https://www.youtube.com/watch?v=gfmRrPjnEw4
- https://godbolt.org/
- Reintroduction to C https://www.youtube.com/watch?v=Kq7WIexp6JU
- olvemaudal.com
