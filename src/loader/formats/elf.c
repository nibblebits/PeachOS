/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#include "elf.h"

void* elf_get_entry_ptr(struct elf_header* elf_header)
{
    return (void*) elf_header->e_entry;
}

uint32_t elf_get_entry(struct elf_header* elf_header)
{
    return elf_header->e_entry;
}