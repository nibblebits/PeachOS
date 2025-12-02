/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#ifndef ISR80H_MISC_H
#define ISR80H_MISC_H

struct interrupt_frame;
void* isr80h_command0_sum(struct interrupt_frame* frame);
#endif