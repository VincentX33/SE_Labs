#include <iostream>

using namespace std;
class Dog;

class Cat{
	int age;
	string name;
	public: 
	  Cat();
	  Cat(int,string);
		void getInfo();
		inline void printDetails();
		friend void leader(Cat&, Dog&);
};
Cat :: Cat(){
	age = 0;
	name = "Nameless Cat";
}
Cat :: Cat(int x, string y){
	age = x;
	name = y;
}
void Cat::printDetails(){
 cout<<"Name:"<<name<<"\nAge: "<<age<<"\n"; 
}
void Cat::getInfo(){
	cout<<"Cat Details\n----\t----\nEnter age:";
	cin>>age;
	cin.ignore();
	cout<<"Enter name:";
	getline(cin,name);
}
class Dog{
	int age;
	string name;
	public: 
	  Dog();
	  Dog(int,string);
		void getInfo();
		inline void printDetails();
		friend void leader(Cat&, Dog&);
};
Dog :: Dog(){
	age = 0;
	name = "Nameless Cat";
}
Dog :: Dog(int x, string y){
	age = x;
	name = y;
}
void Dog::printDetails(){
 cout<<"Name:"<<name<<"\nAge: "<<age<<"\n"; 
}
void Dog::getInfo(){
	cout<<"Dog Details\n-----\t-----\nEnter age:";
	cin>>age;
	cin.ignore();
	cout<<"Enter name:";
	getline(cin,name);
}

void leader(Cat &a, Dog & b){
	//compare ages of cat and dog
	if (a.age > b.age){
		cout<<"The cat named "<<a.name<<" is older and thus chosen to lead\n";
	}else if (a.age < b.age){
		cout<<"The dog named "<<b.name<<" is older and thus chosen to lead\n";
	}else {
		cout<<"Both are the same age\nChoose leader via toss\n";
	}
}

int main(){
	Cat a;
	Dog b;
	a.getInfo();
	b.getInfo();
	leader(a,b);
}
