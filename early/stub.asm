    org 0xFFF0
    bits 16
_boot:
    cli
    jmp 0xF000:0x0000

    times 16-($-$$) db 0
