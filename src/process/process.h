#ifndef PROCESS_H
#define PROCESS_H

enum class ProcessState {
    READY, 
    RUNNING, 
    DONE
};

class Process
{
private:
    int pid;
    ProcessState state;
    int time_arrived;
    int time_remaining;
public:
    Process(int pid, int time_arrived, int time_remaining);
    int getPid() const;
    ProcessState getState() const;
    int getArrivalTime() const;
    int getRemainingTime() const;

    int execute(int runtime);
};

#endif