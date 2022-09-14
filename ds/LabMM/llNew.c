#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;  
};
struct node * create(struct node * ,int * );
struct node * addAtBeginning(struct node *, int *, int);
struct node * addAtEnd(struct node *,int *, int);
void displayList(struct node *, int);
void searchList(struct node *,int );
int count(struct node *, int);
struct node * deleteFromList(struct node *, int *);
struct node * reverse(struct node *, int * );

int main(){
    struct node * linklist = NULL;
    int c = 0,n,s;
    do {
        printf("Enter:\n");
        printf("\t1 to add value\n\t2 to display linked list\n\t3 to search\n\t4 to count");
        printf("\n\t5 to perform value summation\n\t6 to exit\n\t:");
        scanf("%d",&c);
        switch(c){
            case 1: //
                    
                    break;
            case 2: //ll display
                    break;
            case 3: //search for given element
                    printf("Element to be searched:");
                    scanf("%d",&s);
                    break;
            case 4: //count number of elements
                    printf("There are %d elements in given list\n",count(linklist));
                    break;
            case 5: //
                    printf("The sum of linked list elements is %d\n",listSum(linklist));
                    break;
            case 6: //break;
                    break;
            default:
                    printf("Undefined input\n");
                    break;


        }
    }while(c!=6);
    return 0;
}
struct node * create(struct node * start,int * nlen){
    //create takes n nodes in the beginning
    int n,j,i;
    start = NULL;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    if (n==0)
        return start;
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
struct node * deleteFromList(struct node *start, int * nlen, int index){
    if (start == NULL){
        printf("Empty list\n");
        return; 
    }
    struct node * p = start;
    struct node * temp;
    int i = 1;
    if (index == 1){
        //del first node
        temp = start;
        start = start->next;
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
struct node * reverse(struct node * start, int * nlencd ){
    //reverse the list
    //first node shud become last,last first,2nd point to first, 3rd to 2nd
    /*
    while start->next != NULL;
        temp is made to hold value of start->next;
        start->next = temp->next ie tht node is removed
        temp->next = newstart;
        newstart = temp;
    */
}