#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
  struct node * next;
};

/*
addatbeg
addatend
addafter
create
add
display
polEdit
*/
struct node * addafter(struct node *,struct node *);
struct node * addatbeg(struct node *,struct node *);
struct node * addatend(struct node *,struct node *);
struct node * create(struct node *);
struct node * add(struct node *,struct node *);
struct node * setEdit(struct node * );
void displayLL(struct node *);
struct node * deleteTerm(struct node *, int);
int isIn(struct node *);
int main(){
  struct node * set1 = NULL, * set2 = NULL, * set3 = NULL, *set4 = NULL;
  int c,status = 0,e;
  printf("---------Set handler program-----------\n");
  do{
    printf("Enter\n 1 to accept 2 sets\n ");
    printf("2 to perform set union\n ");
    printf("3 to perform set intersection\n ");
    printf("4 to perform set difference\n ");
    printf("5 to display both sets\n ");
    printf("6 to exit \n ");
    scanf("%d",&c);
    switch(c){
      case 1:
        printf("Enter set A :\n");
        set1 = create(set1);
        printf("Enter set p2 :\n");
        set2 = create(set2);
        status = 1;
        break;
      case 2:
        if (status == 0){union
          printf("Sets have to be accepted before union\nEnter Set A:\n");
          set1 = create(set1);
          printf("Enter set B:\n")
          set2 = create(set2);
          status = 1;
        }
        set3 = Set_union(set1, set2);
        displayLL(set3);
        break;
      case 3:
      if (status == 0){
        printf("Sets have to be accepted before intersection\nEnter Set A:\n");
        set1 = create(set1);
        printf("Enter set B:\n")
        set2 = create(set2);
        status = 1;
      }
        set4 = intersection(set1,set2);
        displayLL(set4);
        break;
      case 4:
      if (status == 0){
        printf("Sets have to be accepted before difference\nEnter Set A:\n");
        set1 = create(set1);
        printf("Enter set B:\n")
        set2 = create(set2);
        status = 1;
      }
        printf("Enter 1 for A-B, 2 for B-A:");
        scanf("%d", &e);
        if (e==1){

        }else if(e==2){

        }else{
          printf("Invalid order\n");
        }
        break;
      case 5:
        displayLL(set1);
        displayLL(set2);
      case 6:
        break;
      default:
        printf("Enter correct input values\n");
    }
  }while(c!=6);

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
  //check first node is null or not
  if ((start==NULL) || (p->expo > start->expo)){
    start = addatbeg(start,p);
    return start;
  }
  struct node * temp = start;
  while ((temp->next != NULL) && (p->expo < temp->next->expo)){
    temp = temp->next;
  }
  //check if temp->next = null, if it is, add at end
  if (temp->next == NULL){
    //check whether one node only
    if (p->expo > temp->expo){
      p->next = temp;
      start = p;
    }
    else if (p->expo == temp->expo){
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
    printf(" + 0 = 0 |\n");
}

struct node * add(struct node *a,struct node *b){
  //add two sets
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
struct node * multiply(struct node * p1, struct node *p2){
  //multiplication valid as long as both are non null
  struct node * product = NULL;
  struct node * a, *b;
  a = p1;
  b = p2;
  if (a==NULL || b==NULL)
    return product;
  /*
  carry out outer traversal on one set
  inner traversal occurs as long as outer is not null
  use just one product node
  */
 while (a!=NULL){
  b = p2;
  while (b!=NULL){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = a->coeff * b->coeff;
    temp->expo = a->expo + b->expo;
    temp->next = NULL;
    product = addafter(product, temp);
    b = b->next;
  }
  a = a->next;
 }
 return product;
}
struct node * polEdit(struct node * a){
  //either insert a term or delete a term
  int c;
  printf("Enter \n\t1 to insert a term\n\t2 to delete a term\n:");
  scanf("%d", &c);
  struct node * temp = (struct node *)malloc(sizeof(struct node));
  if (c==1)
  {
    printf("Enter coefficient and exponent:");
    scanf("%d,%d",&(temp->coeff),&(temp->expo));
    temp->next = NULL;
    a = addafter(a,temp);
  }
  else if (c==2){
    printf("Enter exponent of term to be deleted:");
    scanf("%d",&c);
    a = deleteTerm(a, c);
  }
  else{
    printf("Only two options\nReturning unmodified start\n");
  }
  return a;
}
struct node * deleteTerm(struct node * start, int exp){
  struct node * p = start;
  if (start == NULL)
    return start;
  else if (start->expo == exp){
    p = start;
    start = start->next;
    free(p);
    return start;
  }
  while (p->next!=NULL){
    if (p->next->expo == exp){
      struct node * temp = (struct node *)malloc(sizeof(struct node));
      temp = p->next;
      free(temp);
      p->next = temp->next;
      return start;
    }
    p = p->next;
  }
  }
  printf("Item %d not found in list\n");
  return start;
