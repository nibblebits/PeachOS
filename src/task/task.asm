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
section .asm

global restore_general_purpose_registers
global task_return
global user_registers

; void task_return(struct registers* regs);
task_return:
    mov ebp, esp
    ; PUSH THE DATA SEGMENT (SS WILL BE FINE)
    ; PUSH THE STACK ADDRESS
    ; PUSH THE FLAGS
    ; PUSH THE CODE SEGMENT
    ; PUSH IP

    ; Let's access the structure passed to us
    mov ebx, [ebp+4]
    ; push the data/stack selector
    push dword [ebx+44]
    ; Push the stack pointer
    push dword [ebx+40]

    ; Push the flags
    mov eax, [ebx+36]
    or eax, 0x200 ; interrupt enable flag set
    push eax

    ; Push the code segment
    push dword [ebx+32]

    ; Push the IP to execute
    push dword [ebx+28]

    ; Setup some segment registers
    mov ax, [ebx+44]
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    push dword [ebp+4]
    call restore_general_purpose_registers
    add esp, 4

    ; Let's leave kernel land and execute in user land!
    iretd
    
; void restore_general_purpose_registers(struct registers* regs);
restore_general_purpose_registers:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]
    mov edi, [ebx]
    mov esi, [ebx+4]
    mov ebp, [ebx+8]
    mov edx, [ebx+16]
    mov ecx, [ebx+20]
    mov eax, [ebx+24]
    mov ebx, [ebx+12]
    add esp, 4
    ret

; void user_registers()
user_registers:
    mov ax, 0x23
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    ret