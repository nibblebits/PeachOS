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

#include "disk.h"
#include "io/io.h"
#include "config.h"
#include "status.h"
#include "memory/memory.h"

struct disk disk;

int disk_read_sector(int lba, int total, void* buf)
{
    outb(0x1F6, (lba >> 24) | 0xE0);
    outb(0x1F2, total);
    outb(0x1F3, (unsigned char)(lba & 0xff));
    outb(0x1F4, (unsigned char)(lba >> 8));
    outb(0x1F5, (unsigned char)(lba >> 16));
    outb(0x1F7, 0x20);

    unsigned short* ptr = (unsigned short*) buf;
    for (int b = 0; b < total; b++)
    {
        // Wait for the buffer to be ready
        char c = insb(0x1F7);
        while(!(c & 0x08))
        {
            c = insb(0x1F7);
        }

        // Copy from hard disk to memory
        for (int i = 0; i < 256; i++)
        {
            *ptr = insw(0x1F0);
            ptr++;
        }

    }
    return 0;
}

void disk_search_and_init()
{
    memset(&disk, 0, sizeof(disk));
    disk.type = PEACHOS_DISK_TYPE_REAL;
    disk.sector_size = PEACHOS_SECTOR_SIZE;
    disk.id = 0;
    disk.filesystem = fs_resolve(&disk);
}

struct disk* disk_get(int index)
{
    if (index != 0)
        return 0;
    
    return &disk;
}

int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf)
{
    if (idisk != &disk)
    {
        return -EIO;
    }

    return disk_read_sector(lba, total, buf);
}