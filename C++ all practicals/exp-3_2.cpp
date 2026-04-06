#include<iostream>
using namespace std;

int iterativesum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int recursivesum(int arr[],int n)
{
    if(n==0)
    return 0;
    return arr[n-1]+recursivesum(arr,n-1);
}
int maxelementrecursive(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    int maxremaining  = maxelementrecursive(arr, n-1);

    if(arr[n-1] > maxremaining)
        return arr[n-1];
    else
        return maxremaining;
}

int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int* arr=new int[n];

    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    int sum_iterative=iterativesum(arr,n);
    int sum_recursive=recursivesum(arr,n);
    cout<<"iterative sum is--"<<sum_iterative<<endl;
    cout<<"recursive sum is--"<<sum_recursive<<endl;
    cout<<"the max element is--"<<maxelementrecursive(arr,n)<<endl;
    return 0;
}