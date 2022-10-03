#include <iostream>


// to implement copy constructors, parameterized constructor and destructor

class Sample{
	string name;
	int * a;
	public:
		Sample();
		Sample(string);
		Sample(Sample &,int);
		~Sample();	
		printInfo();
};

Sample :: Sample(){
	cout<<"Enter name: ";
	getline(cin,name);
	cout<<"Enter number :";
	int n;
	cin>>n;
	a = new int;
	a = *n;
}

Sample :: Sample(string nm,int n){
	name = nm;
	a = new int;
	*a = n;
}


