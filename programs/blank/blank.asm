[BITS 32]

section .asm

global _start

_start:
    mov esp, 0x400004
    push eax
    push dword 30
    mov eax, 0 ; The SUM command
    int 0x80
    
    jmp $


