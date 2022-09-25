#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * next;
};

/*
addatbeg
addatend
addafter
create
add
display
multiply
polEdit
*/
struct node * addatbeg(struct node *,struct node *);
void displayLL(struct node *);
struct node * dequeue(struct node **, struct node **);
void enqueue(struct node **, struct node **);
struct node * createNode();
int main(){  
  struct node * front = NULL,*rear = NULL,*t;
  printf("---Queue----\n");
  int c;
  do {
    printf("Enter:\n ");
    printf("1 to enqueue element\n ");
    printf("2 to dequeue\n ");
    printf("3 to display\n ");
    printf("4 to count number of elements\n ");
    printf("5 to exit\n :");
    scanf("%d",&c);
    switch(c){
      case 1: 
        enqueue(&front, &rear);
        break;
      case 2: 
        t = dequeue(&front, &rear);
        printf("%d", t->data);
        break;
      case 3: 
        displayLL(front);
        break;
      case 4: 
        // printf("There are %d elements in queue\n",qcount(front));
        break;
      case 5: 
        break;
      default:
        printf("Invalid Input\n");
    }
  }while(c!=5);

  return 0;
}
void enqueue(struct node ** f, struct node ** r){
  struct node * front = *f;
  struct node * rear = *r;
  struct node * temp;
  temp = createNode();
  if (temp==NULL){
    printf("Stack overflow\n");
  }else{
    front = addatbeg(front,temp);
    if (rear == NULL){
      rear = front;
    }
  }
}
struct node * dequeue(struct node ** f, struct node ** r){
  struct node * front = *f;
  struct node * rear = *r;
  struct node * p, * temp;
  if (*f == * r){
    p = *f;
    *f = NULL;
    *r = NULL;
    return p;
  }
  for (p = *f;p->next!= *r;p = p->next)
  ;
  if (p->next == *r)
  {
    temp = *r;
    p->next = NULL;
    return temp;
  }
  
}
struct node * addatbeg(struct node * start, struct node * p){
  if (!p)
    return start;
  p->next = start;
  start = p;
  return start;
}
struct node * createNode(){
  int n;
  struct node * temp = (struct node *)malloc(sizeof(struct node ));
  if (!createNode)
    return NULL;
  printf("Enter value:");
  scanf("%d",&n);
  temp->data  = n;
  temp->next = NULL;
  return temp;
}

void displayLL(struct node * a){
    if (a==NULL){
        printf("Empty list\n");
        return;
    }
    //int i = 0;
    printf("| ");
    while (a!= NULL){
        printf("%d ",a->data);
        a = a->next;
        //i++;
    }
    printf(" |\n");
}

