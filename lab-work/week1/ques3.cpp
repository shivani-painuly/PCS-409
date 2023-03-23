/*
Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching)
*/
#include <iostream>
#include <cmath>

using namespace std;

int jumpsearch(int a[], int c, int num)
{
    int start = 0, ending = sqrt(c), i;
    while (a[ending] <= num && ending < c)
        {
        start = ending;
        ending += sqrt(c);
        if (ending > c - 1)
        {
            ending = c;
        }
    }
    for (i = start; i < ending; i++) {
        if (a[i] == num) {
            return i;
        }
    }
    return start;
}

int main() {
    int a[100], b, c, i, j, num;
    cout << "Input number of test cases: " << endl;
    cin >> b;
    for (i = 0; i < b; i++) {
        cout << "Input number of elements in array: " << endl;
        cin >> c;
        cout << "Input sorted elements in array: " << endl;
        for (j = 0; j < c; j++) {
            cin >> a[j];
        }
        cout << "Input element to search: " << endl;
        cin >> num;
        int res = jumpsearch(a, c, num);
        if (res == c) {
            cout << "Not Present. It would be inserted at index " << res << endl;
        } else if (a[res] == num) {
            cout << "Present at index " << res << endl;
        } else {
            cout << "Not Present. It would be inserted at index " << res << endl;
        }
    }
    return 0;
}
