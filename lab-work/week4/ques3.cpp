/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int p = partition(arr, low, high);
        if (p - low == k - 1) {
            return arr[p];
        }
        else if (p - low > k - 1) {
            return kthSmallest(arr, low, p - 1, k);
        }
        else {
            return kthSmallest(arr, p + 1, high, k - p + low - 1);
        }
    }
    return -1;
}

int main()
{
    int test_cases;
    cout<<"Enter the number of test cases"<<endl;
    cin>>test_cases;
    while(test_cases--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        int res = kthSmallest(arr, 0, n - 1, k);
        if (res == -1) {
            cout << "not present\n";
        }
        else {
            cout << res << "\n";
        }
    }
}
