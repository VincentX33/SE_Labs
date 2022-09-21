#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 20

//declare library type
struct Library{
  int acc_number;
  char title[30];
  char author[30];
  int price;
  char issue_status; //'y' if issued else 'n'
};

//function to take input for 1 book
void addBook(struct Library * l,int * nbooks){
  if (*nbooks == 0){
    //empty library
    //ask whether you wish to add books
    int c = 0;
    int j,k;
    printf("Library is empty\n");
    printf("Do you wish to add books ?\n");
    printf("1 to add | 0 to not add");
    scanf("%d",&c);
    if (c){
      char s[30];

      printf("Enter accession number:");
      scanf("%d",&j);
      l->acc_number = j;
      printf("Enter book title: ");
      fgets(s,30,stdin);
      //have to check whether the compiler adds \n
      //fix issue if present
      strcpy(l->title,s);

      printf("Enter author name:");
      fgets(s,30,stdin);
      strcpy(l->author,s);
      printf("Enter price");
      scanf("%d", &k);
      l->price = k;

      //set flag to not issued
      l->issue_status = 'n';
    }
  }
}

//function to display 1 book
void displayBook(struct Library * l){
  printf("-----\n ");
  printf("Title           : %s\n ",l->title);
  printf("Accession Number: %d\n ",l->acc_number);
  printf("Author          : %s\n ",l->author);
  printf("Price           : %d\n",l->price);
  printf("Currently ");
  (l->issue_status == 'n')?printf("not issued\n"):printf("issued\n ");
}

//function to display all books
void displayLibrary(struct Library * l, int nbooks){
  int i = 0;
  for (i; i<nbooks; i++){
    displayBook(l);
    l++;
  }
}
//list author's books
void authorInventory(struct Library * l, char * authorName, int nbooks){
      int q = 0;
      //printf("nbooks=%d\n",nbooks);
  	  int i;
      //try by removing q
      for (i=0;i<(nbooks);i++){
          //locate the book
          //printf("Author = %s",a->author);
          if (strcmp(l->author, authorName)==0){
              if (q==0)
                  printf("\n\tLocated Book\n");
              q++;
              displayBook(l);
          }
          l++;
      }
      if (q==0){
          printf("Book not found\n");
      }
      sleep(0.5);
}

//function to issue count of books in library
int libraryCount(int * nbooks){
  //can actually just return the global for now
  //becos we are using arrays for now and
  //there is no way to tell how many books are taken
  return *nbooks;
}
//return of a book
void returnBook(struct Library * l,int acc_number){

}

//issue a book
void issueBook(struct Library * l, int acc_number){

}
//extra functions
int bookExists(struct Library * l, int nbooks, char * title){
  int k = 0;
  int i = 0;
  for (i; i<nbooks && !k;i++){
    if (strcmp(l->title,title)==0)
      k++;
    l++;
  }
  return k;
}
int main(){
  //declarations
  struct Library lib[MAX]; //library with MAX books
  struct Library * ll = lib;
  int n = 0; //no of books in library
  int c;
  printf("----- Library Management Tool --------\n");
  do {
    printf("Enter:\n");
    printf("1 to Add book info\n ");
    printf("2 to Display book info\n ");
    printf("3 to list books by an author\n ");
    printf("4 to Issue a book\n ");
    printf("5 to Return a book\n ");
    printf("6 to Count no of books in library\n ");
    printf("7 to Exit\n ");
    printf("\t:");
    scanf("%d",&c);
    switch (c) {
      case 1: //add book info
              addBook(ll,&n);
              break;
      case 2: //display book info
              break;
      case 3: //list all books of given author
              break;
      case 4: //issue a book
              break;
      case 5: //return a book
              break;
      case 6: //list count of books in library
              break;
      case 7: exit(1);
              break;
      default:
              printf("Unexpected option: choose between 1-7\n");
    }

  }while (c!=7);
  //menu driven program
  return 0;
}
