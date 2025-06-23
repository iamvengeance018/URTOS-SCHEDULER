#include <iostream>
#include "scheduler.h"
#include "task_config.h"

using namespace std;

int main(){
    Scheduler scheduler;
    
    TaskControlBlock tcb1={
      1,      //taskID
      2,      //Priority
      false,  //isCompleted
      true,   //isReady
      task1,  //taskFunction
      "Task1",//TaskName
      900,    //totalRuntime
      0       //timeExecuted
    };
    
    TaskControlBlock tcb2={
      2,      //taskID
      1,      //Priority
      false,  //isCompleted
      true,  //isReady
      task2,  //taskFunction
      "Task2",//TaskName
      600,    //totalRuntime
      0       //timeExecuted
    };
    
    scheduler.registerTask(tcb1);
    scheduler.registerTask(tcb2);
    
    scheduler.startPreemptiveScheduling();
  
  return 0;
  
}
