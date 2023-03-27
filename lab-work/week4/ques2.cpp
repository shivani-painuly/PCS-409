/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high, long long &comp, long long &swaps) {
    int pivot = arr[low + rand() % (high - low + 1)];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
            comp++;
        } while (arr[i] < pivot);
        do {
            j--;
            comp++;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
        swaps++;
    }
}

void quicksort(int arr[], int low, int high, long long &comp, long long &swaps) {
    if (low < high) {
        int p = partition(arr, low, high, comp, swaps);
        quicksort(arr, low, p, comp, swaps);
        quicksort(arr, p + 1, high, comp, swaps);
    }
}

int main()
{
    int test_cases;
    cout<<"Enter the number of test cases"<<endl;
    cin>>test_cases;
    while(test_cases--)
    {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    srand(time(NULL));
    long long comp = 0, swaps = 0;
    quicksort(arr, 0, n - 1, comp, swaps);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << comp << "\n";
    cout << "Number of swaps: " << swaps << "\n";
    }
}
