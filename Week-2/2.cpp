// Given a sorted array of positive integers, design an algorithm and implement it using a program 
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k].  
// Input format: 
// The first line contains number of test cases, T. 
// For each test case, there will be two input lines. 
// First line contains n (the size of array). 
// Second line contains space-separated integers describing array. 
// Output:  
// The output will have T number of lines.  
// For each test case T, print the value of i, j and k, if found else print “No sequence found”.

#include <iostream>
#include <algorithm>
using namespace std;

void fun(int *arr,int n)
{
    for (int k = n - 1; k >= 0; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == arr[k])
            {
                cout << i << " " << j << " " << k << endl;
                return;
            }
            else if (sum < arr[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    cout << "No sequence found" << endl;
}

int main()
{
    int n, *arr, testCase;
    cin >> testCase;
    while (testCase)
    {
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }

        fun(arr,n);

        delete[] arr;

        testCase--;
    }
    return 0;
}