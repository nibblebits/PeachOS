[BITS 32]

section .asm

global _start

_start:
    push eax
    push dword 30
    mov eax, 0 ; The SUM command
    int 0x80
    
    jmp $


