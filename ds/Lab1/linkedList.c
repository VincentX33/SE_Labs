#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

struct node * create(struct node * start){
    //if a is null at at beginning
    struct node * temp;
    struct node * p;
    int w,val;
    printf("Enter number of nodes to be added:");
    scanf("%d",&w);
    if (start==NULL){
        start = (struct node * )malloc(sizeof(struct node));
        //regulate temp pointer
        printf("Enter first value:");
        scanf("%d",&val);
        start->value = val;
        start->next = NULL;
        temp = start;
        w--;
        
    }
    else{
        //if start is not null, to prevent data loss we have to
        //push temp to next until it is null
        temp = start;
        int i=0;//b
        while (temp->next!=NULL){
            temp = temp->next;
            i++;
        }
        //printf("\n moved %d nodes forward:\nCurrent node: %d\n", i,i+1);
    }
    //now temp is supposed to be NULL if >=1 element exists
    //now take the elements in temp
    //take number of elements n
    //loop n times
    while (w--){
        //printf("\nw==%d\n",w);
        if (temp->next==NULL){
                p = (struct node *)malloc(sizeof(struct node));
                //printf("\nAllocated p\n");
        }
        printf("Enter value:");
        scanf("%d",&val);
        p->value = val;
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
    //if a is not null add another node at the end and return same start
    return start;
}
void errorAddress(struct node * a){
    if (a==NULL){
        printf("Error\n");
        return ;
    }
    while (a->next!=NULL){
        printf("\nAddress of a is %x\n",a);
        printf("Address of next node is %x\n",a->next);
        printf("==========\n");
        a = a->next;
    }

}

int displayLL(struct node * a){
    if (a==NULL){
        printf("Empty list\n");
        return 0;
    }
    //int i = 0;
    printf("|");
    while (a!= NULL){
        printf("%d --> ",a->value);
        a = a->next;
        //i++;
    }
    printf("|\ni:%d\n",i);
}
int count(struct node * a){
    struct node * temp = a;
    int c = 0;
    while (temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
}
int listSum(struct node * a){
    int sum = 0;
    struct node * temp = a;
    while (temp!=NULL){
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

int searchInList(struct node * a,int value ){
    struct node * temp = a;
    while (temp!=NULL){
        if (temp->value == value){
            printf("Value %d found in list\n",value);
            return 1;
        }
        temp = temp->next;
    }
    printf("Value %d not found in linked list\n");
    return 0;
}

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
                    linklist = create(linklist);
                    break;
            case 2: //ll display
                    displayLL(linklist);
                    //errorAddress(linklist);
                    break;
            case 3: //search for given element
                    printf("Element to be searched:");
                    scanf("%d",&s);
                    searchInList(linklist,s);//later modify for verbosity
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
