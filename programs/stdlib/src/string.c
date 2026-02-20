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

#include "string.h"

char tolower(char s1)
{
    if (s1 >= 65 && s1 <= 90)
    {
        s1 += 32;
    }

    return s1;
}

int strlen(const char* ptr)
{
    int i = 0;
    while(*ptr != 0)
    {
        i++;
        ptr += 1;
    }

    return i;
}

int strnlen(const char* ptr, int max)
{
    int i = 0;
    for (i = 0; i < max; i++)
    {
        if (ptr[i] == 0)
            break;
    }

    return i;
}

int strnlen_terminator(const char* str, int max, char terminator)
{
    int i = 0;
    for(i = 0; i < max; i++)
    {
        if (str[i] == '\0' || str[i] == terminator)
            break;
    }

    return i;
}

int istrncmp(const char* s1, const char* s2, int n)
{
    unsigned char u1, u2;
    while(n-- > 0)
    {
        u1 = (unsigned char)*s1++;
        u2 = (unsigned char)*s2++;
        if (u1 != u2 && tolower(u1) != tolower(u2))
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}
int strncmp(const char* str1, const char* str2, int n)
{
    unsigned char u1, u2;

    while(n-- > 0)
    {
        u1 = (unsigned char)*str1++;
        u2 = (unsigned char)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}

char* strcpy(char* dest, const char* src)
{
    char* res = dest;
    while(*src != 0)
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }

    *dest = 0x00;

    return res;
}

char* strncpy(char* dest, const char* src, int count)
{
    int i = 0;
    for (i = 0; i < count-1; i++)
    {
        if (src[i] == 0x00)
            break;

        dest[i] = src[i];
    }

    dest[i] = 0x00;
    return dest;
}

bool isdigit(char c)
{
    return c >= 48 && c <= 57;
}
int tonumericdigit(char c)
{
    return c - 48;
}

char* sp = 0;
char* strtok(char* str, const char* delimiters)
{
    int i = 0;
    int len = strlen(delimiters);
    if (!str && !sp)
        return 0;
    
    if (str && !sp)
    {
        sp = str;
    }

    char* p_start = sp;
    while(1)
    {
        for (i = 0; i < len; i++)
        {
            if(*p_start == delimiters[i])
            {
                p_start++;
                break;
            }
        }

        if (i == len)
        {
            sp = p_start;
            break;
        }
    }

    if (*sp == '\0')
    {
        sp = 0;
        return sp;
    }

    // Find end of substring
    while(*sp != '\0')
    {
        for (i = 0; i < len; i++)
        {
            if (*sp == delimiters[i])
            {
                *sp = '\0';
                break;
            }
        }

        sp++;
        if (i < len)
            break;
    }

    return p_start;
}