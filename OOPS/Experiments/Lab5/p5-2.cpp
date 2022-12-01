#include<iostream>
#include<iomanip>
//hybrid: virtual base classes
using namespace std;
class Student
{
  protected:
  string name;
  int roll;
  public:
  void getStudentInfo();
};

void Student::getStudentInfo(){
    cout<<"Enter name: ";
    getline(cin, name);
    cout<<"Enter roll number: ";
    cin>>roll;
}

class test : virtual public Student
{
protected:
    float mark1, mark2; //test scores
    float maxMarks;
public:
    void getMarks(){
    cout<<"Enter marks in subject1: ";
    cin>>mark1;
    cout<<"Enter marks in subject2: ";
    cin>>mark2;
    cout<<"Enter max marks per exam:";
    cin>>maxMarks;
    }
};

class sports : virtual public Student
{
protected:
  int sptmks;
public:
    void getSportsMarks();
};

void sports::getSportsMarks()
{
  cout<<"Sportsmarks attained:";
  cin>>sptmks;
}

class marksheet : public sports, public test
{
  int finalTotal;
  float percentage ;
  public:
    void marksheetGeneration(){
      finalTotal = (mark1 + mark2 + sptmks);
      percentage = (float(finalTotal)/(maxMarks*2)) * 100; //assuming 2 40 mark papers
      
    }
    void marksheetDisplay(){
      cout<<"----------Marksheet----:\n";
      cout<<"Name: "<<name<<"\n";
      cout<<"Roll no: "<<roll<<"\n";
      cout<<"Subject 1:"<<mark1<<"\t | Subject 2:"<<mark2<<"\n";
      cout<<"Sports marks obtained: "<<sptmks<<"\n";
      cout<<"Final Score: " <<finalTotal<< "\n";
      cout<<setw(30)<<"Percentage:"<<percentage<<"\n";
    }
};

int main()
{
    marksheet s;
    s.getStudentInfo();
    s.getMarks();
    s.getSportsMarks();
    s.marksheetGeneration();
    s.marksheetDisplay();
    return 0;
}