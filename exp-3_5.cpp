#include<iostream>
using namespace std;

int superdigit(long long n)
{
    if(n<10)
    return n;
    long long sum=0;
    while(n>0)
    {
      sum+=n%10;
      n=n/=10;  
    }
    return superdigit(sum);
}
int main()
{
    string n;
    int k;
    cout<<"enter the number as string"<<endl;
    cin>>n;
    cout<<"enter the value of k"<<endl;
    cin>>k;
    long long sum=0;
    for(int i=0;i<n.length();i++)
    {
       sum+=n[i]-'0';
    }
    sum=sum*k;
    int result=superdigit(sum);
    cout<<"the superdigit is--"<<result<<endl;
    return 0;
}