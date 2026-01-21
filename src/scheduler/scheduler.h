#include <queue>
#include <vector>
#include "../cpu/cpu.h"
#include "../process/process.h"

class Scheduler
{
private:
    CPU cpu;
    int time_quantum;
    std::queue<Process*> ready_queue;
    std::vector<Process> processes;
    unsigned int process_index;
    int current_time;

    void sortProcesses();
    void enqueueProcess();
public:
    Scheduler(int time_quantum);
    int getTimeQuantum() const;
    int getCurrentTime() const;

    void addProcess(const Process& process);
    void run();
};