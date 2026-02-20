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

global print:function
global peachos_getkey:function
global peachos_malloc:function
global peachos_free:function
global peachos_putchar:function
global peachos_process_load_start:function
global peachos_process_get_arguments:function 
global peachos_system:function
global peachos_exit:function

; void print(const char* filename)
print:
    push ebp
    mov ebp, esp
    push dword[ebp+8]
    mov eax, 1 ; Command print
    int 0x80
    add esp, 4
    pop ebp
    ret

; int peachos_getkey()
peachos_getkey:
    push ebp
    mov ebp, esp
    mov eax, 2 ; Command getkey
    int 0x80
    pop ebp
    ret

; void peachos_putchar(char c)
peachos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 3 ; Command putchar
    push dword [ebp+8] ; Variable "c"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void* peachos_malloc(size_t size)
peachos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4 ; Command malloc (Allocates memory for the process)
    push dword[ebp+8] ; Variable "size"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void peachos_free(void* ptr)
peachos_free:
    push ebp
    mov ebp, esp
    mov eax, 5 ; Command 5 free (Frees the allocated memory for this process)
    push dword[ebp+8] ; Variable "ptr"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void peachos_process_load_start(const char* filename)
peachos_process_load_start:
    push ebp
    mov ebp, esp
    mov eax, 6 ; Command 6 process load start ( stars a process )
    push dword[ebp+8] ; Variable "filename"
    int 0x80
    add esp, 4
    pop ebp
    ret

; int peachos_system(struct command_argument* arguments)
peachos_system:
    push ebp
    mov ebp, esp
    mov eax, 7 ; Command 7 process_system ( runs a system command based on the arguments)
    push dword[ebp+8] ; Variable "arguments"
    int 0x80
    add esp, 4
    pop ebp
    ret


; void peachos_process_get_arguments(struct process_arguments* arguments)
peachos_process_get_arguments:
    push ebp
    mov ebp, esp
    mov eax, 8 ; Command 8 Gets the process arguments
    push dword[ebp+8] ; Variable arguments
    int 0x80
    add esp, 4
    pop ebp
    ret

; void peachos_exit()
peachos_exit:
    push ebp
    mov ebp, esp
    mov eax, 9 ; Command 9 process exit
    int 0x80
    pop ebp
    ret