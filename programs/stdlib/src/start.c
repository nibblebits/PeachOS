/*
 * Copyright (C) Daniel McCarthy <daniel@dragonzap.com>
 * This file is licensed under the GPLv2 license.
 * To learn how to build this get the kernel development course at https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
 */

#include "peachos.h"

extern int main(int argc, char** argv);

void c_start()
{
    struct process_arguments arguments;
    peachos_process_get_arguments(&arguments);

    int res = main(arguments.argc, arguments.argv);
    if (res == 0)
    {
        
    }
}