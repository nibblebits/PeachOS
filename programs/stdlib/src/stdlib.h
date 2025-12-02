/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#ifndef PEACHOS_STDLIB_H
#define PEACHOS_STDLIB_H
#include <stddef.h>

void* malloc(size_t size);
void free(void* ptr);
char* itoa(int i);
#endif