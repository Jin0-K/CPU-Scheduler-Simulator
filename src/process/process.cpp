#include <algorithm>
#include "process.h"

Process::Process(int pid, int time_arrived, int time_remaining) {
    this->pid = pid;
    this->state = ProcessState::READY;
    this->time_arrived = time_arrived;
    this->time_remaining = time_remaining;
}

int Process::getPid() const {
    return pid;
}
ProcessState Process::getState() const {
    return state;
}
int Process::getArrivalTime() const {
    return time_arrived;
}
int Process::getRemainingTime() const {
    return time_remaining;
}

int Process::execute(int runtime) {
    // Set process state RUNNING
    state = ProcessState::RUNNING;
    // Apply time executed
    time_remaining -= std::min(runtime, time_remaining);
    // Check whether the process is finished
    if (time_remaining == 0) {
        state = ProcessState::DONE;
    } else {
        state = ProcessState::READY;
    }

    return time_remaining;
}