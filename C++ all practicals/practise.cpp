#include<iostream>
using namespace std;
class xyz;
class abc
{
  private:
  int numA;
  public:
  void set()
  {
    numA=10;
  }
  friend int add(abc,xyz);
};
class xyz
{
    private:
    int numB;
    public:
    void setdata()
    {
        numB=20;
    }
  friend int add(abc,xyz);
};
int add(abc obja,xyz objb)
{
    return (obja.numA+objb.numB);
}
int main()
{
    abc obja;
    xyz objb;
    obja.set();
    objb.setdata();
    cout<<"sum is--"<<add(obja,objb)<<endl;
    return 0;
}