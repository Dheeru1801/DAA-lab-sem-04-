#include <bits/stdc++.h>
using namespace std;

// int MCM(vector<int>arr,int i,int j,vector<vector<int>>&dp)
// {
//     int mini=INT_MAX;
//     if(i==j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];

//     for(int k=i;k<j;k++)
//     {
//         int steps=arr[i-1]*arr[k]*arr[j] + MCM(arr,i,k,dp) + MCM(arr,k+1,j,dp);
//         mini=min(mini,steps);
//     }

//     return dp[i][j]=mini;
// }

int MCMTabulation(vector<int>arr,int n)
{
    
    int dp[n][n];
    for(int i=1;i<n;i++) 
        dp[i][i]=0;
    
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int mini=INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j]=mini;
        }
    }

    return dp[1][n-1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // vector<vector<int>>dp(n,vector<int>(n,-1));    
    // cout << "Minimum MCM: " << MCM(arr, 1,n-1,dp) << endl;
    
    cout << "Minimum MCM: " << MCMTabulation(arr,n) << endl;
    return 0;
}
