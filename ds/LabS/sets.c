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
struct node * setEdit(struct node * );
void displayLL(struct node *);
struct node * deleteTerm(struct node *, int);
int isIn(struct node *, int);
struct node * Set_union(struct node *,struct node *);
struct node * difference(struct node *,struct node *);
struct node * intersection(struct node *,struct node *);


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
        if (status == 0){
          printf("Sets have to be accepted before union\nEnter Set A:\n");
          set1 = create(set1);
          printf("Enter set B:\n");
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
        printf("Enter set B:\n");
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
        printf("Enter set B:\n");
        set2 = create(set2);
        status = 1;
      }
        printf("Enter 1 for A-B, 2 for B-A:");
        scanf("%d", &e);
        if (e==1){
          set3 = difference(set1,set2);
        }else if(e==2){
          set3 = difference(set2,set1);
        }else{
          printf("Invalid order\n");
        }
        displayLL(set3);
        break;
      case 5:
        printf("Set 1: ");
        displayLL(set1);
        printf("Set 2: ");
        displayLL(set2);
        break;
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
  printf("Enter number of items:");
  scanf("%d",&n);
  while (n--){
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d", &(temp->value));
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
  if ((start==NULL) || (p->value < start->value)){
    start = addatbeg(start,p);
    return start;
  }
  struct node * temp = start;
  while ((temp->next != NULL) && (p->value > temp->next->value)){
    temp = temp->next;
  }
  //check if temp->next = null, if it is, add at end
  if (temp->next == NULL){
    if (p->value > temp->value){
      temp->next = p;
    }
  }else {
    if (p->value < temp->next->value) {
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
    printf("{ ");
    while (a!= NULL){
        printf("%d , ", a->value);
        a = a->next;
        //i++;
    }
    printf(" }\n");
}

struct node * Set_union(struct node *a,struct node *b){
  //add two sets
  struct node *sum = NULL;
  while (a!=NULL && b!= NULL)//as long as neither one  null
  {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if (a->value == b->value){
      temp->value = a->value;
      temp->next = NULL;
      if (sum == NULL){
        sum = addatbeg(sum,temp);
      }
      else {
        sum = addatend(sum,temp);
      }
    }else if (a->value < b->value){
      temp->value = a->value;
      temp->next = NULL;
      sum = addatend(sum,temp);
      a = a->next;
    }else if (b->value < a->value){
      temp->value = b->value;
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
    temp->value = p->value;
    temp->next = NULL;
    sum = addatend(sum, temp);
    p = p->next;
  }
  return sum;
}
int isIn(struct node * a, int v){
  int s = 0;
  while (a!= NULL){
    if (a->value == v){
      return 1;
    }
    a = a->next;
  }
  return 0;
}

struct node * intersection(struct node *a,struct node *b){
  if (a==NULL || b==NULL)
    return NULL;
  struct node * inter = NULL;
  int i;
  while (a && b){
    i = a->value;
    if (isIn(b,i)){
      struct node * temp = (struct node * )malloc(sizeof(struct node));
      temp->value = i;
      temp->next = NULL;
      inter = addatend(inter,temp);
    }
    a = a->next;
  }
  return inter;
}

struct node * difference(struct node * from, struct node * remove){
  struct node * inter = intersection(from, remove); 
  //iterate over from,
  //if element in inter, don't input
  struct node * result = NULL;
  for (from; from != NULL; from = from->next){
    if (!(isIn(inter,from->value))){
      struct node * temp = (struct node *)malloc(sizeof(struct node));
      temp->value = from->value;
      temp->next = NULL;
      result = addatend(result,temp);
    }
  }
  return result;
  //as we have to remove from `from` all inter elements

}
struct node * deleteTerm(struct node *start, int v){
  struct node * a = start;
  if (a == NULL)
    return a;
  else if (!(isIn(a,v)))
    return a;
  //start element
  else if (a->value == v){
    struct node * temp = a;
    a = a->next;
    free(temp);
    return a;
  }else {
    while (a->next != NULL){
      if (a->next->value == v){
        struct node * temp = a->next;
        a->next = temp->next;
        free(temp);
        return a;
      }
      a = a->next;
    }
  }
}
