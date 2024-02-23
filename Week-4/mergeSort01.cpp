#include<iostream>
using namespace std;

void Merge(int arr[],int lb,int mid,int ub)
{
    int temp[ub-lb+1];
    int i=lb,j=mid+1,k=0;
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else if (arr[i] > arr[j])
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int l=0;l<k;l++)
    {
        arr[lb+l]=temp[l];
    }
}
void mergeSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int  mid=lb+(ub-lb)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    }
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

        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        
    
    return 0;
}