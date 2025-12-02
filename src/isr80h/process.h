/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#ifndef ISR80H_PROCESS_H
#define ISR80H_PROCESS_H

struct interrupt_frame;
void* isr80h_command6_process_load_start(struct interrupt_frame* frame);
void* isr80h_command7_invoke_system_command(struct interrupt_frame* frame);
void* isr80h_command8_get_program_arguments(struct interrupt_frame* frame);
void* isr80h_command9_exit(struct interrupt_frame* frame);

#endif