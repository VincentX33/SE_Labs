#include <iostream>

using namespace std;
void swap(int & a,int & b){
	int t;
	t = a;
	a = b;
	b = t;
}

int main(){
	int a = 1,b= 3;
	cout<<"\nBefore swap\n";
	cout<<"A = "<<a<<" B = "<<b<<"\n";
	swap(a,b);
	cout<<"\nAfter swap\n\n";
	cout<<"A = "<<a<<" B = "<<b<<"\n";
	return 0;
}
