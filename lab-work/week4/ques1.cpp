/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.
*/
#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right) {
    long long inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inv_count;
}

long long merge_sort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main()
{
    int test_cases;
    cout<<"Enter the number if test cases"<<endl;
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
    int temp[n];
    long long inv_count = merge_sort(arr, temp, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << inv_count << "\n";
    }
}
