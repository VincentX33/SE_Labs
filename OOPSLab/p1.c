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
    char c;
    if (*nbooks != 0){
        //printf("Trigger\n");
        a++;//next empty position
        c = getchar();
    }
    char lname[30],lauthor[30],lsub[25];
    lname[0] = 0;
    int lcopies;
    printf("Enter book name:");
    fgets(lname, 25, stdin);
    lname[strlen(lname)-1] = '\0';
    // gets(lname); //this takes proper name but error for array
    // getchar();
    strcpy(a->name, lname);
    if (lname[0]==0)
        printf("\nError\n");
    printf("Enter author name:");
    fgets(lauthor,50,stdin);
    lauthor[strlen(lauthor)-1] = '\0';
    // gets(lauthor);
    // getchar();
    strcpy(a->author, lauthor);
    printf("Enter subject:");
    fgets(lsub,50,stdin);
    lsub[strlen(lsub)-1] = '\0';
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
}
void displayAllBooks(Book * a,int nbooks){
    printf("All library books:\n");
    for (int i=0;i< (nbooks);i++){
        displayBook(a);
        a++;
    }
}
void nameSearch(Book * a,char * name, int nbooks){
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
            printf("\n---Located Book\n");
            q = 0;
            displayBook(a);
        }else{
            //printf("Author=%s, SearchAuthor=%s\n",a->author,author);
        }
        a++;
    }
    if (q==1){
        printf("Book not found\n");
    }
        
}
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
int main(){
    int i=0,n=0; //n is for number of books in the library(unique only)
    Book library[10];
    printf("----- Library Management Tool --------\n");
    Book b1;
    //insertBook(&b1,&n);
    //displayBook(&b1);
    Book * lb = library;
    insertBook(lb, &n);
    insertBook(lb, &n);
    insertBook(lb, &n);
    // insertBook(lb, &n);
    // insertBook(lb, &n);
    //nameSearch(lb,"vincent",n);
    authorSearch(lb,"dsouza",n);
    bookDelete(library,1,&n);
    displayAllBooks(library,n);
    /*
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
                    nameSearch(lb,"vincent",n);
                    break;
            case 3: //search by book author
                    authorSearch(lb,"dsouza",n);
                    break;
            case 4: //delete a book
                    bookDelete(lb,2,&n);
                    break;
            case 5: //dislayAllbooks
                    displayAllBooks(library,n);
                    break;
            case 6: break;
            default: printf("Choose an option from (1-6):\n");
        }
    }while (i!=6);
    */
    return 0;

}