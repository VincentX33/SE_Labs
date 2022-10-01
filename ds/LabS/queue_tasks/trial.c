#include <stdio.h>
#include <stdlib.h>
#include "queueI.h"

int main(){
  int i, front = -1, rear = -1,v;
  int queue[MAX+1];
  for (i = 0; i < 3; i++){
    printf("Enter value:");
    scanf("%d",&v);
    enqueue(queue, &front, &rear, v);
  }
  // printf("On top : %d\n", dequeue(queue, &front, &rear));
  // printf("On top : %d\n", dequeue(queue, &front, &rear));
  // printf("On top : %d\n", dequeue(queue, &front, &rear));
  //printf("Queue Display\n");

  display(queue, front, rear);
  return 0;
  return 0;
}
