#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;  
};
struct node * create(struct node * ,int * );
struct node * addAtBeginning(struct node *, int *, int);
struct node * addAtEnd(struct node *,int *, int);
void displayList(struct node *);
void searchList(struct node *,int );
int count(struct node *);
struct node * deleteIndexFromList(struct node *, int *,int);
struct node * deleteValueFromList(struct node *, int *,int);
struct node * reverse(struct node *, int * );
struct node * addAfter(struct node *,int *, int,int);
struct node * addBefore(struct node *,int *, int,int);

int main(){
    struct node * linklist = NULL;
    int c = 0,n = 0,s,index,data,value;
    do {
        printf("Enter:\n");
        printf("\t1 to add value\n\t2 to display linked list\n\t");
        printf("3 to search\n\t4 to delete at a location");
        printf("\n\t5 to perform reversal\n\t");
        printf("6 to insert node before a value\n\t");
        printf("7 to insert node after a value\n\t");
        printf("8 to delete a value\n\t");
        printf("9 to exit\n\t:");
        scanf("%d",&c);
        switch(c){
            case 1: //add value to linked list
                    linklist = create(linklist,&n);
                    break;
            case 2: //ll display
                    displayList(linklist);
                    break;
            case 3: //search for given element
                    printf("Element to be searched:");
                    scanf("%d",&s);
                    searchList(linklist,s);
                    break;
            case 4: //delete element
                    printf("Enter index to be deleted:");
                    scanf("%d", &index);
                    linklist = deleteIndexFromList(linklist, &n,index);
                    break;
            case 5: //reverse the linklist
                    linklist = reverse(linklist,&n);
                    break;
            case 6: //insert at 
                    printf("Enter value before which to insert:");
                    scanf("%d", &data);
                    printf("Enter value to be inserted:");
                    scanf("%d",&value);
                    linklist = addBefore(linklist,&n,data,value);
                    break;
            case 7: //insert at 
                    printf("Enter value after which to insert:");
                    scanf("%d", &data);
                    printf("Enter value to be inserted:");
                    scanf("%d",&value);
                    linklist = addAfter(linklist,&n,data,value);
                    break;
            case 8: printf("Enter value to be deleted:");
                    scanf("%d", &value);
                    linklist = deleteValueFromList(linklist, &n,value);
                    break;
            case 9: //break;
                    break;
            default:
                    printf("Undefined input\n");
                    break;
        }
    }while(c!=9);
    return 0;
}
struct node * create(struct node * start,int * nlen){
    //create takes n nodes in the beginning
    int n,j,i;
    //start = NULL;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    if (n==0)
        return start;
    if (*nlen != 0){
        //if list already exists
        for (j = 0;j<n;j++){
            printf("Enter value:");
            scanf("%d",&i);
            start = addAtEnd(start,nlen,i);
        }    
        return start;
    }
    printf("Enter value:");
    scanf("%d",&i);
    start = addAtBeginning(start,nlen,i); //add at beg will add content and return start pointer
    for (j = 1;j<n;j++){
        printf("Enter value:");
        scanf("%d",&i);
        start = addAtEnd(start,nlen,i);
    }
    return start;
}
struct node * addAtBeginning(struct node * start, int * nlen, int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = start;
    start = temp;
    *nlen = *nlen + 1;
    return start;
}
struct node * addAtEnd(struct node * start,int * nlen, int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    struct node * p = start;
    temp->data = val;
    temp->next = NULL;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    *nlen = *nlen + 1;
    return start;
}
void displayList(struct node * start){
    if (start == NULL){
        printf("Empty list\n");
        return;
    }
    struct node * p = start;
    while (p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n---------------------\n");
}
void searchList(struct node * start,int val ){
    if (start==NULL){
        printf("Empty list\n");
        return;
    }
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p = start;
    int pos = 1;
    while (p!=NULL){
        if (p->data == val){
            printf("Value %d exists in list at position %d\n", val,pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Item %d not in list\n", val);
}
int count(struct node * start){
    int count = 0;
    struct node * temp = start;
    while (temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
struct node * deleteIndexFromList(struct node *start, int * nlen, int index){
    if (start == NULL){
        printf("Empty list\n");
        *nlen = 0;
        return start; 
    }
    if (index > *nlen ){
        printf("Index out of bounds\n");
        return start;
    }
    struct node * p = start;
    struct node * temp;
    int i = 1;
    if (index == 1){
        //del first node
        temp = start;
        start = start->next;
        free(temp);
    }else if (index == *nlen){
        while (i<index-1){
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = NULL;
        free(temp);
    }else{
        while (i<index-1){
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    *nlen = *nlen -1 ;
    return start;
}
struct node * deleteValueFromList(struct node *start, int * nlen, int value){
    if (start == NULL){
        printf("Empty list\n");
        *nlen = 0;
        return start; 
    }
    struct node * p = start, * temp;
    int i = 1;
    if (p->data == value){
        temp = p;
        start = p->next;
        free(temp);
        *nlen = *nlen - 1;
        return start;
    }   
    for (p; p->next!=NULL;p = p->next){
        if (p->next->data == value){
            temp = p->next;
            p->next = temp->next;
            free(temp);
            *nlen = *nlen - 1;
            return start;
        }
        if (p->next==NULL)
            break;
    }
    if (p->next==NULL){
        printf("Item %d not found in list\n", value);
    }
    return start;
}
struct node * reverse(struct node * start, int * nlen ){
    //first node shud become last,last first,2nd point to first, 3rd to 2nd
    /*
    p = start
    while p->next != NULL;
        temp is made to hold value of start->next;
        p->next = temp->next ie tht node is removed
        temp->next = start;
        start = temp;
    */
   if (start == NULL){
    printf("Empty list");
    return start;
   }
   struct node * temp, *ptr, *a;
   ptr = start;
   while (ptr->next != NULL){
    temp = ptr->next; //the second node is stored as temp;
    ptr->next = temp->next; //the third node is pointed to by first node
    temp->next = start;
    start = temp; 
    //now temp becomes first node as it points to ptr, ptr points to 3rd      
   }
   return start;
}
struct node * addAfter(struct node * start ,int *len, int data,int value){
    if (start == NULL){ //for when start is NULL
        printf("List is empty, so value not found in list\n");
    }else if (start->data == data){
        struct node * temp = (struct node * )malloc(sizeof(struct node));
        temp->data = value;
        temp->next = start->next;
        start->next = temp;
        *len = * len + 1;
        return start;
    }else {
        struct node * p;
        for (p = start; p->next!=NULL;p = p->next){
            if (p->data == data){
                struct node * temp = (struct node * )malloc(sizeof(struct node));
                temp->data = value;
                temp->next = p->next;
                p->next = temp;
                *len = * len + 1;
                return start;
            }
        }
        if (p->data == data){
            struct node * temp = (struct node * )malloc(sizeof(struct node));
            temp->data = value;
            temp->next = p->next;
            p->next = temp;
            *len = * len + 1;
        }else {
            printf("Required value is not in list\n");
        }
    }
}
struct node * addBefore(struct node * start ,int *len, int data,int value){
    if (start == NULL){ //for when start is NULL
        printf("List is empty, so value not found in list\n");
    }else if (start->data == data){
        start = addAtBeginning(start,len,value);
    }else {
        struct node * p;
        for (p = start; p->next!=NULL;p = p->next){
            if (p->next->data == data){
                struct node * temp = (struct node * )malloc(sizeof(struct node));
                temp->data = value;
                temp->next = p->next;
                p->next = temp;
                *len = * len + 1;
                break;
            }
        }
        if (p->next==NULL){
            printf("Required value is not in list\n");
        }
    }
    return start;
}
