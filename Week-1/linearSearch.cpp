// Given an array of nonnegative integers, design a linear algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total number
// of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)

#include <iostream>
using namespace std;

void fun(int *arr, int n, int key)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
        {
            cout << "Present " << i + 1 << endl
                 << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not Present " << n << endl
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

        fun(arr, n, key);

        delete[] arr;
        testCase--;
    }
    return 0;
}
