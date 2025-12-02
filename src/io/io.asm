; Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
; This file is licensed under the GPLv2 license.
; To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch

section .asm

global insb
global insw
global outb
global outw

insb:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, [ebp+8]
    in al, dx

    pop ebp
    ret

insw:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, [ebp+8]
    in ax, dx

    pop ebp
    ret

outb:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov edx, [ebp+8]
    out dx, al

    pop ebp
    ret

outw:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov edx, [ebp+8]
    out dx, ax

    pop ebp
    ret