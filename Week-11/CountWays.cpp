#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int> coins, int n, int t)
{
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));

    for (int i = 0; i <= t; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = 1; 
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (coins[i] <= j)
                take = dp[i][j - coins[i]];
            dp[i][j] = take + notTake;
        }
    }

    return dp[n - 1][t];
}

int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    int t;
    cin>>t;
    cout << countWays(coins, n, t) << endl;

    return 0;
}
