#include <fstream>
#include <iostream>
#include <string>
#include "process/process.h"
#include "cpu/cpu.h"
#include "scheduler/scheduler.h"

int main() {
    Scheduler scheduler(2); // time quantum = 2

    std::ifstream file("processes.txt");
    if (!file) {
        std::cerr << "Failed to open input file\n";
        return 1;
    }

    int pid, arrival, burst;
    while (file >> pid >> arrival >> burst) {
        scheduler.addProcess(Process(pid, arrival, burst));
    }

    scheduler.run();
}
