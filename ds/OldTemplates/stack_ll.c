#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;  
};
struct node * addatbeg(struct node *,struct node *);
void displayList(struct node *);
void searchList(struct node *,int );
struct node * push(struct node * start, struct node * temp);
struct node * pop(struct node * start);
void displayNode(struct node *);
/* generic functions for all type of nodes*/


int main(){
  struct node * top = NULL,*temp;
  int c;
  printf("---------Stack handler program-----------\n");
  do{
    printf("Enter\n 1 to push to stack\n ");
    printf("2 to pop from stack\n ");
    printf("3 to peek at top of stack");
    printf("4 display stack contents\n ");
    printf("5 to exit the program\n ");
    scanf("%d",&c);
    switch(c){ 
      case 1: 
        break;
      case 2: 
        break;
      case 3: 
        break;
      case 4: 
        break;
      case 5:
        break;
    }
  }while(c!=5); 
  return 0;
}

struct node * addatbeg(struct node * start, struct node * p){
  p->next = start;
  start = p;
  return start;
}
struct node * push(struct node * start, struct node * a){
  a->next = start;
  start = a;
  return start;
}
struct node * pop (struct node * start){
  //returns new start
  if (start==NULL)
    return NULL;
  struct node *t = start;
  start = start->next;
  printf("Popped value:%d\n", t->data);  
  free(t);
  return start;
}
void displayList(struct node * start){
  if (start == NULL){
      printf("Empty list\n");
  }else{
  struct node * p;
  for (p = start;p!=NULL;p = p->next){
    displayNode(p);
  }
  printf("\n---------------------\n");
  }
}
void displayNode(struct node * a){
  printf("%d ", a->data);
}
