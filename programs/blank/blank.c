/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#include "peachos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main(int argc, char** argv)
{
    while(1)
    {
        print(argv[0]);
        for (int i = 0; i < 1000000; i++)
        {
            
        }
    }
    return 0;
}