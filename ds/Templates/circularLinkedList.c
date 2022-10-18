#include <stdio.h>
#include <stdlib.h>

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

int main(){
  struct node * last = NULL;
  struct node * a = (struct node *)malloc(sizeof(struct node));
  struct node * b = (struct node *)malloc(sizeof(struct node));
  struct node * c = (struct node *)malloc(sizeof(struct node));
  struct node * d = (struct node *)malloc(sizeof(struct node));
  struct node * e = (struct node *)malloc(sizeof(struct node));
  struct node * f = (struct node *)malloc(sizeof(struct node));
  a->value = 10;
  b->value = 20;
  c->value = 30;
  d->value = 40;
  e->value = 50;
  f->value = 60;
  addAtBegin(&last,a);
  addAtEnd(&last,b);
  addAtBegin(&last,c);
  addAtEnd(&last,d);
  deleteFromList(&last,20);
  displayCircularList(&last);
  return 0;
}