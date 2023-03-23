#include<iostream>
using namespace std;
int binarysearch(int a[],int c,int num)
{
    int lb,ub,mid;
    lb=0;
    ub=c-1;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==num)
        {
            return mid+1;
        }
        else if(a[mid]>num)
        {
            ub=mid-1;
        }
        else if(a[mid]<num)
        {
            lb=mid+1;
        }
    }
    return -1;
}
int main()
{
    int a[100],b,c,i,j,num;
    cout<<"Input number of test cases"<<endl;
    cin>>b;
    for(i=0;i<b;i++)
    {
        cout<<"Input number of elements in array"<<endl;
        cin>>c;
        cout<<"Input sorted elements in array"<<endl;
        for(j=0;j<c;j++)
        {
            cin>>a[j];
        }
        cout<<"Input element to search"<<endl;
        cin>>num;
        int res=binarysearch(a,c,num);
        (res==-1)?cout<<"Not present"<<endl:cout<<"Present"<<res<<endl;
    }
}
