#include<iostream>
using namespace std;

void function(int arr[],int n)
{
    
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "After sorting the array : ";

    // function(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}