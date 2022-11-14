#include <iostream>

using namespace std;
class Sample{
    int x,y;
public: 
    Sample(int a, int b){x=a;y=b;}
    void display(){
        cout<<"x:"<<x<<"  y:"<<y<<"\n";
    }
    friend Sample operator*(Sample &, Sample &);
    friend Sample operator+(Sample &,Sample &);
    friend Sample operator-(Sample &, Sample &);
    friend Sample operator/(Sample &, Sample &);
};
Sample operator*(Sample & a, Sample &b){
    return Sample(a.x*b.x, a.y*b.y);
}
Sample operator+(Sample & a, Sample &b){
    int q = a.x+b.x;
    int w =  a.y+b.y;
    return Sample(q,w);
}
Sample operator-(Sample & a, Sample &b){
    Sample m(a.x-b.x, a.y-b.y);
    return m;
}
Sample operator/(Sample & a, Sample &b){
    if (b.x != 0 && b.y!=0){
        Sample m(a.x/b.x, a.y/b.y);
        return m;
    }
    Sample s(0,0);
    return s;
}

int main(){
    Sample b(1,2);
    Sample a(5,3);
    cout<<"A:\n";
    a.display();
    cout<<"B:\n";
    b.display();
    Sample c = a+b;
    cout<<"C:a+b\n";
    c.display();
    Sample d = a-b;
    cout<<"D:a-b\n";
    d.display();
    Sample e = a*b;
    cout<<"E:a*b\n";
    e.display();
    Sample f = a/b;
    cout<<"F:a/b\n";
    f.display();

    return 0;
}