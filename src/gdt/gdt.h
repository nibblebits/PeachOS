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

#ifndef GDT_H
#define GDT_H
#include <stdint.h>
struct gdt
{
    uint16_t segment;
    uint16_t base_first;
    uint8_t base;
    uint8_t access;
    uint8_t high_flags;
    uint8_t base_24_31_bits;
} __attribute__((packed));

struct gdt_structured
{
    uint32_t base;
    uint32_t limit;
    uint8_t type;
};

void gdt_load(struct gdt* gdt, int size);
void gdt_structured_to_gdt(struct gdt* gdt, struct gdt_structured* structured_gdt, int total_entires);
#endif