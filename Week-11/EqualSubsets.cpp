#include<bits/stdc++.h>
using namespace std;

// bool equalSubsets(vector<int>arr,int i,int target)
// {
//     if(target==0) return true;
//     if(i==0) return (target==arr[i]);

//     bool pick=false;
//     bool notPick=equalSubsets(arr,i-1,target);
//     if(arr[i]<=target) pick=equalSubsets(arr,i-1,target-arr[i]);

//     return (pick||notPick);
// }


// bool equalSubsets(vector<int> arr, int i, int target,vector<vector<int>>&dp)
// {
//     if (target == 0)
//         return true;
//     if (i == 0)
//         return (target == arr[i]);
//     if(dp[i][target]!=-1) return dp[i][target];

//     bool pick = false;
//     bool notPick = equalSubsets(arr, i - 1, target,dp);
//     if (arr[i] <= target)
//         pick = equalSubsets(arr, i - 1, target - arr[i],dp);

//     return dp[i][target]=(pick || notPick);
// }

bool equalSubsets(vector<int> arr, int i, int k)
{
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));

    // base cases
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;

    for(int i=0;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            bool pick = false;
            bool notPick = dp[i-1][target];
            if (arr[i] <= target)
                pick = dp[i-1][target- arr[i]] ;

            dp[i][target] = (pick || notPick);
        }
    }

    return dp[n-1][k];
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    
    if(sum%2!=0)
        cout << "False" << endl;
    else    
    {
        int target=sum/2;
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        if(equalSubsets(arr,n-1,target)) cout<<"True";
        else cout<< "False";
    }
        
    return 0;
}