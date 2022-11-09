#include <iostream>
#include <cstring>
//implementing strings,concat and compare
using namespace std;
#define MAX 100
class NewString{
    char * str;
    int len;
    public:
        NewString();
        NewString(char * );
        NewString(int);
        NewString(NewString &);
        int length();
        friend NewString operator+(NewString &,NewString &);
        void operator=(const NewString & a);
        friend void operator>>(istream & ,NewString &);
        friend void operator<<(ostream & ,NewString &);
        friend bool operator>(const NewString&,const NewString&);
        friend bool operator<(const NewString&,const NewString&);
};
NewString::NewString(){
    str = new char[1];
    str[0] = '\0';
    len = 0;
}
NewString::NewString(NewString & a){
    len = a.len;
    delete str;
    str = new char[len+1];
    strcpy(str,a.str);
}
NewString::NewString(char *c){
    len = strlen(c);
    str = new char[len+1];
    strcpy(str,c);
}
NewString::NewString(int n){
    len = n;
    str = new char[n+1];
    str[0] = 'a';
    str[1] = '\0';
}
int NewString::length(){
    return strlen(str);
}
NewString operator+(NewString &a, NewString & b){
    int l = a.len + b.len;
    NewString x(l);
    x.len = l;
    strcpy(x.str,a.str);
    strcat(x.str,b.str);
    return x;
}
void NewString::operator=(const NewString & a){
    len = a.len;
    str = new char[len+1];
    strcpy(str,a.str);
}
void operator>>(istream & w1,NewString & w2){
    char * s = new char[MAX+1];
    w1>>s;
    int l = strlen(s);
    if (w2.length() != 0){
        delete []w2.str;
        w2.len = 0;
        w2.str = new char[l+1];
    }else{
        delete []w2.str;
        w2.str = new char[l+1];
    }
    w2.len = l;
    strcpy(w2.str,s);
    delete []s;
}
void operator<<(ostream & w3, NewString & w2){
    w3<<w2.str<<"\n";
}
bool operator>(const NewString & a, const NewString & b){
    //only checking length
    if (a.len>b.len)
        return true;
    return false;
}
bool operator<(const NewString & a, const NewString & b){
    //only checking length
    if (a.len<b.len)
        return true;
    return false;
}
int main(){
    NewString fname;
    NewString lname;
    cout<<"enter firstname:";
    cin>>fname;
    cout<<"enter lastname:";
    cin>>lname;
    cout<<fname;
    cout<<lname;
    NewString fullName;
    fullName = (fname +lname);
    cout<<fullName;
    if (fname > lname)
        cout<<"Firstname greater\n";
    else if (lname > fname)
        cout<<"Lastname greater\n";
    return 0;
}