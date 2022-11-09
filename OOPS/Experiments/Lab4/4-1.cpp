#include <iostream>

using namespace std;

class Complex{
    float real;
    float imag;
    public:
        Complex();
        Complex(float,float);
        void display();
        void getData();
        Complex operator++(); //prefix overloads
        Complex operator--();
        //postfix overloads
        Complex operator++(int);
        Complex operator--(int);
};
Complex ::Complex(){
    real = 0;
    imag = 0;
}
Complex :: Complex(float c, float d){
    real = c;
    imag = d;
}
void Complex::getData(){
 cout<<"Enter real and imaginary:";
 cin>>real>>imag;   
}
void Complex::display(){
    cout<<real<<" + "<<imag<<"i\n";
}
Complex Complex::operator++(){
    real++;
    imag++;
    Complex b(real,imag);
    return b;
}
Complex Complex::operator--(){
    real--;
    imag--;
    Complex a(real,imag);
    return a;
}
Complex Complex::operator++(int){
    Complex temp(*this);
    ++(*this);
    return temp;
}
Complex Complex::operator--(int){
    Complex temp(*this);
    --(*this);
    return temp;
}
int main(){
    Complex a;
    Complex b(1.0, 2.0);
    a.getData();
    cout<<"\nPrefix output:\n";
    (++a).display(); 
    cout<<"\nAfter prefix\n";
    a.display();
    cout<<"\nPostfix display:\n";
    (a++).display();
    cout<<"\nAfter postfix\n";
    //b = a+b;
    // a++;
    a.display();
    return 0;
}