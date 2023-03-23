/*
Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.
Input Format: The first line contains number of test cases, T. For each test case, there will be two input lines. First line contains n (the size of array). Second line contains space-separated integers describing array.
Output Format: The output will have T number of lines. For each test case T, there will be three output lines. First line will give the sorted array. Second line will give total number of comparisons. Third line will give total number of shift operations required.
*/
#include<iostream>
using namespace std;
void insertionsort(int arr[],int array_size)
{
    int i,j,t=0,comparison=0,shift=0;
    for(i=1;i<array_size;i++)
    {
        t=arr[i];
        j=i-1;
        shift++;
        while(j>=0&&t<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
            shift++;
            comparison++;
        }
        arr[j+1]=t;
    }
    for(i=0;i<array_size;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"Shifts = "<<shift<<endl<<"Comparisons = "<<comparison<<endl;
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
    insertionsort(arr,array_size);
    }
}
