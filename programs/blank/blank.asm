[BITS 32]

section .asm

global _start

_start:

    mov eax, 0
    int 0x80
    
    jmp $
