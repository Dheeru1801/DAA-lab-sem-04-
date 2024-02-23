#include <iostream>
using namespace std;

void insertionSort(int arr[], int n,int *cmp,int *shift)
{
    int key, j, i;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        key = arr[i];
        
        while (j >= 0 && arr[j] > key)
        {
            (*cmp)++;
            arr[j + 1] = arr[j];
            j--;
            (*shift)++;
        }
        (*shift)++;
        arr[j + 1] = key;
    }
}

int main()
{
    cout << "Enter the size of the array : ";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "After sorting the array : ";
    int cmp=0,shift=0;
    insertionSort(arr, n,&cmp,&shift);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<"Comparision = "<<cmp<<endl;
    cout<<"Shift = "<<shift<<endl;

    return 0;
}