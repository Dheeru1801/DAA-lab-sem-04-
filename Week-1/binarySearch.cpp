// Given an already sorted array of positive integers, design an algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total number
// of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input).

#include <iostream>
using namespace std;

void fun(int *arr, int l, int u, int key, int &comparison)
{
    int mid = l + (u - l) / 2;
    comparison++;

    if (u >= l)
    {
        if (*(arr + mid) == key)
        {
            cout << "Present " << comparison << endl
                 << endl;
            return;
        }
        if (*(arr + mid) > key)
        {
            fun(arr, l, mid - 1, key, comparison);
        }
        if (*(arr + mid) < key)
        {
            fun(arr, mid + 1, u, key, comparison);
        }
    }
    else
    {
        cout << "Not Present " << comparison << endl
             << endl;
    }
}

int main()
{
    int n, *arr, testCase, key;
    cin >> testCase;
    while (testCase)
    {
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }
        cin >> key;

        int comparison = 0;
        fun(arr, 0, n - 1, key, comparison);

        delete[] arr;

        testCase--;
    }
    return 0;
}
