#include <stdio.h>
#include <stdlib.h>

struct node{
  char value;
  struct node * next;
};

//implement a ll stack

struct node * push(struct node * top,struct node * temp){
  if (top == NULL){
    return temp;
  }
  temp->next = top;
  top = temp;
  return top;
}
//take value
struct node * addValue(struct node * top, int val){
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->value = val;
  temp->next = NULL;
  top = push(top,temp);
  return top;
}
struct node * pop(struct node * top, int * val){
  if (top==NULL)
    return top;
  struct node * temp = top;
  top = top->next;
  *val = temp->value;
  free(temp);
  return top;
}
