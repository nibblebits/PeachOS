#include "heap.h"
#include "task/task.h"
#include "task/process.h"
#include <stddef.h>
void* isr80h_command4_malloc(struct interrupt_frame* frame)
{
    size_t size = (int)task_get_stack_item(task_current(), 0);
    return process_malloc(task_current()->process, size);
}
