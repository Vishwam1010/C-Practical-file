#include<iostream>
using namespace std;

template<class T>
T maximum(T a[],int n)
{
   T max=a[0];
   for(int i=0;i<n;i++)
   {
    if(a[i]>max)
    {
      max=a[i];
    }
   }
   return max;
}
template<class T>
void reverse(T a[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        
       T temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
}
template<class T>
void display(T a[],int n)
{
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
  int a[]={1,2,3,4,5};
  int n=5;
  cout<<"original array"<<endl;
  display(a,n);
  cout<<"maximum element is--"<<maximum(a,n)<<endl;
  reverse(a,n);
  cout<<"reversed array";
  display(a,n);
  return 0;
}