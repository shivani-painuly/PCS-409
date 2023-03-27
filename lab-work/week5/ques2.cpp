#include <iostream>

using namespace std;

int main()
{
    int i,j,k,test,n,key;
    cout<<"enter test cases";
    cin>>test;
    for(i=0;i<test;i++)
    {
        cout<<"enter number of element";
        cin>>n;
        int a[n];
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        cout<<"enter key";
        cin>>key;
        j=0;
        k=n-1;
        int x=0;
        while(j<=k)
        {
            if(a[j]+a[k]<key)
            j++;
            else if(a[j]+a[k]>key)
            k--;
            else
            {
               x=1; 
               cout<<a[j]<<" "<<a[k];
               break;
            }
        }
        if(x==0)
        cout<<"no such element exist";
    }
}
