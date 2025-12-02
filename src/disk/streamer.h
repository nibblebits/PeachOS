/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#ifndef DISKSTREAMER_H
#define DISKSTREAMER_H

#include "disk.h"

struct disk_stream
{
    int pos;
    struct disk* disk;
};

struct disk_stream* diskstreamer_new(int disk_id);
int diskstreamer_seek(struct disk_stream* stream, int pos);
int diskstreamer_read(struct disk_stream* stream, void* out, int total);
void diskstreamer_close(struct disk_stream* stream);

#endif