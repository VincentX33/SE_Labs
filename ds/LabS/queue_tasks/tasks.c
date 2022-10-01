#include <stdio.h>
#include <stdlib.h>
#include "queue_tasks.h"

#define MAXTITLE 50
#define MaxTasks 50
struct Task {
  int taskID;
  char title[MAXTITLE];
  float duration;
  int status; //0 if unscheduled, 1 if scheduled, 2 if completed
};
int main(){
  struct Task daily_tasks[MaxTasks];
  //handle the tasks
  //take input from file
  int q_of_ns[10];
  int f = -1, r = -1,v,i;
  for (i = 0; i < 5; i++){
    printf("Enter value:");
    scanf("%d",&v);
    enqueue(q_of_ns, &f, &r, v);
  }
  display(q_of_ns, f, r);
  return 0;
}
