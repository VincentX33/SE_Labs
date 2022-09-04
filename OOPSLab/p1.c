#include <stdio.h>
#include <string.h>
struct Book{
    char name[30];
    char author[30];
    int ncopies;
    char subject[25];
};
typedef struct Book Book;

void insertBook(Book * a,int * nbooks){
    if (*nbooks != 0){
        printf("Trigger\n");
        a++;//next empty position
    }
    char lname[30],lauthor[30],lsub[25];
    lname[0] = 0;
    int lcopies;

    printf("Enter book name:");
    getchar();
    fgets(lname, 50, stdin);
    strcpy(a->name, lname);
    if (lname[0]==0)
        printf("\nError\n");
    printf("Enter author name:");

    fgets(lauthor,50,stdin);
    strcpy(a->author, lauthor);
    printf("Enter subject:");
    fgets(lsub,50,stdin);
    strcpy(a->subject, lsub);
    printf("Enter number of copies available:");
    scanf("%d",&lcopies);
    a->ncopies = lcopies;
    *nbooks = *nbooks + 1;
    if (a->name[0] == '\n')printf("Problem");
    //fflush(stdin);
}

void displayBook(Book * a){
    printf("---------------------\n");
    printf(" Name : %s\n",a->name );
    printf(" Author : %s\n",a->author );
    printf(" Subject : %s\n",a->subject );
    printf(" No of copies : %d\n",a->ncopies);
    printf("---------------------\n");
}
void displayAllBooks(Book * a,int nbooks){
    for (int i=0;i< (nbooks);i++){
        displayBook(a);
        a++;
    }
}
void nameSearch  (Book * a,char * name, int nbooks){
    int q = 1;
    for (int i=0;i<(nbooks) && q;i++){
        //locate the book
        if (strcmp(a->name, name)==0){
            printf("\n\tLocated Book\n");
            q = 0;
            displayBook(a);
        }
        a++;
    }
}
void authorSearch(Book * a, char * author, int nbooks){
    int q = 1;
    for (int i=0;i<(nbooks) && q;i++){
        //locate the book
        if (strcmp(a->author, author)==0){
            printf("\n\tLocated Book\n");
            q = 0;
            displayBook(a);
        }
        a++;
    }
}
void bookDelete  (Book * a, int index = -1){
    int i;
    if (index==(-1)){
        printf("Enter index to delete:");
        scanf("%d",&i);
        
    }
}
int main(){
    int i=0,n=0; //n is for number of books in the library(unique only)
    Book library[10];
    printf("----- Library Management Tool --------\n");
    Book b1;
    //insertBook(&b1,&n);
    //displayBook(&b1);
    Book * lb = library;
    //insertBook(lb, &n);
    //printf("One done\n");
    //insertBook(lb, &n);
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
                    nameSearch(lb,n);
                    break;
            case 3: //search by book author
                    authorSearch(lb,n);
                    break;
            case 4: //delete a book
                    bookDelete(lb,n);
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