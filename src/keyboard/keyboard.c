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

#include "keyboard.h"
#include "status.h"
#include "kernel.h"
#include "task/process.h"
#include "task/task.h"
#include "classic.h"

static struct keyboard* keyboard_list_head = 0;
static struct keyboard* keyboard_list_last = 0;

void keyboard_init()
{
    keyboard_insert(classic_init());
}

int keyboard_insert(struct keyboard* keyboard)
{
    int res = 0;
    if (keyboard->init == 0)
    {
        res = -EINVARG;
        goto out;
    }

    if (keyboard_list_last)
    {
        keyboard_list_last->next = keyboard;
        keyboard_list_last = keyboard;
    
    }
    else
    {
        keyboard_list_head = keyboard;
        keyboard_list_last = keyboard;
    }
    
    res = keyboard->init();
out:
    return res;
}

static int keyboard_get_tail_index(struct process* process)
{
    return process->keyboard.tail % sizeof(process->keyboard.buffer);
}

void keyboard_backspace(struct process* process)
{
    process->keyboard.tail -=1 ;
    int real_index = keyboard_get_tail_index(process);
    process->keyboard.buffer[real_index] = 0x00;
}

void keyboard_set_capslock(struct keyboard* keyboard, KEYBOARD_CAPS_LOCK_STATE state)
{
    keyboard->capslock_state = state;
}

KEYBOARD_CAPS_LOCK_STATE keyboard_get_capslock(struct keyboard* keyboard)
{
    return keyboard->capslock_state;
}

void keyboard_push(char c)
{
    struct process* process = process_current();
    if (!process)
    {
        return;
    }

    if(c == 0)
    {
        return;
    }

    int real_index = keyboard_get_tail_index(process);
    process->keyboard.buffer[real_index] = c;
    process->keyboard.tail++;
}

char keyboard_pop()
{
    if (!task_current())
    {
        return 0;
    }

    struct process* process = task_current()->process;
    int real_index = process->keyboard.head % sizeof(process->keyboard.buffer);
    char c = process->keyboard.buffer[real_index];
    if (c == 0x00)
    {
        // Nothing to pop return zero.
        return 0;
    }

    process->keyboard.buffer[real_index] = 0;
    process->keyboard.head++;
    return c;
}