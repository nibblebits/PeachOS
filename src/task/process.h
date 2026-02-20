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

#ifndef PROCESS_H
#define PROCESS_H
#include <stdint.h>
#include <stdbool.h>

#include "task.h"
#include "config.h"

#define PROCESS_FILETYPE_ELF 0
#define PROCESS_FILETYPE_BINARY 1

typedef unsigned char PROCESS_FILETYPE;

struct process_allocation
{
    void* ptr;
    size_t size;
};

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

struct process
{
    // The process id
    uint16_t id;

    char filename[PEACHOS_MAX_PATH];

    // The main process task
    struct task* task;

    // The memory (malloc) allocations of the process
    struct process_allocation allocations[PEACHOS_MAX_PROGRAM_ALLOCATIONS];

    PROCESS_FILETYPE filetype;

    union
    {
        // The physical pointer to the process memory.
        void* ptr;
        struct elf_file* elf_file;
    };
    

    // The physical pointer to the stack memory
    void* stack;

    // The size of the data pointed to by "ptr"
    uint32_t size;

    struct keyboard_buffer
    {
        char buffer[PEACHOS_KEYBOARD_BUFFER_SIZE];
        int tail;
        int head;
    } keyboard;

    // The arguments of the process.
    struct process_arguments arguments;
};

int process_switch(struct process* process);
int process_load_switch(const char* filename, struct process** process);
int process_load(const char* filename, struct process** process);
int process_load_for_slot(const char* filename, struct process** process, int process_slot);
struct process* process_current();
struct process* process_get(int process_id);
void* process_malloc(struct process* process, size_t size);
void process_free(struct process* process, void* ptr);

void process_get_arguments(struct process* process, int* argc, char*** argv);
int process_inject_arguments(struct process* process, struct command_argument* root_argument);
int process_terminate(struct process* process);

#endif