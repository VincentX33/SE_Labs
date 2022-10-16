#include <stdio.h>
#include <stdlib.h>

//implement dynamic data structures
struct node {
  int value;
  struct node * next;
};
/*
Stack using double pointer
push
pop
display

*/
void push(struct node ** top,int val){
  struct node * n = (struct node *)malloc(sizeof(struct node));
  if (n){
    n->value = val;
    n->next = *top;
    *top = n;
  }
}
struct node * pop (struct node **top){
  struct node * t = *top;
  *top = (*top)->next;
  t->next = NULL;
  return t;
}
void display(struct node ** start){
  struct node * p;
  printf("[  ");
  for (p = *start;p!=NULL;p = p->next)
    printf("%d  ",p->value);
  printf(" ]\n");
}
int main(){
  struct node * stack = NULL;
  push(&stack,12);
  push(&stack,14);
  push(&stack,15);
  push(&stack,17);
  printf("Popped value:%d\n",(pop(&stack))->value);
  display(&stack);
  return 0;
}