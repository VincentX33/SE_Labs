#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100
int stack[MAX];
int top = -1;
//function prototypes
void push(int item);
int pop();
void peek();
int isEmpty();
int isFull();
void display();

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
  //printf("Stack contents:\n ");
  for (i = top; i >= 0; i--){
    printf("%c  ",stack[i]);
  }
  printf("\n");
}

long int pfEval(char exp[]){
  long int a,b,temp,result;
  int i;
  //use the same stack for this
  for (i = 0;i<strlen(exp);i++){
    if (exp[i]<='9' && exp[i]>='0')
      push(exp[i]-'0');
    else {
      a = pop();
      b = pop();
      switch(exp[i]){
        case '+':
          temp = b+a;
          break;
        case '-':
          temp = b-a;
          break;
        case '*':
          temp = b*a;
          break;
        case '/':
          temp = b/a;
          break;
        case '%':
          temp = b%a;
          break;
        case '^':
          temp = pow(b,a);
          break;
      }
      push(temp);
    }
  }
  result = pop();
  return result;
}
int main(){
  //code for evaluating postfix express 
  char exp[100];
  printf("Enter expression:");
  scanf("%s",exp);
  printf("Result is %ld\n",pfEval(exp));
}