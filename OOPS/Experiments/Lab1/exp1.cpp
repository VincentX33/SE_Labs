#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <limits>
#include <ios>
// #include <unistd.h>
#include <stdio.h>
using namespace std;

const int MAXSIZE = 50;
const int LIBSIZE = 10;
const int MAX = 20; 
const int ACCESS_1 = 1000;
class Book {
  char * name;
  char * author;
  char * subject;
  int ncopies;
  int accession;
  public: Book();
    void acceptBookDetails(int &);
    void acceptBookDetails(int &,char *,char *,char *,int);
    void displayBookDetails();
    int nameExists(char *);
    int authorExists(char *);
    int subjectExists(char *);
    int accession_val();
    void deleteBook();
};
Book :: Book(){
  name = NULL;
  author = NULL;
  subject = NULL;
  ncopies = 0;
  accession = 0;
}
int Book::accession_val(){
  return accession;
}
void Book::acceptBookDetails(int &k){
  name = new char[MAXSIZE];
  subject = new char[MAXSIZE];
  author = new char[MAXSIZE];
  cin.ignore(10,'\n');
  cout<<"Enter name of book:";
  cin.getline(name,MAXSIZE,'\n');
  cin.ignore(10,'\n');	
  cout<<"Enter author name:";
  cin.getline(author,MAXSIZE,'\n');
  cin.ignore(10,'\n');
  cout<<"Enter subject:";
  cin.getline(subject,MAXSIZE,'\n');
  cin.ignore(10,'\n');
  cout<<"No of copies: ";
  cin>>ncopies;
  accession = k++;
}
void Book::acceptBookDetails(int &k,char * bookName, char * authorName, char * subj, int ncopy){
  strcpy(name,bookName);
  strcpy(author,authorName);
  strcpy(subject,subj);
  ncopies = ncopy;
  accession = k;
  k++;
}

void Book::displayBookDetails(){
cout<<"===================================\n ";
cout<<setw(16)<<"Book name : "<<name<<"\n ";
cout<<setw(16)<<"Author : "<<author<<"\n ";
cout<<setw(16)<<"Subject : "<<subject<<"\n ";
cout<<setw(16)<<"No of Copies: "<<ncopies<<"\n ";
cout<<setw(16)<<"Accession no : "<<accession<<"\n==================================\n";
}

int Book::nameExists(char * nM){
  if (name == NULL)return 0;
  if (strcmp(name,nM)==0)
    return 1;
  return 0;
}
int Book::authorExists(char * auTH){
  if (author == NULL)return 0;
  if (strcmp(author,auTH)==0)
    return 1;
  return 0;
}
int Book::subjectExists(char * subJ){
  if (subject == NULL)return 0;
  if (strcmp(subject,subJ)==0)
    return 1;
  return 0;
}
void Book::deleteBook(){
  accession = 0;
  ncopies = 0;
  name = author = subject = NULL;
}
//array functions
void displayAllBooks(Book * a, int n, int access){
  cout<<"---------Library containing "<<n<<" books-----------\n";
  int i = 0, j = 0;
  while ((i < (access-ACCESS_1)) && (j < n)){
      if (a->accession_val()!=0){
      a->displayBookDetails();
      j++;
    }
    a++;
    i++;
  }
}
void authorSearch(Book * a, char * Author,int access){
	//sleep(1);
  int q = 0,i;
  for (i=0;i<(access-ACCESS_1);i++,a++){
    if (a->authorExists(Author)){
      if (q==0)
        cout<<"\n\tLocated Book/s by given author\n";
      q++;
      a->displayBookDetails();
    }
  }
  if (q==0)
    cout<<"No book by author in library\n";
  //sleep(0.5);
}
void nameSearch(Book * a, char * Name,int access){
  //sleep(1);
  int q = 1,i;
  for (i=0;i<(access-ACCESS_1) && q;i++,a++){
    if (a->nameExists(Name)){
      cout<<"\n\tLocated Book\n";
      q = 0;
      a->displayBookDetails();
    }
  }
  if (q==1)
    cout<<"No book under given title\nCheck for typos\n";
  //sleep(0.5);
}
void subjectSearch(Book * a, char * Subject,int access){
  //sleep(1);
  int q = 0,i;
  for (i=0;i<(access-ACCESS_1);i++,a++){
    if (a->subjectExists(Subject)){
      if (!q)
        cout<<"\n\tLocated Book|s for given subject\n";
      q++;
      a->displayBookDetails();
    }
  }
  if (q==0)
      cout<<"No book for given subject\n";
  //sleep(0.5);
}
void insertInLib(Book * a, int * n, int & k){
  int i = 0;
  if (*n >= LIBSIZE){
    cout<<"Shelves full! Books cannot be added\n";
    return;
  }
  while (i < *n){
    if (a->accession_val()==0)
      break;
    a++;
    i++;
  }
  a->acceptBookDetails(k);
  *n = *n + 1;
}
void deleteFromLib(Book * a, int * n, int acc){
  int i = 0;
  if (*n == 0){
    cout<<"Shelves empty! Nothing to delete\n";
    return;
  }
  while (i < *n){
    if (a->accession_val()==acc){
      a->deleteBook();
      *n = *n - 1;
      break;
    }
    a++;
    i++;
  }
  
} 
int main(){
  //implement library management system
  int n = 0,i, acc = ACCESS_1,delAcc;
  char c, s[MAXSIZE];
  Book b,a[LIBSIZE],*library = a;
  cout<<"----- Library Management Tool --------\n";
  do {
  //sleep(0.6);
  cout<<"Enter\n 1 to insert book record\n ";
  cout<<"2 to Search based on book name\n ";
  cout<<"3 to Search based on author name\n ";
  cout<<"4 to Delete a book from the record\n ";
  cout<<"5 to Display all book records\n ";
  cout<<"6 to Get subject inventory\n ";
  cout<<"7 to Exit the program\n\t:";
  scanf("%d",&i);
  switch(i){  
  case 1: 
    insertInLib(library,&n,acc);
    break;
  case 2: //search by book name
    cin.ignore(10,'\n');
    cout<<"Enter name of book:";
    cin.getline(s,MAXSIZE);
    nameSearch(library, s, acc);
    break;
  case 3: //search by book author
    cin.ignore(10,'\n');
    cout<<"Enter name of author:";
    cin.getline(s,MAXSIZE);
    authorSearch(library, s, acc);
    break;
  case 4: //delete a book
    cout<<"Accession Number of book to remove from library:";
    scanf("%d",&delAcc);
    deleteFromLib(library,&n,delAcc);
    break;
  case 5: //dislayAllbooks
    displayAllBooks(library,n,acc);
    break;
  case 6: //subject inventory
    cin.ignore(10,'\n');
    cout<<"Enter subject:";
    cin.getline(s,MAXSIZE);
    subjectSearch(library, s, acc);
  case 7: break;
  default: 
    cout<<"Choose an option from (1-7):\n";
  }
  }while (i!=7);  
  return 0;
}
