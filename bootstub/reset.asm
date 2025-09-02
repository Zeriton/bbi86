    org 0xFFF0
    bits 16
on_reset:
    cli
    jmp (FIRMWARE_ROM_START >> 4):(FIRMWARE_ROM_START & 0xF)
    
    times 16-($-$$) db 0
