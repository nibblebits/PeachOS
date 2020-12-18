#include "peachos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main(int argc, char** argv)
{
    char* ptr = malloc(20);
    strcpy(ptr, "hello world");
    print(ptr);
    free(ptr);

    ptr[0] = 'B';
    print("abc\n");

    while(1) 
    {
    }
    return 0;
}