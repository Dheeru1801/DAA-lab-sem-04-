#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int *cmp, int *Swap)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            (*cmp)++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        (*Swap)++;
    }
}

int main()
{
    int Testcase;
    cin >> Testcase;
    while (Testcase)
    {

        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "After sorting the array : ";
        int cmp = 0, Swap = 0;
        selectionSort(arr, n, &cmp, &Swap);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "Comparision = " << cmp << endl;
        cout << "Swap = " << Swap << endl;

        Testcase--;
    }
    return 0;
}