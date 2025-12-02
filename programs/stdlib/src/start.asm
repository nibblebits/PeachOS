; Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
; This file is licensed under the GPLv2 license.
; To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch

[BITS 32]

global _start
extern c_start
extern peachos_exit

section .asm

_start:
    call c_start
    call peachos_exit
    ret