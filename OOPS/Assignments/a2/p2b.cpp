#include <iostream>

using namespace std;
class DomesticUser{
	int units;
	string name;
	float charges;
	public: DomesticUser();
					DomesticUser(int, string);
					void calcBiLL();
					void printBill();
};
DomesticUser::DomesticUser(){
	cin.ignore();
	cout<<"Enter name:";
	getline(cin,name);
	cout<<"Enter units used:";
	cin>>units;
	charges = 0;
	calcBiLL();
	printBill();
}
DomesticUser :: DomesticUser(int a,string n){
	units = a;
	name = n;
	charges = 0;
	calcBiLL();
	printBill();
}
void DomesticUser :: printBill(){
	cout<<"Name: "<<name<<"  Charges :"<<charges<<"\n";
}
void DomesticUser ::calcBiLL(){
	if (units < 100){
		charges = units*0.60;// in  no
	}else {
		int x = units;
		if (x>100){
			charges = charges + (100*0.60); //60 rs
			x = x-100;
		}
		if (x>200){
			charges += (200*0.80); //+ 160 rs 
			x = x-200;
		}else{
			charges += (x*0.80);
			x = 0;
		}
		charges += (x*0.90); //whatever is left
		if (charges < 50)
			charges = 50;
		if (charges > 300)
			charges = charges * 1.15;
	}

}
int main(){
	cout<<"Enter number of customers who bill to generate:";
	int n,a;
	string na;
	cin>>n;
	while (n--){
		DomesticUser m;
	}
	return 0;
}
