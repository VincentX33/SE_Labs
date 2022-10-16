#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * next;
};

/*
addatbeg
addatend
addafter
create
add
display
multiply
polEdit
*/
struct node * addatbeg(struct node *,struct node *);
struct node * addatend(struct node *,struct node *);
void displayLL(struct node *);

int main(){  
  return 0;
}
struct node * addatbeg(struct node * start, struct node * p){
  p->next = start;
  start = p;
  return start;
}
struct node * addatend(struct node * start, struct node * p){
    struct node * temp = start;
    if (temp==NULL){
      start = p;
      return start;
    }
    while (temp->next != NULL )
      temp = temp->next;
    temp->next = p;
    return start;
}
void displayLL(struct node * a){
    if (a==NULL){
        printf("Empty list\n");
        return;
    }
    //int i = 0;
    printf("| ");
    while (a!= NULL){
        printf("%d ",a->data);
        a = a->next;
        //i++;
    }
    printf(" + 0 = 0 |\n");
}

