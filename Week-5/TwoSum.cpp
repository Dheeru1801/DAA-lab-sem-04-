#include<bits/stdc++.h>

using namespace std;

vector<int> TwoSum(vector<int>arr,int n,int key)
{
    vector<int>temp;
    
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==key)
        {
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            return temp;
        }
        else if(arr[i]+arr[j]<key)
            i++;
        else
            j--;
    }

    return temp;
} 

int main()
{

    int n;
    cout<<"Enter the no of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    vector<int> result = TwoSum(arr, n, k);
    if(result.empty())
        cout<<"No pair found"<<endl;
    else
        cout<<result[0]<<" "<<result[1]<<endl;

    return 0;
}