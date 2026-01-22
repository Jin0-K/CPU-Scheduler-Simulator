#include <iostream>
#include <algorithm>
#include "scheduler.h"
#include "../process/process.h"

Scheduler::Scheduler(int time_quantum) {
    this->time_quantum = time_quantum;
    this->process_index = 0;
    this->current_time = 0;
}

int Scheduler::getTimeQuantum() const {
    return time_quantum;
}

int Scheduler::getCurrentTime() const {
    return current_time;
}

// Sort processes vector in arrival time
void Scheduler::sortProcesses() {
    std::sort(processes.begin(), processes.end(),
              [](const Process& a, const Process& b) {
                  return a.getArrivalTime() < b.getArrivalTime();
              });
}

// Add processes that are ready to ready queue 
void Scheduler::enqueueProcess() {
    while (process_index < processes.size()) {
        if (processes[process_index].getArrivalTime() <= getCurrentTime()) {
            ready_queue.push(&processes[process_index++]);
        } else {
            break;
        }
    }
}

// Add processes to vector list
void Scheduler::addProcess(const Process& process) {
    processes.push_back(process);
}

void Scheduler::run() {
    sortProcesses();
    enqueueProcess();
    while (process_index < processes.size() || !ready_queue.empty())
    {
        enqueueProcess();

        if (ready_queue.empty()) {
            std::cout   << "[ " << current_time
                        << " - " << current_time + 1
                        << " ] CPU IDLE\n";
            current_time++;
            continue;
        }

        Process *processInExecute = ready_queue.front();
        ready_queue.pop();
        int time_executed = cpu.run(*processInExecute, getTimeQuantum());

        // Print the Schedule
        std::cout << "[ " << current_time << " - ";

        current_time += time_executed;
        enqueueProcess(); // For the processes arrived while another is being executed
        
        std::cout << current_time << " ] Process " << processInExecute->getPid() << " RUNNING" << std::endl;

        if (processInExecute->getState() == ProcessState::READY) {
            ready_queue.push(processInExecute);
        }
        
    }
    
}