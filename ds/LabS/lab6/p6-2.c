#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"
//@vincent Dsouza
//number storage using double linked list
void recursiveDisplay(struct node * start){
  if (start==NULL)
    return;
  recursiveDisplay(start->next);
  printf("%d ",start->value);
}
void numberStore(struct node ** start, long long number){
  //create a double linked list to store digits of number
  if (number>0){
    int d;
    while (number){
      d = number%10;
      number= number/10;
      struct node * temp = (struct node *)malloc(sizeof(struct node));
      temp->value = d;
      temp->next = NULL;
      temp->prev = NULL;
      insertAtEnd(start,temp);
    }
  }
}
void sumTwoNums(struct node **num1,struct node ** num2,struct node **sum2){
  struct node * p1 = *num1;
  struct node * p2 = *num2;
  int carry = 0, k;
  while (p1 && p2){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    k = p1->value + p2->value + carry;
    temp->value = k%10;
    carry = k/10;
    temp->next = NULL;
    temp->prev = NULL;
    insertAtEnd(sum2,temp);
    p1 = p1->next;
    p2 = p2->next;
  }
  struct node * p = (p1==NULL)?p2:p1;
  while (p){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    k = p->value + carry;
    k = k%10;
    carry = k/10;
    temp->value = k;
    temp->next = NULL;
    temp->prev = NULL;
    insertAtEnd(sum2,temp);
    p = p->next;
  }
  if (carry){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->value = carry;
    temp->next = NULL;
    temp->prev = NULL;
    insertAtEnd(sum2,temp);
  }
}
int main(){
  struct node * start = NULL;
  struct node * num1, *num2;
  num1 = NULL;
  num2 = NULL;
  int n1=1,n2=2;
  printf("Enter number 1:");
  scanf("%d",&n1);
  printf("Enter number 2:");
  scanf("%d",&n2);
  numberStore(&num1,n1);
  displayDoubleList(&num1);
  numberStore(&num2,n2);
  displayDoubleList(&num2);
  struct node * sum2 = NULL ;
  sumTwoNums(&num1,&num2,&sum2);
  recursiveDisplay(sum2);
  return 0;
}