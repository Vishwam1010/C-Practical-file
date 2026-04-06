#include<iostream>
using namespace std;

class inventory
{
  private:
  int itemid;
  string itemname;
  double price;
 
  int initialstock;
  int addedstock;
  int totalstockafteradd;
  int soldstock;
  int currentstock;

  public:
  inventory()
  {
    int itemid=0;
    string itemname ="test name" ;
    double price=0;
    int initialstock=0;
    int addedstock=0;
    int totalstockafteradd=0;
    int soldstock=0;
    int currentstock=0;
  }
  inventory(int id,string name,double p,int inistck)
  {
    itemid=id;
    itemname=name;
    price=p;
    initialstock=inistck;
    addedstock=0;
    soldstock=0;
    totalstockafteradd=initialstock;
    currentstock=initialstock;
  }
  int addstock(int n)
  {
    if(n>0)
    {
        addedstock+=n;
        totalstockafteradd=initialstock+addedstock;
        currentstock=totalstockafteradd-soldstock;
    }
    else if(n<0)
    {
        cout<<"insufficient stock"<<endl;
    }
  }
  int sellstock(int n)
  {
    if(n>0 && n<=currentstock)
    {
      soldstock+=n;
      currentstock-=n;
    }
    else if(n<0)
    {
      cout<<"insufficient stock"<<endl;
    }
  }
  void display()
  {
    cout<<"--Inventory details--"<<endl;
    cout<<"item name--"<<itemname<<endl;
    cout<<"item Id--"<<itemid<<endl;
    cout<<"item's price--"<<price<<endl;
    cout<<"initial stock--"<<initialstock<<endl;
    cout<<"added stock--"<<addedstock<<endl;
    cout<<"total stock--"<<totalstockafteradd<<endl;
    cout<<"current stock--"<<currentstock<<endl;
  }
};
int main()
{
  inventory I1(101,"hp victus",40000,100);
  I1.addstock(20);
  I1.sellstock(10);
  I1.display();
  return 0;
}