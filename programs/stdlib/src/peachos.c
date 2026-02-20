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

#include "peachos.h"
#include "string.h"

struct command_argument* peachos_parse_command(const char* command, int max)
{
    struct command_argument* root_command = 0;
    char scommand[1025];
    if (max >= (int) sizeof(scommand))
    {
        return 0;
    }


    strncpy(scommand, command, sizeof(scommand));
    char* token = strtok(scommand, " ");
    if (!token)
    {
        goto out;
    }

    root_command = peachos_malloc(sizeof(struct command_argument));
    if (!root_command)
    {
        goto out;
    }

    strncpy(root_command->argument, token, sizeof(root_command->argument));
    root_command->next = 0;


    struct command_argument* current = root_command;
    token = strtok(NULL, " ");
    while(token != 0)
    {
        struct command_argument* new_command = peachos_malloc(sizeof(struct command_argument));
        if (!new_command)
        {
            break;
        }

        strncpy(new_command->argument, token, sizeof(new_command->argument));
        new_command->next = 0x00;
        current->next = new_command;
        current = new_command;
        token = strtok(NULL, " ");
    }
out:
    return root_command;
}
int peachos_getkeyblock()
{
    int val = 0;
    do
    {
        val = peachos_getkey();
    }
    while(val == 0);
    return val;
}

void peachos_terminal_readline(char* out, int max, bool output_while_typing)
{
    int i = 0;
    for (i = 0; i < max -1; i++)
    {
        char key = peachos_getkeyblock();

        // Carriage return means we have read the line
        if (key == 13)
        {
            break;
        }

        if (output_while_typing)
        {
            peachos_putchar(key);
        }

        // Backspace
        if (key == 0x08 && i >= 1)
        {
            out[i-1] = 0x00;
            // -2 because we will +1 when we go to the continue
            i -= 2;
            continue;
        }

        out[i] = key;
    }

    // Add the null terminator
    out[i] = 0x00;
}

int peachos_system_run(const char* command)
{
    char buf[1024];
    strncpy(buf, command, sizeof(buf));
    struct command_argument* root_command_argument = peachos_parse_command(buf, sizeof(buf));
    if (!root_command_argument)
    {
        return -1;
    }

    return peachos_system(root_command_argument);
}