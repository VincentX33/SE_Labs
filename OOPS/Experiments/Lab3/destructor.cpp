#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
//destructors
class Wolf{
  int age;
  float weight;
  char * name;
  public:
    Wolf(int,float,char * x);
    void display();
    ~Wolf();
};
Wolf::Wolf(int a,float w, char * x){
  age = a;
  weight = w;
  int n = strlen(x);
  name = new char[n+1];
  strcpy(name,x);
}
void Wolf::display(){
  cout<<"Wolf named "<<name<<", age "<<age<<", weighing "<<weight;
  cout<<" kgs is very dangerous\n";
} 
Wolf::~Wolf(){
  delete name;
  cout<<"Destroying object after main closed with destructor\n";
}
int main(){
  char * s = "Saruman";
  Wolf A(3,140.3,s);
  A.display();
  cout<<"Last line of main\n";
  return 0;
}