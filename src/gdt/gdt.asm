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