// Given a sorted array of positive integers containing few duplicate elements, design an algorithm
// and implement it using a program to find whether the given key element is present in the array or not .
// If present, then also find the number of copies of given key.(Time Complexity = O(log n))
// Input format : The first line contains number of test cases, T
// .For each test case, there will be three input lines.First line contains n(the size of array).
// Second line contains space - separated integers describing array.
// Third line contains the key element that need to be searched in the array.
// Output format:
// The output will have T number of lines.For each test case T,
// output will be the key element and its number of copies in the array if the
// key element is present in the array otherwise print “Key not present”.

#include <iostream>
#include <algorithm>
using namespace std;

void findKeyAndCopies(int *arr, int n, int key)
{
    int lower = lower_bound(arr, arr + n, key) - arr;
    int upper = upper_bound(arr, arr + n, key) - arr;
    int copy = upper - lower;
    cout << key << " - " << copy << endl;
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

        findKeyAndCopies(arr, n, key);

        delete[] arr;

        testCase--;
    }
    return 0;
}