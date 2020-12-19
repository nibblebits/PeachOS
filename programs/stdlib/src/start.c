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