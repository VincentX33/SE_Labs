#include <iostream>
#include <iomanip>
using namespace std;
class DM;

class DB{
	float feet;
	float inch;
	public:	DB(float,float);
					DB(DB&);
					void display();
					friend DB sum(DB&, DM&);
					friend DM sum(DM&,DB&);
};
DB::DB(float x = 0, float y = 0){
	feet = x;
	inch = y;
}
DB::DB(DB & q){
	feet = q.feet;
	inch = q.inch;
}
void DB::display(){
	cout<<"Feet: "<<feet<<setw(20)<<"\tInches :"<<inch<<"\n";
}
class DM{
	float meter;
	float cm;
	public:	DM(float,float);
					DM(DM&);
					void display();
					friend DB sum(DB&, DM&);
					friend DM sum(DM&,DB&);
};
DM::DM(float x = 0, float y = 0){
	meter = x;
	cm = y;
}
DM::DM(DM & q){
	meter = q.meter;
	cm = q.cm;
}
void DM::display(){
	cout<<"Metre:"<<meter<<setw(20)<<"\tCentimetre :"<<cm<<"\n";
}
DB sum(DB& X, DM& Y){
	DB Sum(0,0);
  //logic to add both
	float a, b;
	a = Y.meter*100 + Y.cm; //cms of Y
	b = X.feet * 12 + X.inch; //inches of X	
	a = a/2.54; //convert to inches
	b = b+a; //total inches of both
	//a shud hold feet and b inches
	a = 0;	
	while (b>12){
		a++;
		b-=12;
	}
	Sum.feet = a;
	Sum.inch = b;
	return Sum;
}

DM sum(DM& Y,DB& X){
	DM Sum(0,0);
  //logic to add both
	float a,b,m;
	a = Y.meter*100 + Y.cm; //cms of a
	b = X.feet*12 + X.inch;
	b = b*2.54; //b has centimeters of X
	b = b + Y.cm;
	m = Y.meter;
	while (b>100){
		m++;
		b = b-100;
	}
	Sum.meter = m;
	Sum.cm = b;
	return Sum;
}


int main(){	
	DM a(1, 1);
	DB b(1,11);
	cout<<"A:\n";
	a.display();
	cout<<"B:\n";
	b.display();	
	DB sumb; 
	cout<<"In Feet, inches:\n";
	sumb = sum(b,a);
	sumb.display();
	DM summ;	
	summ = sum(a,b);
	cout<<"In metre,cm:\n";
	summ.display();
	return 0;
}
