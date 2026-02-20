; PeachOS 32-Bit Kernel project
; Copyright (C) 2026 Daniel McCarthy <daniel@dragonzap.com>
; This file is part of th PeachOS Kernel.
;
; This program is free software; you can redistribute it and/or
; modify it under the terms of the GNU General Public License
; version 2 as published by the Free Software Foundation.
;
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
; See the GNU General Public License version 2 for more details.
;
; You should have received a copy of the GNU General Public License
; along with this program; if not, see <https://www.gnu.org/licenses/>.
;
; For full source code, documentation, and structured learning,
; see the official kernel development video course:
; https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
;
; The new part two course is now here
; Learn to extend your kernel into 64-bit long mode with GUI
; Get all modules today here: https://dragonzap.com/offer/developing-a-multithreaded-kernel-from-scratch-part-two-full-series
;
; Or get them individually here: 
; MODULE 1 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-one
; MODULE 2 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-two
;

[BITS 32]

global _start
global kernel_registers
extern kernel_main

CODE_SEG equ 0x08
DATA_SEG equ 0x10

_start:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp


    ; Remap the master PIC
    mov al, 00010001b
    out 0x20, al ; Tell master PIC

    mov al, 0x20 ; Interrupt 0x20 is where master ISR should start
    out 0x21, al

    mov al, 0x04 ; ICW3
    out 0x21, al

    mov al, 00000001b
    out 0x21, al
    ; End remap of the master PIC

    call kernel_main

    jmp $

kernel_registers:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    ret


times 512-($ - $$) db 0