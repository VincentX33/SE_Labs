#include <iostream>

using namespace std;

class Sample{
	int age;
	int marks;
	public: 
	  Sample();
	  Sample(int,int);
		void getInfo();
		void getInfo(int, int);
		inline void printDetails();
};
Sample :: Sample(){
	age = 0;
	marks = 0;
}
Sample :: Sample(int x, int y){
	age = x;
	marks = y;
}
void Sample::printDetails(){
 cout<<" Age: "<<age<<"\n Marks: "<<marks<<"\n"; 
}

void Sample::getInfo(){
	cout<<"Enter age:";
	cin>>age;
	cout<<"Enter marks:";
	cin>>marks;
}
void Sample :: getInfo(int a, int b = 0){
	age = a;
	marks = b;
}
int main(){
	Sample a,b;
	a.getInfo();
	a.printDetails();
	b.getInfo(19,12);
	b.printDetails();	
}
