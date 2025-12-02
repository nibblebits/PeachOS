; Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
; This file is licensed under the GPLv2 license.
; To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch

section .asm

global tss_load

tss_load:
    push ebp
    mov ebp, esp
    mov ax, [ebp+8] ; TSS Segment
    ltr ax
    pop ebp
    ret