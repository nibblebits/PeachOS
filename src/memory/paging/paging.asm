; Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
; This file is licensed under the GPLv2 license.
; To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch

[BITS 32]

section .asm

global paging_load_directory
global enable_paging

paging_load_directory:
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    mov cr3, eax
    pop ebp
    ret

enable_paging:
    push ebp
    mov ebp, esp
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    pop ebp
    ret
