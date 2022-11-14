#include <iostream>
using namespace std;
/*
Write a C++ program to create a vector of ‘n’ elements (allocate the memory
dynamically) and then multiply a scalar value with each element of a vector. Also show the result of addition of two vectors.
*/

class vector{
  int * v; // array of v elements
  int n; //size of vector currently
  public :
    vector();
    vector(int);
    vector(int, int);
    vector(int, int *);
    friend vector operator*(vector, int);
    friend vector operator*(int, vector);
    friend vector operator+(vector, vector);
    friend void operator>>(istream &, vector &);
    friend void operator<<(ostream &, vector &);
};
vector :: vector(){
  n = 1;
  v = new int[1];
  v[0] = 0;
}
vector::vector(int c){
  n = c;
  v = new int[c];
  for (int i = 0; i<c;i++)
    v[i] = 0;
}
vector::vector(int c, int val){
  n = c;
  v = new int[c];
  for (int i = 0; i<c;i++)
    v[i] = val;
}
vector::vector(int c, int * arr){
  n = c;
  v = new int[c];
  for (int i = 0; i<c;i++)
    v[i] = arr[i];
}
vector operator*(vector a, int m){
  int x = a.n;
  vector newVect(x);
  int i;
  for (i = 0;i<x;i++){
    newVect.v[i] = m*(a.v[i]);
  }
  return newVect;
}
vector operator*(int m,vector a){
  int x = a.n;
  vector newVect(x);
  int i;
  for (i = 0;i<x;i++){
    newVect.v[i] = m*(a.v[i]);
  }
  return newVect;
}
vector operator+(vector a, vector b){
  int n1, n2, c;
  if (a.n < b.n){
    n1 = b.n; //bigger in n1
    n2 = a.n;
    c = 2; //2 means b bigger
  }else{
    n1 = a.n;
    n2 = b.n;
    c = 1; // a bigger
  }
  vector newVect(n1);
  int i;
  //for the first n2 elements, add
  for (i = 0; i < n2; i++)
    newVect.v[i] = a.v[i] + b.v[i];
  
  if (c==1)
    for (i; i< n2;i++){
      newVect.v[i] = a.v[i];
    }
  else if (c==2)
    for (i; i< n1;i++){
      newVect.v[i] = b.v[i];
    }
  return newVect;
}
void operator<<(ostream & d1, vector & w){
  int i = 0;
  d1<<"[ ";
  for (i; i < w.n; i++)
    d1<<w.v[i]<<" , ";
  d1<<"\b\b]\n";
}
void operator>>(istream & d2, vector & w){
  int i = 0;
  for (i;i<w.n;i++)
    d2>>w.v[i];
}
int main(){
  int w[10] = {1,2,3,4,5,6,8};
  vector a(5);
  vector b(7, w);
  cout<<"Enter A:";
  cin>>a;
  cout<<"A:\n";
  cout<<a;
  cout<<"B:\n";
  cout<<b;
  cout<<"A+b:\n";
  vector c = a+b;
  cout<<c;
  cout<<"d = a*6\n";
  vector d = a*6;
  cout<<d;
  cout<<"e = 10*b\n";
  vector e = 10*b;
  cout<<e;
  return 0;
}