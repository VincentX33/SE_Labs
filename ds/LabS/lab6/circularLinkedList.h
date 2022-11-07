#include <stdio.h>
#include <stdlib.h>
//@vincentDsouza
struct node {
  int value;
  struct node * next;
};
/*
implement various link list functions
create
insert
  at beginning:done
  in empty:same as above
  at end:done
  before value
  after value
  at index:done
display:done
reverse
delete 
  at index
  value:done
  first:done
  last:done
  only:done
*/
//Note: everything implemented using double pointers

void addAtBegin(struct node **last,struct node * t){
  //if empty
  if (*last == NULL){
    t->next = t;
    *last = t;
  }else{
    t->next = (*last)->next;
    (*last)->next = t;
  }
}
void addAtEnd(struct node**last, struct node * t){
  struct node * l = *last;
  if (*last == NULL){
    t->next = t;
    *last = t;
  }else{
    t->next = l->next;
    l->next = t;
    *last = t;
  }
}
void deleteFromList(struct node **last, int val){
  if (*last){
    struct node * s = (*last)->next;
    if (s->next == s && (s->value == val)){
      free(s);//if 1 node
      s = NULL;
      return;
    }
    if (s->value == val){
      struct node * t = s;
      (*last)->next = s->next;
      free(t);
      return;
    }
    while ((s->next != (*last)->next ) && (s->next->value != val))
      s = s->next;
    if (s->next->value == val){
      if (s->next == (*last)){
        struct node * t = s->next;
        s->next = s->next->next;
        free(t);
        *last = s;
      }else{
        struct node * t = s->next;
        s->next = s->next->next;
        free(t);
      }
    }
  }
}
void displayCircularList(struct node ** last){
  struct node * p = (*last)->next;
  printf("[ ");
  if ((struct node **)((*last)->next) == last){
    printf("%d ]\n", (*last)->value);
    return;
  }
  while (p!=(*last)){
    printf("%d ",p->value);
    p = p->next;
  }
  printf("%d ]\n", (*last)->value);
}
void createCircular(struct node ** last, int n){
  //to create n nodes
  if (n>0){
    int v;
    while (n--){
      printf("Enter value:");
      scanf("%d",&v);
      struct node * temp = (struct node *)malloc(sizeof(struct node));
      temp->value = v;
      temp->next = NULL;
      addAtEnd(last,temp);
    }
  }
}