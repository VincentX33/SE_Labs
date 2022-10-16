#include <iostream>
#include <iomanip>
using namespace std;

class Pair{
int x;
int y;
public: 
  void getpair(int a, int b){
  	x=a ;  y=b;
  };
  
  void putpair(){
    cout<<"X= "<<x<<"\tY= "<<y<<"\n";  
  }     
};

int main(){
  int a,b, n,i;
  cout<<"Enter size of object array to be created: ";
  cin>>n;
  Pair * start = new Pair[n];
  Pair * c = start;
  for (i = 0; i < n; i++,c++){
    cout<<"Enter two ints: ";
    cin>>a>>b;
    c->getpair(a,b);
  }
	c = start;
	for (i = 0; i < n; i++,c++)
  	c->putpair();
	delete []start;
	return 0;
}
