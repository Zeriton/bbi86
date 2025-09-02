    bits 16
    org FIRMWARE_ROM_START & 0x000FFFFF
_start:
    ;; Setting up the GDT (Global Descriptor Table)
    mov eax, gdt_descriptor          ; Remember, we are still in 16-bit addressing so we must use
                                     ; convert the 32-bit address into a valid segmented address
    mov ebx, eax
    shr eax, 4
    and ebx, 0xF
    mov ds, ax
    lgdt [ds:bx]                     ; Set the GDTR register to `gdt_desc`

    ;; Enable A20 line (Enable the 21st bit in any memory access)
    ;; NOTE: This only uses the fast A20 gate method---we will not
    ;;       support older systems that don't have this.
    in al, 0x92
    or al, 2
    out 0x92, al

    ;; Set PE bit (Protection Enable) in CR0 (Control Register 0)
    ;; Note: Enabled protected mode, hopefully with GDT set properly & A20 enabled.
    mov eax, cr0
    or al, 1
    mov cr0, eax
    
	jmp dword 0x08:after
.L1:
    hlt
    jmp .L1

;;; -----------------------------------------------
;;; DATA SECTION
;;; -----------------------------------------------

;;; GDT (Global Descriptor Table)
;;; NOTE: See 'https://wiki.osdev.org/Global_Descriptor_Table' for
;;;       more information about the GDT.
gdt_descriptor:
    dw .end - .start - 1
    dd .start
.start:
    ;; Null Entry
    dq 0

    ; Code Segment: base=0, limit=0xFFFFF, 32-bit, executable, readable
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x9A
    db 0xCF
    db 0x00

    ; Data Segment: base=0, limit=0xFFFFF, 32-bit, readable/writable
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x92
    db 0xCF
    db 0x00
.end:

    times 256-($-$$) db 0           ; Technically we don't need to pad it, but it keeps the file size predictable
    
after:                              ; Points to the starting address of the next stage
