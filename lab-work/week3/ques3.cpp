/*
Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))
Input Format: The first line contains number of test cases, T. For each test case, there will be two input lines. First line contains n (the size of array). Second line contains space-separated integers describing array.
Output Format: The output will have T number of lines. For each test case, output will be 'YES' if duplicates are present otherwise ‘NO’.
*/
#include <iostream>
#include<algorithm>
using namespace std;

int hasDuplicates(int arr[], int array_size)
{
    sort(arr,arr+array_size);
    for (int i=0;i<array_size-1;i++)
    {
        if (arr[i] == arr[i+1])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int arr[10],array_size,testcase,i,j;
    cout<<"Input number of test cases"<<endl;
    cin>>testcase;
    while(testcase--){
        cout<<"Input array size"<<endl;
        cin>>array_size;
        cout<<"Input array elements"<<endl;
        for(i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }
    if(hasDuplicates(arr,array_size))
    {
        cout <<"YES"<< endl;
    } else
    {
        cout <<"NO"<< endl;
    }
    }
    return 0;
}
