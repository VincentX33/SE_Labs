#include <bits/stdc++.h>
//parameterized constructors
using namespace std;
class Student{
  string name;
  int age;
  float cgpa;
  public :    
    Student();
    Student(string,int,float);
    void display();
    void getinfo();
};
Student::Student(){
  name = "";
  age = 0;
  cgpa = 0;
}
Student::Student(string n,int a = 0,float f = 0){
  name = n;
  age = a;
  cgpa = f;
}
void Student::display(){
  cout<<"Student Details\n";
  cout<<"Name : "<<name<<"\n";
  cout<<"Age : "<<age<<"\n";
  cout<<"cgpa : "<<cgpa<<"\n";
}
void Student::getinfo(){
  cout<<"Enter Student Details\n";
  cout<<"Name : "<<"\n";
  getline(cin, name);
  cout<<"Age : "<<"\n";
  cin>>age;
  cout<<"cgpa : "<<"\n";
  cin>>cgpa;
}
int main(){
  Student X;
  X.getinfo(); //calling member function
  Student Y("Joshua Higgs", 19, 9.99); //parameterized constructor
  X.display();
  Y.display();
  return 0;
}