#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 20
#define SIZE 50
struct Book{
    char name[SIZE];
    char author[SIZE];
    int ncopies;
    char subject[SIZE];
};
typedef struct Book Book;

void insertBook(Book * a,int * nbooks){
    char c;
	c = getchar();
    int x = *nbooks;
    if (*nbooks != 0){
        //printf("Trigger\n");
        c = getchar();
    }
   	int i = 0;
    for (i = 0;i < x;i++){
        a++;
    }
    char lname[SIZE],lauthor[SIZE],lsub[SIZE];
    lname[0] = 0;
    int lcopies;
    printf("Enter book name:");
    fgets(lname, SIZE, stdin);
    lname[strlen(lname)-1] = '\0';
    strcpy(a->name, lname);
    if (lname[0]==0)
        printf("\nError\n");
    printf("Enter author name:");
    fgets(lauthor,SIZE,stdin);
    lauthor[strlen(lauthor)-1] = '\0';
    strcpy(a->author, lauthor);
    printf("Enter subject:");
    fgets(lsub,SIZE,stdin);
    lsub[strlen(lsub)-1] = '\0';
    strcpy(a->subject, lsub);
    printf("Enter number of copies available:");
    scanf("%d",&lcopies);
    a->ncopies = lcopies;
    *nbooks = *nbooks + 1;
    if (a->name[0] == '\n')printf("Problem");
}

void displayBook(Book * a){
    printf("---------------------\n");
    printf(" Name : %s\n",a->name );
    printf(" Author : %s\n",a->author );
    printf(" Subject : %s\n",a->subject );
    printf(" No of copies : %d\n",a->ncopies);
    printf("---------------------\n");
    sleep(1);
}
void displayAllBooks(Book * a,int nbooks){
    printf("=================================\n");
    printf("Library containing %d books:\n",nbooks);
	int i;
    for (i=0;i< (nbooks);i++){
        displayBook(a);
        a++;
    }
    printf("\n=================================\n");
    sleep(0.5);
}
void nameSearch(Book * a,char * name, int nbooks){
    sleep(1);
    int q = 1,i;
    for (i=0;i<(nbooks) && q;i++){
        //locate the book
        if (strcmp(a->name, name)==0){
            printf("\n\tLocated Book\n");
            q = 0;
            displayBook(a);
        }
        a++;
    }
    if (q==1)
        printf("Book not found\n");
    sleep(0.5);
}
void authorSearch(Book * a, char * author, int nbooks){
    int q = 0, i;
    for (i=0;i<(nbooks);i++){
        //locate the book
        if (strcmp(a->author, author)==0){
            if (q==0)
                printf("\n\tLocated Book\n");
            q++;
            displayBook(a);
        }
        a++;
    }
    if (q==0){
        printf("Book not found\n");
    }
    sleep(0.5);
}

void bookDelete(Book * a,int index,int * nbook){
    if (*nbook <= 0){
        printf("Empty library\n");
        return;
    }
    Book * b;
    int i = index-1, x = *nbook,j,k=0;
    char q[SIZE],r[SIZE],s[SIZE];
    if (i>(x-1)){
        printf("Shelf empty at that position\n");
        return;
    }
    /*  we need to push a to location we wish to delete
    if we wish to delete location 0,then we 
    needed to do a=a+0;
    ~ if location 1 need deletion then a = a+1;
    so to delete index i we need to do a = a+i; */
    a = a+i;
    //have to handle case where selected element is last in array
    if (i == (x-1)){
        *nbook = *nbook-1;
        return;
    }
    while (i<(x-1)){
        b = a+1;
        strcpy(q,b->name);
        strcpy(r,b->author);
        strcpy(s,b->subject);
        j = b->ncopies;
        strcpy(a->name,q);
        strcpy(a->author,r);
        strcpy(a->subject,s);
        a->ncopies = j;
        a++;
        i++;
    }
    *nbook = *nbook -1;
}

int subjectInventory(Book * a, char * subject, int nbooks){
    int q = 0,i;
    for (i=0;i<(nbooks);i++){
        if (strcmp(a->subject, subject)==0){
            if (q==0)
                printf("\n\tSubject has book/s\n");
            q++;
            displayBook(a);
        }
        a++;
    }
    if (q==0){
        printf("No book found under given subject\n");
    }
    sleep(0.5);
}


int main(){
    int i=0,n=0,delIn; //n is for number of books in the library(unique only)
    Book library[MAX];
    char *s = (char *)malloc(sizeof(char)*50);
    printf("----- Library Management Tool --------\n");
    Book * lb = library;
    char c;
    do {
        sleep(0.6);
        printf("Enter\n 1 to insert book record\n 2 to Search based on book name\n ");
        printf("3 to Search based on author name\n 4 to Delete a book from the record\n ");
        printf("5 to Display all book records\n ");
        printf("6 to Get subject inventory\n ");
        printf("7 to Exit the program\n\t:");
        scanf("%d",&i);
        switch(i){
            case 1: //insertion function
                    insertBook(lb, &n);
                    break;
            case 2: //search by book name
                    printf("Enter name of book:");
                    //fflush(stdin);
                    c = getchar();
                    gets(s);
                    nameSearch(lb,s,n);
                    break;
            case 3: //search by book author
                    printf("Enter name of author:");
                    c = getchar();
                    gets(s);
                    authorSearch(lb,s,n);
                    break;
            case 4: //delete a book
                    printf("Delete nth book for n(+ve n):");
                    scanf("%d",&delIn);
                    bookDelete(lb,delIn,&n);
                    break;
            case 5: //dislayAllbooks
                    displayAllBooks(library,n);
                    break;
            case 6: //subject inventory
                    printf("Enter subject:");
                    c = getchar();
                    gets(s);
                    subjectInventory(lb,s,n);
                    break;
            case 7: break;
            default: printf("Choose an option from (1-7):\n");
        }
    }while (i!=7);

    return 0;
}