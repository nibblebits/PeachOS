; Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
; This file is licensed under the GPLv2 license.
; To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch

section .asm
global gdt_load

gdt_load:
    mov eax, [esp+4]
    mov [gdt_descriptor + 2], eax
    mov ax, [esp+8]
    mov [gdt_descriptor], ax
    lgdt [gdt_descriptor]
    ret


section .data
gdt_descriptor:
    dw 0x00 ; Size
    dd 0x00 ; GDT Start Address