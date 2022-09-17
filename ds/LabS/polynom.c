#include <stdio.h>
#include <stdlib.h>

struct node{
  int coeff;
  int expo;
  struct node * next;
};

/*
addatbeg
addatend
addafter is value based
create
display
*/
struct node * addafter(struct node *,struct node *);
struct node * addatbeg(struct node *,struct node *);
struct node * addatend(struct node *,struct node *);
struct node * create(struct node *);
struct node * add(struct node *,struct node *);
void displayLL(struct node *);

int main(){
  //accept a polynomial
  struct node * polynomial1, * polynomial2, * p3;
  printf("Enter two polynomials and get their addition:\n");
  polynomial1 = create(polynomial1);
  polynomial2 = create(polynomial2);
  p3 = add(polynomial1, polynomial2);
  displayLL(p3);
  return 0;
}
struct node * create(struct node * start){
  //start == NULL
  start = NULL;
  struct node * temp;
  int n,a,b;
  printf("Enter number of terms:");
  scanf("%d",&n);
  while (n--){
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter coefficient and exponent (c,e):");
    scanf("%d,%d", &(temp->coeff),&(temp->expo));
    temp->next = NULL;
    if (start == NULL){
      start = addatbeg(start,temp);
    }else{
      start = addafter(start, temp);
    }
  }
  return start;
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
struct node * addafter(struct node * start, struct node * p){
  //check if p's coefficient < the next node's coefficient
  //check first node corr
  if (p->expo > start->expo){
    start = addatbeg(start,p);
    return start;
  }
  struct node * temp = start;
  while ((temp->next != NULL) && (p->expo < temp->next->expo)){
    temp = temp->next;
  }
  //check if temp->next = null, if it is, add at end
  if (temp->next == NULL){
    //our expo is smaller than any yet stored so it has to be added at end
    //check add beg/end
    if (p->expo > temp->expo){
      p->next = temp;
      start = p;
    }else if (p->expo == temp->expo){
      temp->coeff += p->coeff;
    }else if (p->expo < temp->expo){
      temp->next = p; //if the p exp is lower than any yet encountered
    }
    return start;
  }else {
    if (p->expo == temp->next->expo)
      temp->next->coeff += p->coeff;
    else if (p->expo > temp->next->expo) {
      p->next = temp->next;
      temp->next = p;
    }
  }
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
        printf("%dX^%d + ",a->coeff, a->expo);
        a = a->next;
        //i++;
    }
    printf(" = 0 |\n");
}

struct node * add(struct node *a,struct node *b){
  //add two polynomials
  struct node * sum = NULL;
  while (a!=NULL && b!= NULL)//as long as neither one  null
  {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if (a->expo == b->expo){
      temp->expo = b->expo;
      temp->coeff = a->coeff + b->coeff;
      temp->next = NULL; //not needed
      sum = addatend(sum,temp);
      a = a->next;
      b = b->next;
    }else if (a->expo > b->expo){
      temp->expo = a->expo;
      temp->coeff = b->coeff;
      temp->next = NULL;
      sum = addatend(sum,temp);
      a = a->next;
    }else if (b->expo > a->expo){
      temp->expo = b->expo;
      temp->coeff = b->coeff;
      temp->next = NULL;
      sum = addatend(sum,temp);
      b = b->next;
    }
  }
  struct node * p;
  //handle the other one
  p = (a==NULL)?b:a;
  while (p!=NULL){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = p->coeff;
    temp->expo = p->expo;
    temp->next = NULL;
    sum = addatbeg(sum, temp);
    p = p->next;
  }
  return sum;
}