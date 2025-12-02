/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "peachos.h"
int main(int argc, char** argv)
{
    print("PeachOS v1.0.0\n");
    while(1) 
    {
        print("> ");
        char buf[1024];
        peachos_terminal_readline(buf, sizeof(buf), true);
        print("\n");
        peachos_system_run(buf);
        
        print("\n");
    }
    return 0;
}