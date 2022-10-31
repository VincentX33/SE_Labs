#include <iostream>
using namespace std;
//copy constructor
class Sample{
  int x;
  string d;
  public:
    Sample();
    Sample(Sample &);
    void display();
    void input();
};
Sample::Sample(){
  x = 0;
  d = "";
}
Sample::Sample(Sample & U){
  x = U.x;
  d = U.d;
}
void Sample::input(){
  cout<<"Enter x:";
  cin>>x;
  cin.ignore();
  cout<<"Enter textstring:";
  getline(cin,d);
}
void Sample::display(){
  cout<<"X   :"<<x<<"\nText:"<<d<<"\n";
}
int main(){
  Sample X;
  X.input();
  cout<<"Copying contents into another object...\n";
  Sample Y(X);
  cout<<"Displaying second object\n";
  Y.display();
  return 0;
}