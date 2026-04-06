#include<iostream>
using namespace std;
 
class rectangle
{
  private:
  double length;
  double width;

  public:
  void setdata(double l,double w)
  {
    length=l;
    width=w;
  }
  double area( double l,double w)
  {
    return l*w;
  }
  double perimeter(double l,double w)
  {
    return 2*(l+w);
  }
  void display(int index)
  {
    cout<<"\nindex number of rectangle-- "<<index;
    cout<<"\narea of rectangle-- "<<area;
    cout<<"\nperimeter of rectangle-- "<<perimeter;
  }
};

int main()
{
    rectangle rect[10];
    int choice;
    int count;
    count=0;

    do
    {
      cout<<"1.adding rectangle"<<endl;
      cout<<"2.updating rectangle"<<endl;
      cout<<"3.displaying rectangle according to index number"<<endl;
      cout<<"4.exit"<<endl;

      int choice;
      switch(choice)
      {
        case 1:
        double length,width;
        cin>>length>>width;

     
      
      
    
    }
}