#include <iostream>

using namespace std;

class Sample{
	int age;
	int marks;
	public: 
	  Sample();
	  Sample(int,int);
		void getInfo();
		inline void printDetails();
		friend void birthday(Sample&	);
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
void birthday(Sample &a){
	cout<<" Happy Birthday\n";
	a.age += 1;
}
void Sample::getInfo(){
	cout<<"Enter age:";
	cin>>age;
	cout<<"Enter marks:";
	cin>>marks;
}

int main(){
	Sample a(10,20);
	a.printDetails();
	birthday(a);
	a.printDetails();
}
