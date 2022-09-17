#include <iostream>
//#include <bits/stdc++.h>
#include <io.h>

using namespace std;
const int MAX = 20; 
class Book {
    string name;
    string author;
    string subject;
    int ncopies;
    public: void acceptBookDetails();
            void acceptBookDetails(string,string,string,int);
            void displayBookDetails();
            int nameExists();
            int authorExists();
            int subjectExists();
};
void Book::acceptBookDetails(){
    cout<<"Enter name of book:";
    getline(name, MAX);
    cout<<"";
}
void Book::acceptBookDetails(){
    
}


//array functions
/*
display all books
namesearch
authorsearch
subjectSearch
bookdelete
*/
int main(){
    //implement library management system
    int delIn,i;
    char c;
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


    return 0;
}