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
using namespace std;

int findFirstOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}

int findLastOccurrence(int *arr, int n, int key)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}

void findKeyAndCopies(int arr[], int n, int key)
{
    int firstOccurrence = findFirstOccurrence(arr, n, key);

    if (firstOccurrence != -1)
    {
        int lastOccurrence = findLastOccurrence(arr, n, key);
        int numberOfCopies = lastOccurrence - firstOccurrence + 1;

        cout << key << " - " << numberOfCopies << endl;
    }
    else
    {
        cout << "Key not present" << endl;
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

        findKeyAndCopies(arr, n, key);

        delete[] arr;

        testCase--;
    }
    return 0;
}