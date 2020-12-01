#ifndef ISR80H_IO_H
#define ISR80H_IO_H

struct interrupt_frame;
void* isr80h_command1_print(struct interrupt_frame* frame);
void* isr80h_command2_getkey(struct interrupt_frame* frame);
void* isr80h_command3_putchar(struct interrupt_frame* frame);
#endif