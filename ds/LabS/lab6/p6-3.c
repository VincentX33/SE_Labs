#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"
//@vincent Dsouza
//program to delete alternate nodes from circular linked list
struct node * deleteAlternate(struct node ** last){
  //delete alternate nodes
  //if no node return 
  if (*last == NULL)
    return NULL;
  else if ((*last)->next == (*last)){
    //only node
    free(*last);
    *last = NULL;
    return NULL;
  }else{
    //alternate nodes to be deleted
    struct node * ptr = (*last)->next;
    struct node * temp;
    while (ptr!=(*last) && ptr->next != (*last)){
      temp = ptr->next; //intermediate node to be deleted
      ptr->next = temp->next;
      ptr = ptr->next;
      free(temp);
    }
    if (ptr->next==(*last)){
      //delete last node and make ptr the new last nodes
      temp = *last;
      ptr->next = temp->next;
      *last = ptr;
      free(temp);
    }
    return *last;
  }
}

int main(){
  //implement demo circular linked list
  struct node * demoCircular = NULL;
  int n;
  printf("Enter number of nodes:");
  scanf("%d",&n);
  createCircular(&demoCircular,n);
  printf("Original list:\n");
  displayCircularList(&demoCircular);
  printf("\nmodified list list:\n");
  demoCircular = deleteAlternate(&demoCircular);
  displayCircularList(&demoCircular);
  return 0;
}
