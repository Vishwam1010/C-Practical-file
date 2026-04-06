#include<iostream>
using namespace std;

class account
{
  private:
  int accountnumber;
  string holdername;
  double balance;
  public:
  int static totalaccount;
  
  account(int accNo,string name,double bal)
  {
    accountnumber=accNo;
    holdername=name;
    balance=bal;
    totalaccount++;
  }
  int getaccountnumber()
  {
    return accountnumber;
  }
  void updatename(string name)
  {
    holdername=name;
  }
  double getbalance( double)
  {
    return balance;
  }
  void deposit(double amount )
  {
    balance+=amount;
  }
  bool withdraw(double amount)
  {
    if(balance<amount)
    {
      cout<<"insuffienct balance"<<endl;
      return false;
    }
    balance-=amount;
    return true;
  }
  void display()
  {
    cout<<"account number--"<<accountnumber<<endl;
    cout<<" account name--"<<holdername<<endl;
    cout<<" account balance"<<balance<<endl;
  }
};
int account::totalaccount=0;

account* findaccount(account* accounts[],int count,int accNo)
{
 for(int i=0;i<count;i++)
 {
    if(accounts[i] -> getaccountnumber()==accNo)
    {
      return accounts[i];
    }
    
 }
 return NULL;
}
 void transfermoney(account* accounts[],int count)
 {
   int fromacc,toacc;
   double amount;
   cout<<" sender account"<<endl;
   cin>>fromacc;
   cout<<" receiver account"<<endl;
   cin>>toacc;
   cout<<" amount"<<endl;
   cin>>amount;
   account* sender=findaccount(accounts,count,fromacc);
   account* receiver=findaccount(accounts,count,toacc);
   if(sender==NULL || receiver==NULL)
   {
    cout<<"invalid data"<<endl;
   }
   else if(sender->withdraw(amount))
   {
    receiver->deposit(amount);
    cout<<"transaction successsfull"<<endl;
   }
 }

int main()
{
    int const MAX=100;
    account* accounts[MAX];
    int choice;
    int count=0;
    
    
    do
    {
      cout<<"1.Add account"<<endl;
      cout<<"2.updateaccount"<<endl;
      cout<<"3.transfer money"<<endl;
      cout<<"4.display account"<<endl;
      cout<<"5.display total account"<<endl;
      cout<<"choice"<<endl;
      cin>>choice;
     if(choice==1)
      {
         if (count >= MAX)
            {
                cout << "Account limit reached!" << endl;
                continue;
            }
        int accNo;
        string name;
        double balance;
        cout<<"enter account number"<<endl;
        cin>>accNo;
        cin.ignore();
        cout<<"enter holder name"<<endl;
        getline(cin,name);
        cout<<"enter the initial balance"<<endl;
        cin>>balance;

        accounts[count]=new account(accNo,name,balance);
        count++;
        cout<<"account successfully created"<<endl;
      }
     else if(choice==2)
      {
        int accNo;
            string name;

            cout << "Enter account number: ";
            cin >> accNo;
            cin.ignore();

            account* acc = findaccount(accounts, count, accNo);

            if (acc == NULL)
            {
                cout << "Account not found" << endl;
            }
            else
            {
                cout << "Enter new holder name: ";
                getline(cin, name);
                acc->updatename(name);
                cout << "Name updated successfully" << endl;
            }
      }
     else if(choice==3)
      {
        transfermoney(accounts,count);
      }
      else if(choice==4)
      {
        int accNo;
        cout<<"enter the account number"<<endl;
        cin>>accNo;
        account* acc=findaccount(accounts,count,accNo);
        if(acc==NULL)
        {
          cout<<"account not found"<<endl;
        }
        else 
        {
          acc->display();
        }
      }
      else if(choice==5)
      {
        cout<<"total accounts are--"<<account::totalaccount<<endl;
      }
    }while(choice!=0);  
  return 0;
}
