#include <stdio.h>
#include <stdlib.h>
//implement dynamic data structures
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
void insertAtBeginning(struct node ** start, struct node * t){
  //have to insert t before start's node
  t->next = *start; //point t to start
  *start = t; 
}
void insertAtEnd(struct node ** start, struct node * t){
  //have to insert at last pos
  struct node * p = *start;
  if (p==NULL){
    t->next = *start; //point t to start
    *start = t;
  }
  else {
    while (p->next != NULL)p = p->next;
    p->next = t;
  }
}
void insertAtIndex(struct node ** start, struct node * t, int i){
  //have to insert at i
  struct node * p = *start;
  if (i == 1){
    insertAtBeginning(start,t);
  }
  else {
    //iterate till either i matched or NULL
    int l;
    for (l=1;l<i-1 && p!=NULL;l++, p = p->next)
      ;
    //if p->next is null
    if (p){
      if (p->next == NULL)
        p->next = t;
      else {
        t->next = p->next;
        p->next = t;
      }
    }
  }
}

void displayList(struct node * start){
  if (start == NULL){
    printf("Empty list\n");
    return;
  }
  printf("=======\n");
  while (start!=NULL){
    printf("%d  ",start->value);
    start = start->next;
  }
  printf("\n=======\n");
}
void deleteFirst(struct node ** start){
  struct node * temp = *start;
  *start = (*start)->next;
  free(temp);
}
void deleteLast(struct node ** start){
  struct node * p = *start,*temp;
  if (p==NULL){
    return;
  }
  else if (p->next == NULL){
    free(*start);
    *start = NULL;
    return;
  }
  else {
    while (p->next->next != NULL)p = p->next;
    temp = p->next;
    p->next = NULL;
    free(temp);
  }
}
void deleteValue(struct node ** start, int val){
  //check for first instance of val and delete
  if (*start == NULL)
    return;
  if ((*start)->value == val){
    struct node * temp = *start;
    *start = (*start)->next;
    free(temp);
    return;
  }
  struct node * p = *start;
  while (p->next != NULL){
    if (p->next->value == val){
      struct node * temp = p->next;
      p->next = p->next->next;
      free(temp);
      break;
    }
    p = p->next;
  }
}
void deleteAtIndex(struct node ** start, int ind){
  if (ind == 1){
    deleteFirst(start);
  }
  int i = 1;
  struct node * p = *start, *temp;
  for (i; i<ind-1 && p!=NULL;i++,p = p->next)
    ;
  if (p==NULL)
    return;
  if (p->next!=NULL){
    temp = p->next;
    p->next = p->next->next;
    free(temp);
  }
}
int main(){
  struct node *list = NULL;
  printf("Address of list's pointer is %p\n",&list);
  struct node * t = (struct node *)malloc(sizeof(struct node));
  t->value = 100;
  t->next = NULL;
  insertAtBeginning(&list,t);
  printf("Address of list's pointer is %p\n",&list);
  struct node * r = (struct node *)malloc(sizeof(struct node));
  r->next = NULL;
  r->value = 300;
  insertAtEnd(&list,r);
  struct node * q = (struct node *)malloc(sizeof(struct node));
  q->value = 200;
  q->next = NULL;
  insertAtIndex(&list,q,2);
  displayList(list);
  deleteValue(&list,100);
  deleteAtIndex(&list,2);
  displayList(list);
  return 0;
}