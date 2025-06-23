#include "scheduler.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Scheduler::Scheduler(){
  logFile.open("urtos_log.txt",ios::out|ios::trunc);
}

Scheduler::~Scheduler(){
  if(logFile.is_open()) logFile.close();
}

void Scheduler::registerTask(TaskControlBlock tcb){
  taskList.push_back(tcb);
}

void Scheduler::runTask(TaskControlBlock tcb, mutex&printLock){
  {
    lock_guard<mutex> lock(printLock);
    cout<<"Starting "<<tcb.name<<"..."<<endl;
  }
  
  tcb.taskFunction();
  this_thread::sleep_for(chrono::milliseconds(500));
  
  {
    lock_guard<mutex> lock(printLock);
    cout<<"Completed"<<endl;
  }
}

void Scheduler::startRoundRobin(){
  vector<thread> threads;
  
  for(const auto& task:taskList){
    threads.emplace_back(runTask, task, ref(printLock));
  }
  
  for(auto& t:threads){
    t.join();
  }
}

void Scheduler::startPriorityScheduling(){
  sort(taskList.begin(),taskList.end(),[](const TaskControlBlock& a, const TaskControlBlock& b){
    return a.priority<b.priority;
  });
  
  for(const auto& task:taskList){
    {
      lock_guard<mutex> lock(printLock);
      cout<<"Running "<<task.name<<" with priority "<<task.priority<<"..."<<endl;
    }
    
    task.taskFunction();
    this_thread::sleep_for(chrono::milliseconds(500));
    
    {
      lock_guard<mutex> lock(printLock);
      cout<<task.name<<" completed "<<endl;
    }
    
  }
}

void Scheduler::startWithBlocking(){
  for(auto& task: taskList){
    if(!task.isReady){
      lock_guard<mutex> lock(printLock);
      cout<<task.name<<" is blocked "<<endl;
      this_thread::sleep_for(chrono::milliseconds(1000));
      task.isReady=true;
      cout<<task.name<<" is now ready "<<endl;
    }
  }

  for (auto& task : taskList) {
        if (task.isReady && !task.isCompleted) {
            {
                lock_guard<mutex> lock(printLock);
                cout << "Running " << task.name << "..." << endl;
            }

            task.taskFunction();
            this_thread::sleep_for(chrono::milliseconds(500));
            task.isCompleted = true;

            {
                lock_guard<mutex> lock(printLock);
                cout << task.name << " completed " << endl;
            }
        }
    }
}

void Scheduler::startPreemptiveScheduling(){
  const int TIME_SLICE=300;
  
  while(true){
    bool alldone=true;
    
    for(auto& task:taskList){
      if(task.isCompleted || !task.isReady) continue;
      
      alldone=false;
      
      {
        lock_guard<mutex> lock(printLock);
        cout<<task.name<<" is running for "<<TIME_SLICE<<" ms... "<<endl;
        logFile<<task.name<<" is running for "<<TIME_SLICE<<" ms... "<<endl;
      }
      this_thread::sleep_for(chrono::milliseconds(TIME_SLICE));
      task.timeExecuted+=TIME_SLICE;
      
      if(task.timeExecuted>=task.totalRuntime){
        task.isCompleted=true;
        {
          lock_guard<mutex> lock(printLock);
          cout<<task.name<<" is completed after "<<task.timeExecuted<<" ms "<<endl;
          logFile<<task.name<<" is completed after "<<task.timeExecuted<<" ms "<<endl;
        }
      }else{
        {
          lock_guard<mutex> lock(printLock);
          cout<<task.name<<" is paused at "<<task.timeExecuted<<" ms "<<endl;
          logFile<<task.name<<" is paused at "<<task.timeExecuted<<" ms "<<endl;
        }
      }
    }
  if(alldone==true) break;
  }
}
