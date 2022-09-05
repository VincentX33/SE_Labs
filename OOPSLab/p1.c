#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct Book{
    char name[30];
    char author[30];
    int ncopies;
    char subject[25];
};
typedef struct Book Book;

void insertBook(Book * a,int * nbooks){
    fflush(stdin);
    char c;
    int x = *nbooks;
    if (*nbooks != 0){
        //printf("Trigger\n");
        c = getchar();
    }
    for (int i = 0;i < x;i++){
        a++;
    }
    char lname[30],lauthor[30],lsub[25];
    lname[0] = 0;
    int lcopies;
    printf("Enter book name:");
    fgets(lname, 25, stdin);
    lname[strlen(lname)-1] = '\0';
    printf("Strlen of %s is %d\n",lname,strlen(lname));
    // gets(lname); //this takes proper name but error for array
    // getchar();
    strcpy(a->name, lname);
    if (lname[0]==0)
        printf("\nError\n");
    printf("Enter author name:");
    fgets(lauthor,50,stdin);
    lauthor[strlen(lauthor)-1] = '\0';
    printf("Strlen of %s is %d\n",lauthor,strlen(lauthor));
    // gets(lauthor);
    // getchar();
    strcpy(a->author, lauthor);
    printf("Enter subject:");
    fgets(lsub,50,stdin);
    lsub[strlen(lsub)-1] = '\0';
    printf("Strlen of %s is %d\n",lsub,strlen(lsub));
    // gets(lsub);
    //getchar();
    strcpy(a->subject, lsub);
    printf("Enter number of copies available:");
    scanf("%d",&lcopies);
    a->ncopies = lcopies;
    *nbooks = *nbooks + 1;
    if (a->name[0] == '\n')printf("Problem");
    // fflush(stdin);
}

void displayBook(Book * a){
    printf("---------------------\n");
    printf(" Name : %s\n",a->name );
    printf(" Author : %s\n",a->author );
    printf(" Subject : %s\n",a->subject );
    printf(" No of copies : %d\n",a->ncopies);
    printf("---------------------\n");
    sleep(0.5);
}
void displayAllBooks(Book * a,int nbooks){
    printf("=================================");
    printf("Library containing %d books:\n",nbooks);

    for (int i=0;i< (nbooks);i++){
        displayBook(a);
        a++;
    }
    printf("\n=================================\n");

    sleep(2);
}
void nameSearch(Book * a,char * name, int nbooks){
    sleep(1);
    int q = 1;
    for (int i=0;i<(nbooks) && q;i++){
        //locate the book
        if (strcmp(a->name, name)==0){
            printf("\n\tLocated Book\n");
            q = 0;
            displayBook(a);
        }else{
            printf("Name=%sSearchName=%s\nL1=%d\tl2=%d\n",a->name,name,strlen(a->name),strlen(name));
        }
        a++;
    }
    if (q==1)
        printf("Book not found\n");
}
void authorSearch(Book * a, char * author, int nbooks){
    int q = 1;
    //printf("nbooks=%d\n",nbooks);
    for (int i=0;i<(nbooks) && q;i++){
        //locate the book
        //printf("Author = %s",a->author);
        if (strcmp(a->author, author)==0){
            printf("\n\tLocated Book\n");
            q = 0;
            displayBook(a);
        }else{
            //printf("Author=%s, SearchAuthor=%s\n",a->author,author);
        }
        a++;
    }
    if (q==1){
        printf("Book not found\n");
        sleep(2);
    }
        
}
/*
void bookDelete(Book * q, int index, int * nbooks){
    int i = index,x=*nbooks,j=0;
    Book * a = q,*b;
    if (1){
        printf("Enter index to delete:");
        scanf("%d",&i);
    }
    if (i==(x-1))
        *nbooks =i;
    //to push a to the element we wish to delete
    while (j<i && (i!=(*nbooks))){
        a++;
        j++;
    }
    while (i<(x-1)){
        b = a+1;
        strcpy(a->author,b->author);
        strcpy(a->name,b->name);
        strcpy(a->subject,b->subject); 
        a->ncopies = b->ncopies;
        i++;
        a++;
    }
    *nbooks = *nbooks-1;
}
*/

void bookDelete(Book * a,int index,int * nbook){
    if (*nbook <= 0){
        printf("Error\n");
        return;
    }
    Book * b;
    int i = index-1, x = *nbook,j,k=0;
    char q[32],r[32],s[32];
    if (i>(x-1)){
        printf("Error\n");
        return;
    }
    /*
    we need to push a to location we wish to delete
    if we wish to delete location 0 
    then we needed to do a=a+0;
    ~ if location 1 need deletion then a = a+1;
    so to delete index i we need to do a = a+i;
    */
    a = a+i;
    //have to handle case where selected element is last in array
    if (i == (x-1)){
        // printf("Last library book\n");
        *nbook = *nbook-1;
        return;
    }
    //now do deletion
    while (i<(x-1))
    {
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
int main(){
    int i=0,n=0,delIn; //n is for number of books in the library(unique only)
    Book library[10];
    char *s = (char *)malloc(sizeof(char)*50);
    printf("----- Library Management Tool --------\n");
    // Book b1;
    //insertBook(&b1,&n);
    //displayBook(&b1);
    Book * lb = library;
    //insertBook(lb, &n);
    //insertBook(lb, &n);
    //insertBook(lb, &n);
    //insertBook(lb, &n);
    //insertBook(lb, &n);
    //nameSearch(lb,"sid",n); //tested works
    //authorSearch(lb,"vv",n); //tested works
    //bookDelete(library,1,&n);
    //displayAllBooks(library,n);
    
    do {
        printf("Enter\n 1 to insert book record\n 2 to Search based on book name\n ");
        printf("3 to Search based on author name\n 4 to Delete a book from the record\n ");
        printf("5 to display all book records\n 6 to exit the program\n\t:");
        scanf("%d",&i);
        switch(i){
            case 1: //insertion function
                    insertBook(lb, &n);
                    break;
            case 2: //search by book name
                    printf("Enter name of book:");
                    fflush(stdin);
                    gets(s);
                    nameSearch(lb,s,n);
                    break;
            case 3: //search by book author
                    printf("Enter name of author:");
                    fflush(stdin);
                    gets(s);
                    authorSearch(lb,s,n);
                    break;
            case 4: //delete a book
                    printf("Delete nth book for n(+ve n):");
                    scanf("%d",&delIn);
                    if (n<=0)
                        break;
                    bookDelete(lb,delIn,&n);
                    break;
            case 5: //dislayAllbooks
                    displayAllBooks(library,n);
                    break;
            case 6: break;
            default: printf("Choose an option from (1-6):\n");
        }
    }while (i!=6);
    
    return 0;

}