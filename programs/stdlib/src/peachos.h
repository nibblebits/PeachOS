#ifndef PEACHOS_H
#define PEACHOS_H
#include <stddef.h>

void print(const char* filename);
int getkey();

void* peachos_malloc(size_t size);
void peachos_free(void* ptr);
void peachos_putchar(char c);

#endif