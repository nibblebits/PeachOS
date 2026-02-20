/*
 * PeachOS 32-Bit Kernel project
 * Copyright (C) 2026 Daniel McCarthy <daniel@dragonzap.com>
  * This file is part of th PeachOS Kernel.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 * For full source code, documentation, and structured learning,
 * see the official kernel development video course:
 * https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 *
 * The new part two course is now here
 * Learn to extend your kernel into 64-bit long mode with GUI
 * Get all modules today here: https://dragonzap.com/offer/developing-a-multithreaded-kernel-from-scratch-part-two-full-series
 * 
 * Or get them individually here: 
 * MODULE 1 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-one
 * MODULE 2 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-two
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10


#define PEACHOS_TOTAL_INTERRUPTS 512

// 100MB heap size
#define PEACHOS_HEAP_SIZE_BYTES 104857600
#define PEACHOS_HEAP_BLOCK_SIZE 4096
#define PEACHOS_HEAP_ADDRESS 0x01000000 
#define PEACHOS_HEAP_TABLE_ADDRESS 0x00007E00

#define PEACHOS_SECTOR_SIZE 512

#define PEACHOS_MAX_FILESYSTEMS 12
#define PEACHOS_MAX_FILE_DESCRIPTORS 512

#define PEACHOS_MAX_PATH 108

#define PEACHOS_TOTAL_GDT_SEGMENTS 6

#define PEACHOS_PROGRAM_VIRTUAL_ADDRESS 0x400000
#define PEACHOS_USER_PROGRAM_STACK_SIZE 1024 * 16
#define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START 0x3FF000
#define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_END PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START - PEACHOS_USER_PROGRAM_STACK_SIZE

#define PEACHOS_MAX_PROGRAM_ALLOCATIONS 1024
#define PEACHOS_MAX_PROCESSES 12

#define USER_DATA_SEGMENT 0x23
#define USER_CODE_SEGMENT 0x1b

#define PEACHOS_MAX_ISR80H_COMMANDS 1024

#define PEACHOS_KEYBOARD_BUFFER_SIZE 1024

#endif