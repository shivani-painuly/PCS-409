/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key.
*/
#include<iostream>
using namespace std;
void duplicate(int arr[],int key,int array_size)
{
    int c=0;
    for(int i=0;i<array_size;i++)
    {
        if(arr[i]==key)
        {
            c++;
        }
    }
    if(c>0)
    {
        cout<<key<<"-"<<c<<endl;
    }
    else
    {
        cout<<"Key is not found"<<endl;
    }
}
int main()
{
    int arr[100],array_size,testcase,key;
    cout<<"Input test case"<<endl;
    cin>>testcase;
    while(testcase--)
    {
        cout<<"Input array size"<<endl;
        cin>>array_size;
        cout<<"Input array elements"<<endl;
        for(int i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }
        cout<<"Input key to search"<<endl;
        cin>>key;
        duplicate(arr,key,array_size);
    }
}
