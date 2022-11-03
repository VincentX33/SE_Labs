#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node * next;  
};
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

void infixToPostfix(char * infixExp){
  int i,p = 0;
  char next, symbol, postfix[100];
  for (i = 0;i < strlen(infixExp);i++){
    symbol = infixExp[i];
    if (!isWhiteSpace(symbol)){
      switch(symbol){
        case '(': 
          push('(');
          break;
        case ')':
          while ((next=pop(stack))!='('){
            postfix[p++] = next;
          }
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
          int i,j;
          i = instackPriority(stack[top]);
          j = incomingPriority(symbol);
          while ((top!=-1)&&(instackPriority(stack[top]) >= incomingPriority(symbol)))
            postfix[p++] = pop();
          push(symbol);
          break;
        default:
          postfix[p++] = symbol;
          break;
      }
    }
  }
  while (top!= -1){
    postfix[p++] = pop(); 
  }
  postfix[p] = '\0';
  printf("Final expression is %s\n",postfix);
}
int charToInt(char c){
  return (c-'0');
}
void pfEval(char exp[]){
  int i = 0,j,a,b,f;
  char c;
  //use the same stack for this
  for (i = 0; i<strlen(exp);i++){
    push();
  }
    c = exp[i];
    switch(c){
      case '+':
        a = pop();
        b = pop();
        f = a + b;
        push(f);
        break;
      case '-':
        a = pop();
        b = pop();
        f = b-a;
        push(f);
      case '*':
        a = pop();
        b = pop();
        f = b*a;
        push(f);
      case '/':
        a = pop();
        b = pop();
        f = b/a;
        push(f);
      case '%':
        a = pop();
        b = pop();
        f = b%a;
        push(f);
      case '^':
        a = pop();
        b = pop();
        f = pow(b,a);
        push(f);
      default:
        j = charToInt(c);
        push(j);
    }
  }
}
int main(){
  //code for evaluating postfix express 
  char exp[100];
  printf("Enter expression:");
  scanf("%s",exp);
  pfEval(exp);
}