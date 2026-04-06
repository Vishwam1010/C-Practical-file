#include<iostream>
using namespace std;

class library
{
   private:
    double Bid;
    string title;
    string author;
    int numc;

    public:
    void addbook(int n)
    {
      numc=numc+n;
    }
    void issuebook(int n)
    {
      if(numc>n)
      {
        numc=numc-n;
      }
      else cout<<"copies are not available"<<endl;
    }
    void returnbook(int n)
    {
      numc=numc+n;
    }
    void dispbook()
    {
      cout<<"book no."<<Bid<<endl<<"book title--"<<title<<endl<<"author of book--"<<author<<endl<<"number of copies--"<<numc<<endl;
    }
    void setdata(double id,string titleb,string writer,int c)
    {
      Bid=id;
      title=titleb;
      author=writer;
      numc=c;
    }
};

int main()
{
    library b1,b2,b3;
    b1.setdata(1,"maths","ramanujan",100);
    b2.setdata(2,"physics","isaac newton",500);
    b3.setdata(3,"chemistry","rutherford",1000);
    b1.issuebook(50);
    b1.returnbook(30);
    b1.dispbook();
    
    b2.issuebook(200);
    b2.returnbook(100);
    b2.dispbook();

    b3.dispbook();

    return 0;
}