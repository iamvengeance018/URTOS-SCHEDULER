#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <functional>
#include <vector>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

struct TaskControlBlock{
  int taskID;
  int priority;
  bool isCompleted;
  bool isReady;
  function<void()> taskFunction;
  string name;
  int totalRuntime;
  int timeExecuted;
};

class Scheduler{
  public:
    Scheduler();
    ~Scheduler();
    void registerTask(TaskControlBlock tcb);
    void startRoundRobin();
    void startPriorityScheduling();
    void startWithBlocking();
    void startPreemptiveScheduling();
  private:
    vector<TaskControlBlock> taskList;
    ofstream logFile;
    mutex printLock;
    static void runTask(TaskControlBlock tcb, mutex&printLock);
};

#endif
