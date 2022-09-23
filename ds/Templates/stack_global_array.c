#include <stdio.h>
#include <stdlib.h>
//global variables
#define MAX 100
int stack[MAX];
short int top = -1;
//function prototypes
void push();
int pop();
void peek();
int isEmpty();
int isFull();
void display();

//main function
int main(){
  //to take choices and control
  int c, item;
  while (1){
    printf("Enter\n ");
    printf("1 to push\n 2 to pop\n 3 to peek");
    printf("\n 4 to display stack contents\n 5 to exit\n :");
    scanf("%d",&c);
    switch(c){
      case 1: printf("Enter element to be pushed:");
              scanf("%d",&item);
              push(item);
              break;

      case 2: item = pop();
              printf("Popped item is : %d\n",item);
              break;
      case 3: peek();
              break;
      case 4: display();
              break;
      case 5: exit(1);
    }
  }
  return 0;
}
void push(int item){
  //check for overflow
  if (isFull()){
    printf("Error: Stack overflow\n");
    return;
  }
  //increment top, add item at top
  stack[++top] = item;
}
int pop(){
  //check for stack underflow
  if (isEmpty()){
    printf("Error:Stack underflow\n");
    return 0;
  }
  return stack[top--];
}
void peek(){
  if (isEmpty()){
    printf("Error:Stack underflow\n");
    return;
  }
  printf("Item on top of stack is %d\n", stack[top]);

}
int isEmpty(){
  if (top == -1)
    return 1;
  return 0;
}
int isFull(){
  if (top == MAX-1)
    return 1;
  return 0;
}

void display(){
  //as long as it is not empty display
  if (isEmpty()){
    printf("Empty stack\n");
    return;
  }
  int i;
  printf("Stack contents:\n ");
  for (i = top; i >= 0; i--){
    printf("%d  ",stack[i]);
  }
  printf("\n");
}
