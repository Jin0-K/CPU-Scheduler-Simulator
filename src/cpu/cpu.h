#ifndef CPU_H
#define CPU_H

#include "../process/process.h"

class CPU 
{
public:
    int run(Process& process, int time_quantum);
};

#endif