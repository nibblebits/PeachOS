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

#ifndef STRING_H
#define STRING_H
#include <stdbool.h>
int strlen(const char* ptr);
int strnlen(const char* ptr, int max);
bool isdigit(char c);
int tonumericdigit(char c);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, int count);
int strncmp(const char* str1, const char* str2, int n);
int istrncmp(const char* s1, const char* s2, int n);
int strnlen_terminator(const char* str, int max, char terminator);
char tolower(char s1);
#endif