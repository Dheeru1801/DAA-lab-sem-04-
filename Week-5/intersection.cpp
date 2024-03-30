#include <iostream>
using namespace std;
int common(int arr1[], int m, int arr2[], int n, int output[])
{
    int k = 0, i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            output[k] = arr1[i];
            k++;
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return k;
}
int main()
{
    int m, n, arr1[100], arr2[100], output[100], k;
    cout << "Enter 1st ARRAY size: ";
    cin >> m;
    cout << "Enter ARRAY 1: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter 2nd ARRAY size: ";
    cin >> n;
    cout << "Enter ARRAY 2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    k = common(arr1, m, arr2, n, output);
    cout << "Output Array: ";
    for (int i = 0; i < k; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}