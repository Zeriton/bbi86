# bbi86 (Basic Boot Interface x86)
Modern 32-bit+ x86 firmware, designed to replace both UEFI &amp; BIOS

> [!WARNING]
> **bbi86** is currently an *experimental* project that is currently \
> focusing on AMD server systems that support **openSIL**

## Build Guide
To build **bbi86** there is a few but limited options. It is recommended \
for you to use the 'world' target as that'll build everything necessary.
```bash
$ make world
```
#### BUT WAIT!
You might encounter a missing '.config' error, well to fix that \
simply use the 'menuconfig' target, or 'defconfig' for a very simple configuration.
```bash
$ make menuconfig
```
Now, you have basically built **bbi86**, but lets say you need a read-to-go \
image, well that's pretty simple as we luckily have the 'image' target \
exactly for that situation.
```bash
$ make image
```
### Useful Build Options
- TOOLCHAIN: the toolchain to use, only supports 'gnu' & 'llvm'
  - gnu (gcc, ld, as)
      - CROSS_COMPILER: cross compiler prefix, by default uses 'i686-elf-'
  - llvm (clang, ld.lld)
      - TARGET_TRIPLE: llvm target triple, by default uses 'i386-unknown-none'
- FIRMWARE_ROM_START: the address of where the firmware image will start
