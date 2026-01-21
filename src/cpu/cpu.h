#include "../process/process.h"

class CPU 
{
public:
    CPU();
    int run(Process& process, int time_quantum);
};