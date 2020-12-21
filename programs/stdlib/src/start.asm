[BITS 32]

global _start
extern c_start
extern peachos_exit

section .asm

_start:
    call c_start
    call peachos_exit
    ret