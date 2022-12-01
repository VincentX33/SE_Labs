#include <iostream>
//constructors in derived classes
using namespace std;
class Sample1{
  string text;
  int num;
  public:
    Sample1(){
      text = "";
      num = 0;
    }Sample1(string a, int n){
      cout<<"Sample1 constructor\n";
      text = a;
      num = n;
    }
    void showSample1(){
      cout<<"Text:"<<text<<"\t Num: "<<num<<"\n";
    }
};
class Sample2{
  string name;
  public:
    Sample2(){
      name = "";
    }Sample2(string a){
      cout<<"Sample2 constructor\n";
      name = a;
    }
    void showSample2(){
      cout<<"Name:"<<name<<"\n";
    }
};
class Sample3:public Sample1, public Sample2{
  float x;
  float y;
  public:
    Sample3(){
      x = 0;
      y = 0;
    }
    Sample3(string q, int w,string c, float a, float b): Sample1(q,w), Sample2(c){
      cout<<"Sample3 constructor\n";
      x = a;
      y = b;
    }
    void showSample3(){
      cout<<"X:"<<x<<"\t y"<<y<<"\n";
    }

};

int main(){
  Sample3 t("a nice rainy day", 5, "Jason",6.6, 4.5);
  t.showSample1();
  t.showSample2();
  t.showSample3();
  return 0;
}