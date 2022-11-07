#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"
//@vincent Dsouza

//swap the adjacent elements of doubly linkedlist
//by rearrangin the links
void swap(struct node ** start){
  //if empty or only node unchanged
  if (*start == NULL || (*start)->next == NULL){
    return;
  }else{
    //replace start elements
    struct node * temp1 = (*start);
    struct node * temp2 = temp1->next; 
    while (temp1 && temp2){
      //atleast 3 nodes non null
      if (temp1->prev)
        temp1->prev->next = temp2;
      if (temp2->next)
        temp2->next->prev = temp1;
      temp2->prev = temp1->prev;
      temp1->next = temp2->next;
      temp1->prev = temp2;
      temp2->next = temp1;
      //after swap
      if (*start == temp1){
        *start = temp2;
      }
      temp1 = temp1->next;
      if (temp1){
        temp2 = temp1->next;
      }
    }
  }
}
int main(){
  struct node * start = NULL;
  int n;
  printf("Enter number of elements:");
  scanf("%d",&n);
  if (n>10000)
    return 1;
  createDouble(&start,n);
  displayDoubleList(&start);
  swap(&start);
  displayDoubleList(&start);
  return 0;
}