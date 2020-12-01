#include "isr80h.h"
#include "idt/idt.h"
#include "misc.h"
#include "io.h"

void isr80h_register_commands()
{
    isr80h_register_command(SYSTEM_COMMAND0_SUM, isr80h_command0_sum);
    isr80h_register_command(SYSTEM_COMMAND1_PRINT, isr80h_command1_print);
    isr80h_register_command(SYSTEM_COMMAND2_GETKEY, isr80h_command2_getkey);
    isr80h_register_command(SYSTEM_COMMAND3_PUTCHAR, isr80h_command3_putchar);
}