#include <stdio.h>
#include <stdlib.h>
//implement dynamic data structures
struct node {
  struct node * prev;
  int value;
  struct node * next;
};
/*
implement various double link list functions
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
  first:
  last:
  only:
*/
//Note: everything implemented using double pointers
void insertAtBeg(struct node ** start,struct node *t){
  //link t to start of start
  if (!(*start)){
    *start = t;
    t->next = NULL;
    t->prev = NULL;
    return;
  }
  (*start)->prev = t;
  t->prev = NULL;
  t->next = *start;
  *start = t;
}
void insertAtEnd(struct node ** start,struct node * t){
  if (*start){
    struct node * p;
    for (p = *start;p->next!=NULL;p = p->next);
    t->prev = p;
    t->next = NULL;
    p->next = t;
  }else{
    *start = t;
    t->next = NULL;
    t->prev = NULL;
  }
}
void displayDoubleList(struct node ** start){
  struct node * p = *start;
  printf("[ ");
  while (p!=NULL){
    printf("%d ",p->value);
    p = p->next;
  }
  printf(" ]\n");
}
void deleteValue(struct node **start,int val){
  if (*start){
    struct node * p = *start;
    if (p->value == val){
      struct node * t = p;
      if (p->next == NULL){
        free(*start);
        *start = NULL;
      }else{
        *start = (p->next);
        p->next->prev = NULL;
        free(p);
      }
      return;
    }
    while (p->next!=NULL && p->next->value != val){
      p = p->next;
    }
    if (p->next){
      //if last value then next->prev won't occur
      if (p->next->next){
        struct node * t = p->next;
        p->next->next->prev = p;
        p->next = p->next->next;
        free(t);
      }else{
        struct node * t = p->next;
        p->next = NULL;
        free(t);
      }
    }
  }
}
// void deleteIndex(struct node ** start, int index){
//   if (index==0)
// }
void reverse(struct node ** start){
  //reverse the list
  struct node * t = *start;
  struct node * st = t;
  struct node * ns ;
  if (t){
    while (t->next!=NULL){
      t=t->next;
    }
    ns = st;
    //now t is at last node
    //as long as t is not same as st
    struct node * temp;
    //manipulate st instead
    while (st->next!=NULL && st->next->next){
      //take the next adjacent node and add it to start
      temp = st->next;
      st->next->next->prev = st; //removing middle node
      st->next = st->next->next; 
      temp->next = ns;
      ns->prev = temp;
      temp->prev = NULL;
      ns = temp;
    }
    if (st->next == NULL){
      *start = ns;
    }else if (st->next->next == NULL){
      temp = st->next;
      st->next = NULL;
      temp->next = ns;
      ns->prev = temp;
      ns = temp;
    }
    *start = ns;
  }
}
int main(){
  struct node * dblist = NULL;
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
  insertAtBeg(&dblist, a);
  insertAtEnd(&dblist, b);
  insertAtBeg(&dblist, c);
  insertAtEnd(&dblist, d);
  insertAtBeg(&dblist, e);
  deleteValue(&dblist,50);
  insertAtEnd(&dblist, f); 
  reverse(&dblist);
  displayDoubleList(&dblist);
  //shud get  50 30 10 20 40 60

  return 0;
}
void createDouble(struct node ** start,int n){
  if (n>0){
    int v;
    while (n--){
      printf("Enter value:");
      scanf("%d",&v);
      struct node * temp = (struct node *)malloc(sizeof(struct node));
      temp->value = v;
      temp->next = NULL;
      insertAtEnd(start,temp);
    }
  }
}