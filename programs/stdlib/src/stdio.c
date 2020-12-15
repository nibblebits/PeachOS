#include "stdio.h"
#include "peachos.h"

int putchar(int c)
{
    peachos_putchar((char)c);
    return 0;
}