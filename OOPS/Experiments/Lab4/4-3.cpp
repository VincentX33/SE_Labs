#include <iostream>

using namespace std;
//cin/cout insertion
class Sample{
    int x,y;
public:
    Sample(){
        x = 0;
        y = 0;
    }
    friend void operator>>(istream & w1,Sample & w2);
    friend void operator<<(ostream & w3,Sample & w2);
};

void operator>>(istream & w1, Sample & w2){
    w1>>w2.x;
    w1>>w2.y;
}
void operator<<(ostream & w3, Sample & w2){
    w3<<w2.x<<" "<<w2.y<<"\n";
}
int main(){
    Sample a;
    cout<<"Input:\n";
    cin>>a;
    cout<<"Output:\n";
    cout<<a;
    return 0;
}