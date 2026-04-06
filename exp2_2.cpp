#include<iostream>
using namespace std;
class student
{
  private:
  int roll;
  string name;
  float m1,m2,m3;
  public:
  student()
  {
    roll=0;
    name="default";
    m1=m2=m3=50;
  }
  student(int r,string n,float a,float b,float c)
  {
     roll=r;
     name=n;
     m1=a;
     m2=b;
     m3=c;
  }
   int average_marks(float a,float b,float c)
   {
    return (a+b+c)/3;
   }
   void displaymarks()
   {
    cout<<"roll no"<<roll<<endl;
    cout<<"name of student"<<name<<endl;
    cout<<"marks of 1"<<m1<<endl;
    cout<<"marks of 2"<<m2<<endl;
    cout<<"marks of 3"<<m3<<endl;
    cout<<"average marks"<<average_marks(m1,m2,m3)<<endl;
   }
};
int main()
{
    student st[3];
    st[0]=student();
    int roll;
    string name;
    float a,b,c;

    for(int i=1;i<3;i++)
    {
      cout<<"--student details--"<<endl;
      cout<<"enter the roll number"<<endl;
      cin>>roll;
      cout<<"enter the name"<<endl;
      cin>>name;
      cout<<"enter the marks"<<endl;
      cin>>a>>b>>c;

      st[i]=student(roll,name,a,b,c);
    }
    //for displaying data
    for(int i=0;i<3;i++)
    {
        st[i].displaymarks();
    }  
    return 0; 
}