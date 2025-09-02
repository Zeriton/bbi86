# bbi86 (Basic Boot Interface x86)
Modern 32-bit+ x86 firmware, designed to replace both UEFI &amp; BIOS

> [!WARNING]
> **bbi86** is currently an *experimental* project that is currently \
> focusing on AMD server systems that support **openSIL**

# Goals
- *Forcefully* modernize x86: will promote FDTs, hide away older x86 features..
- Handing the payload most power, no more splash screens, no firmware GUI.. all controlled by the payload.
- Modular, the [`early/`](early) stage will be ROM only (non-modular), but the core firmware will be stored on disk. This
  allows the use of `Modules` that vendors or whoever can add.
- No unnecessary I/O initialization & use by default: absolutely no VGA, no special I/O devices. **ONLY UART** \
...
