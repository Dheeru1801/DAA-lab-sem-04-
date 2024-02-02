// Given an already sorted array of positive integers, design an algorithm and implement it using a
// program to find whether a given key element is present in the sorted array or not. For an array
// arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k]< key < arr[ 2k+1] ) is found,
// perform a linear search operation from the index 2k
// to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):

// Jump Search

// Input format:
// The first line contains number of test cases, T.
// For each test case, there will be three input lines.
// First line contains n (the size of array).
// Second line contains n space-separated integers describing array.
// Third line contains the key element that need to be searched in the array.
// Output format:
// The output will have T number of lines.For each test case, output will be “Present” if the key element is found in the array, otherwise
// “Not Present”

#include <iostream>
using namespace std;

void linearSearch(int *arr, int lb, int ub, int key)
{
    int flag = 0, c = 1;
    for (int i = lb; i <= ub; i++)
    {
        c++;
        if (*(arr + i) == key)
        {
            cout << "Present " << c << endl
                 << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not Present " << c << endl
             << endl;
    }
}

void jumpSearch(int *arr, int n, int key)
{
    if (arr[0] == key)
    {
        cout << "Element found at first index" << endl;
        return;
    }
    int i = 1;
    while (i < n && arr[i] <= key)
    {
        i *= 2;
    }
    linearSearch(arr, i / 2, min(n, i), key);
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases)
    {

        int *arr, n, key;
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }
        cin >> key;

        jumpSearch(arr, n, key);

        test_cases--;
    }
    return 0;
}