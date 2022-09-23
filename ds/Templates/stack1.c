#include <stdio.h>
#include <stdlib.h>

//for this version use local stack
//global variables
#define MAX 50
//function prototypes
void push(int [],int *, int);
int pop(int [],int *);
void peek(int [], int *);
int isEmpty(int *);
int isFull(int *);
void display(int [], int *);

//main function
int main(){
  //to take choices and control
  int c,n;
  int item;
  int stack[MAX];
  int top = -1;
  //code  

  return 0;

}
void push(int stack[], int * t,int item){
  //check for overflow
  if (isFull(t)){
    printf("Error: Stack overflow\n");
    return;
  }
  //increment top, add item at top
  *t = *t +1;
  stack[*t] = item;
  }
int pop(int a[],int * t){
  //check for stack underflow
  if (isEmpty(t)){
    printf("Error:Stack underflow\n");
    return;
  }
  int i;
  i = a[*t];
  *t = *t-1;
  return i;
}
void peek(int a[], int * t){
  if (isEmpty(t)){
    printf("Error:Stack underflow\n");
    return;
  }
  printf("Item on top of stack is %d\n", a[*t]);
}
int isEmpty(int * top){
  if (*top == -1)
    return 1;
  return 0;
}
int isFull(int * top){
  if (*top == MAX-1)
    return 1;
  return 0;
}

void display(int a[], int * t){
  //as long as it is not empty display
  if (isEmpty(t)){
    printf("Empty stack\n");
    return;
  }
  int i;
  //printf("Stack contents:\n ");
  for (i = *t; i >= 0; i--){
    if (i==0)
      printf("Last:");
    printf("%d  ",a[i]);
  }
  printf("\n");
}
