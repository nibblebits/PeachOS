[BITS 32]

global _start
extern main

section .asm

_start:
    call main
    ret