/*
Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.
Input Format: The first line contains number of test cases, T. For each test case, there will be two input lines. First line contains n (the size of array). Second line contains space-separated integers describing array.
Output Format: The output will have T number of lines. For each test case T, there will be three output lines. First line will give the sorted array. Second line will give total number of comparisons. Third line will give total number of swaps required.
*/
#include<iostream>
using namespace std;

void selectionsort(int arr[],int array_size)
{
    int min,i,j,temp,swaps=0,comparisons=0;
    for(i=0;i<array_size-1;i++)
    {
        min=i;
        for(j=i+1;j<array_size;j++)
        {
            comparisons++;
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        swaps++;
    }
    for(i=0;i<array_size;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"Swaps = "<<swaps<<endl<<"Comparisons = "<<comparisons<<endl;
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
        selectionsort(arr,array_size);
    }
    return 0;
}
