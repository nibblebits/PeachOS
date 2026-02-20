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

#ifndef FILE_H
#define FILE_H

#include "pparser.h"
#include <stdint.h>

typedef unsigned int FILE_SEEK_MODE;
enum
{
    SEEK_SET,
    SEEK_CUR,
    SEEK_END
};


typedef unsigned int FILE_MODE;
enum
{ 
    FILE_MODE_READ,
    FILE_MODE_WRITE,
    FILE_MODE_APPEND,
    FILE_MODE_INVALID
};

enum
{
    FILE_STAT_READ_ONLY = 0b00000001
};

typedef unsigned int FILE_STAT_FLAGS;

struct disk;
typedef void*(*FS_OPEN_FUNCTION)(struct disk* disk, struct path_part* path, FILE_MODE mode);
typedef int (*FS_READ_FUNCTION)(struct disk* disk, void* private, uint32_t size, uint32_t nmemb, char* out);
typedef int (*FS_RESOLVE_FUNCTION)(struct disk* disk);

typedef int (*FS_CLOSE_FUNCTION)(void* private);

typedef int (*FS_SEEK_FUNCTION)(void* private, uint32_t offset, FILE_SEEK_MODE seek_mode);


struct file_stat
{
    FILE_STAT_FLAGS flags;
    uint32_t filesize;
};

typedef int (*FS_STAT_FUNCTION)(struct disk* disk, void* private, struct file_stat* stat);

struct filesystem
{
    // Filesystem should return zero from resolve if the provided disk is using its filesystem
    FS_RESOLVE_FUNCTION resolve;
    FS_OPEN_FUNCTION open;
    FS_READ_FUNCTION read;
    FS_SEEK_FUNCTION seek;
    FS_STAT_FUNCTION stat;
    FS_CLOSE_FUNCTION close;
    char name[20];
};

struct file_descriptor
{
    // The descriptor index
    int index;
    struct filesystem* filesystem;

    // Private data for internal file descriptor
    void* private;

    // The disk that the file descriptor should be used on
    struct disk* disk;
};



void fs_init();
int fopen(const char* filename, const char* mode_str);
int fseek(int fd, int offset, FILE_SEEK_MODE whence);
int fread(void* ptr, uint32_t size, uint32_t nmemb, int fd);
int fstat(int fd, struct file_stat* stat);
int fclose(int fd);

void fs_insert_filesystem(struct filesystem* filesystem);
struct filesystem* fs_resolve(struct disk* disk);
#endif