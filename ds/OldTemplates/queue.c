#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue(char [], int *f,int *r,int val); //enter element in queue
int dequeue(char [], int *f,int *r); //remove element from queue
void display(char [], int *f,int *r,int val); //display queue elements
int isFull(int, int);
int isEmpty(int, int);
int main(){
  //implement a queue
  int front = -1, rear = -1;
  return 0;
}
int isFull(int f, int r){
  if ((f == 0 && r == MAX-1)||(f==r+1))
    return 1;
  return 0;
}
int isEmpty(int f, int r){
  if (f==-1 && r==-1)
    return 1;
  return 0;
}
void enqueue(char que[], int * front, int * rear, char val ){
  //check if full
  if (isFull(*front, *rear)){
    //queue is full
    printf("Queue overflow\n");
    return;
  }
  //if its empty
  if (*front == -1 && *rear == -1){
    *front = 0;
    *rear = 0;
    que[0] = val;
  }
  //as long as queue is less than MAX-1
  if (*rear == MAX-1)
    *rear = 0;
  else
    (*rear)++;
  que[*rear] = val;
}
char dequeue(int que[], int * front, int * rear){
  //check if empty
  if (isEmpty(*front, *rear)){
    printf("Empty queue\n");
    return '\0';
  }
  char c;
  if (*front == *rear){
    c = que[*front];
    *front = -1;
    *rear = -1;
    return c;
  }
  c = que[*front];
  *front = *front + 1;
  return c;
}
void display(char que[], int f,int r){
  if (isEmpty(*front, *rear)){
    printf("Empty queue\n");
    return;
  }
  int i = f, j = r;
  (if i > j){
    while (i < MAX)
      printf("%d ", que[i++]);
    i = 0;
  }
  while (i <= j){
    printf("%d ", que[i++]);
  }
}
