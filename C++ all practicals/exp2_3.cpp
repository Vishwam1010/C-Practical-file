#include<iostream>
using namespace std;
 
class digiaccount
{
   private:
    string name;
    int Id;
    double balance;
     
    public:
    digiaccount()
    {
        name="no";
        Id=0;
        balance=0;
    }
    digiaccount(string n,int id,double b)
    {
        name=n;
        Id=id;
        balance=b;
    }
    double depositmoney(double amt)
    {  
      if(balance<0)
      {
        cout<<"invalid balance"<<endl;
      }
      else if(balance>=amt)
      {
        balance+=amt;
        cout<<"your current balance"<<balance<<endl;
      } 
    }
    double withdrawmoney(double amt)
    {
        if(balance<amt)
        {
            cout<<"insufficient balance"<<endl;
        }
        else if(balance>amt)
        {
            balance-=amt;
            cout<<"your current balance"<<endl;
        }
    }
    void displayaccount()
    {
      cout<<"---account details---"<<endl;
      cout<<"account holder name:--"<<name<<endl;
      cout<<"holder ID"<<Id<<endl;
      cout<<"balance is"<<balance<<endl;
    }
};
int main()
{
    digiaccount acc[3];
    acc[0]=digiaccount();
    
}