    bits 16

    section .rodata

;;; `gdt_start` - `gdt_end`: Global Descriptor Table (Basic Setup)
;;; Format:
;;;     - Entry 0 (NULL - 64-bit)
;;;     - Entry 1 (Code Segment - 64-bit)
;;;     - Entry 2 (Data Segment - 64-bit)
gdt_start:
    ;; Null Entry
    dq 0

    ;; Code Segment
    db 0
    db 0b01001111
    db 0b10011111
    db 0
    dw 0
    dw 0xFFFF

    ;; Data Segment
    db 0
    db 0b01001111
    db 0b10010011
    db 0
    dw 0
    dw 0xFFFF
gdt_end:

;;; `gdt_desc`: GDT (Global Descriptor Table) Descriptor
;;; Format:
;;;     - limit (16-bit)
;;;     - base (32-bit)
gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start

    section .text
    extern __pentry_addr

    global _start
_start:
    ;; Setting up the GDT (Global Descriptor Table)
    mov eax, gdt_desc                ; Remember, we are still in 16-bit addressing so we must use
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
.L1:
    hlt
    jmp .L1
