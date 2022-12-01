#include <iostream>
//heirarchical inheritance:3-4 inheriting from 1 base class
using namespace std;
//felidae
class felidae{
  protected:
  string name;
  int age;
  float weight;
  string genus;
  public:
    felidae();
    felidae(string, int, float, string);
    void details();
    void description(){
      cout<<"Hear us roar\n";
    }
};
felidae::felidae(){
  age = 0;
  name = "";
  weight = 0;
}
felidae::felidae(string n, int s, float f, string g){
  age = s;
  name = n;
  weight = f;
  genus = g;
}
void felidae::details(){
  cout<<
  "Name: "<<name<<"\n"
  "age: "<<age<<"\n"
  "weight: "<<weight<<"\n"
  "genus: "<<genus<<"\n";
}
class lion: public felidae{
  public:
    lion(){
      name = "";
      age = 0;
      weight = 0;
      genus = "";
    }
    lion(string n, int i, float f){
      name = n;
      age = i;
      weight = f;
      genus = "panthera leo";
    }
};

class tiger: public felidae{
  string stripeColor;
  public:
    tiger(string n, int a, float w, string c){
      name = n;
      age = a;
      weight = w;
      stripeColor = c;
    }
    tiger(){
      name = "";
      age = 0;
      weight = 0;
      genus = "panthera tigris";
      stripeColor = "";
    }
    void details(){
      cout<<
          "Name: "<<name<<"\n"
          "age: "<<age<<"\n"
          "weight:"<<weight<<"\n"
          "genus:"<<genus<<"\n"
          "stripeColor:"<<stripeColor<<"\n";
    }
};
class jaguar: public felidae{
  string color;
  public:
    jaguar(){
      name = "";
      age = 0;
      weight = 0;
      genus = "panthera onca";
      color = "";
    }
    jaguar(string n, int a, float w, string c){
      name = n;
      age = a;
      weight = w;
      color = c;
    } 
    void details(){
      cout<<
          "Name: "<<name<<"\n"
          "age: "<<age<<"\n"
          "weight:"<<weight<<"\n"
          "genus:"<<genus<<"\n"
          "color:"<<color<<"\n";
    }
};

int main(){
  jaguar a("amatham",3,8, "black");
  lion b("rocky", 4, 130.4);
  tiger c("manthan", 6,140.4, "black");
  cout<<"Three objects created using 3 derived classes of felidae\n";
  cout<<"Same inherited description f() called thrice by derived classes\n";
  a.description();
  b.description();
  c.description();
  cout<<"\nA.details:(a is jaguar object)\n\n";
  a.details();
  cout<<"\nB.details:(b is lion object)\n\n";
  b.details();
  cout<<"\nC.details:(c is tiger object)\n\n";
  c.details();
  return 0;
}