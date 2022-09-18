#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <limits>
#include <ios>
//#include <unistd.h>
const int MAXSIZE = 50;
using namespace std;
const int MAX = 20; 
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
};
Book :: Book(){
    name = NULL;
    author = NULL;
    subject = NULL;
}
void Book::acceptBookDetails(int &k){
    name = new char[MAXSIZE];
	subject = new char[MAXSIZE];
	author = new char[MAXSIZE];
    cout<<"Enter name of book:";
	cin.getline(name,MAXSIZE,'\n');
	cout<<"Enter author name:";
    cin.getline(author,MAXSIZE,'\n');
	cout<<"Enter subject:";
	cin.getline(subject,MAXSIZE,'\n');
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
	if (strcmp(name,nM)==0)
		return 1;
	return 0;
}
int Book::authorExists(char * auTH){
	if (strcmp(author,auTH)==0)
		return 1;
	return 0;
}
int Book::subjectExists(char * subJ){
	if (strcmp(subject,subJ)==0)
		return 1;
	return 0;
}

//array functions
void displayAllBooks(Book * a, int n){
	int i = 0;
	while (i++ < n){
		(*a).displayBookDetails();
		a++;
	}
}
/*
void nameSearch(){}
authorsearch
subjectSearch
bookdelete
*/
int main(){
    //implement library management system
    int delIn,i;
    char c;
	Book b;		
	int acc = 1000;
    b.acceptBookDetails(acc);
    b.displayBookDetails();
    if (b.authorExists("dsouza")){
        if (b.nameExists("Dsouza")){
            if (b.subjectExists("CS")){
                printf("Works");
            }
        }
    }
	// (a[0]).acceptBookDetails(acc);
	// (a[1]).acceptBookDetails(acc);
	// (a[0]).displayBookDetails(); 
	// (a[1]).displayBookDetails(); 
    
	/*
	cout<<"----- Library Management Tool --------\n";
    do {
        sleep(0.6);
        cout<<"Enter\n 1 to insert book record\n 2 to Search based on book name\n ";
        cout<<"3 to Search based on author name\n 4 to Delete a book from the record\n ";
        cout<<"5 to Display all book records\n ";
        cout<<"6 to Get subject inventory\n ";
        cout<<"7 to Exit the program\n\t:";
        scanf("%d",&i);
        switch(i){
            case 1: //insertion function
                    break;
            case 2: //search by book name
                    cout<<"Enter name of book:";
                    break;
            case 3: //search by book author
                    cout<<"Enter name of author:";
                    break;
            case 4: //delete a book
                    cout<<"Delete nth book for n(+ve n):";
                    scanf("%d",&delIn);
                    break;
            case 5: //dislayAllbooks
                    break;
            case 6: //subject inventory
                    cout<<"Enter subject:";
                    break;
            case 7: break;
            default: cout<<"Choose an option from (1-7):\n";
        }
    }while (i!=7);
	*/

    return 0;
}
