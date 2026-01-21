#include "cpu.h"

int CPU::run(Process& process, int time_quantum) {
    return process.execute(time_quantum);
}