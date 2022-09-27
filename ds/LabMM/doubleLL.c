#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * prev;
  struct node * next;
};
//working linked list*/
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
struct node * addafter(struct node *,struct node *);
struct node * addatbeg(struct node *,struct node *);
struct node * addatend(struct node *,struct node *);
struct node * create(struct node *);
void displayLL(struct node *);
struct node * deleteTerm(struct node *, int);
int main(){
  int c,status = 0,e;
  struct node * ll;
  ll = create(ll);
  ll = deleteTerm(ll, 5);
  ll = deleteTerm(ll, 15);
  ll = deleteTerm(ll, 25);
  displayLL(ll);
  return 0;
}
struct node * create(struct node * start){
  //start == NULL
  start = NULL;
  struct node * temp;
  int n;
  printf("Enter number of items:");
  scanf("%d",&n);
  while (n--){
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &(temp->data));
    temp->prev = NULL;
    temp->next = NULL;
    if (start == NULL){
      start = addToEmpty(start,temp);
    }else{
      start = addatend(start, temp);
    }
  }
  return start;
}
struct node * addToEmpty(struct node * start, struct node * p){
  p->prev = NULL;
  p->next = start;
  start = p;
  return start;
}
struct node * addatend(struct node * start, struct node * p){
    struct node * temp = start;
    if (temp==NULL){
      start = p;
      start->prev = NULL;
      start->next = NULL;
      return start;
    }
    while (temp->next != NULL )
      temp = temp->next;
    temp->next = p;
    p->prev = temp;
    p->next = NULL;
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
    }
    printf("  |\n");
}

struct node * deleteTerm(struct node * start, int val){
  struct node * p = start;
  if (start == NULL)
    return start;
  else if (start->data == val){
    p = start;
    start->next->prev = NULL;
    start = start->next;
    free(p);
    return start;
  }
  struct node * temp;
  while (p->next->next!=NULL){
    if (p->next->data == val){
      temp = p->next;
      temp->next->prev = p;
      p->next = temp->next;
      free(temp);
      return start;
    }
    p = p->next;
  }
  if(p->next->next == NULL){
    if (p->next->data == val){
      temp = p->next;
      p->next = NULL;
      free(temp);
      return start;
    }
  }
  printf("Item %d not found in list\n",val);
  return start;
}
