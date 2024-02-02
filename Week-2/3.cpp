// Given an array of nonnegative integers, design an algorithm and a program to count the number 
// of pairs of integers such that their difference is equal to a given key, K.  
// Input format: 
// The first line contains number of test cases, T. 
// For each test case, there will be three input lines. 
// First line contains n (the size of array). 
// Second line contains space-separated integers describing array. 
// Third line contains the key element. 
// Output format:  
// The output will have T number of lines.  
// For each test case T, output will be the total count i.e., number of times such pair exists.

#include <iostream>
#include <algorithm>
using namespace std;
//using two pointer approach
int fun(int arr[], int n, int key)
{
    sort(arr, arr + n);

    int count = 0;
    int left = 0, right = 1;

    while (right < n)
    {
        int diff = arr[right] - arr[left];

        if (diff == key)
        {
            count++;
            left++;
            right++;
        }
        else if (diff < key)
        {
            right++;
        }
        else
        {
            left++;
        }

        if (left == right)
        {
            right++;
        }
    }

    return count;
}

int main()
{
    int n, *arr, testCase,key;
    cin >> testCase;
    while (testCase)
    {
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }
        cin>>key;

        int x=fun(arr, n,key);
        cout<<x<<endl<<endl;

        delete[] arr;

        testCase--;
    }

    return 0;
}