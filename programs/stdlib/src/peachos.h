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

#ifndef PEACHOS_H
#define PEACHOS_H
#include <stddef.h>
#include <stdbool.h>


struct command_argument
{
    char argument[512];
    struct command_argument* next;
};

struct process_arguments
{
    int argc;
    char** argv;
};


void print(const char* filename);
int peachos_getkey();

void* peachos_malloc(size_t size);
void peachos_free(void* ptr);
void peachos_putchar(char c);
int peachos_getkeyblock();
void peachos_terminal_readline(char* out, int max, bool output_while_typing);
void peachos_process_load_start(const char* filename);
struct command_argument* peachos_parse_command(const char* command, int max);
void peachos_process_get_arguments(struct process_arguments* arguments);
int peachos_system(struct command_argument* arguments);
int peachos_system_run(const char* command);
void peachos_exit();
#endif