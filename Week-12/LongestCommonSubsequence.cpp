#include<bits/stdc++.h>
using namespace std;

// int LCS(string str1,string str2,int i1,int i2)
// {
//     //base case
//     if(i1<0||i2<0) return 0;

//     if(str1[i1]==str2[i2])
//         return 1+LCS(str1,str2,i1-1,i2-1);
    
//     return max(LCS(str1,str2,i1,i2-1),LCS(str1,str2,i1-1,i2));

// }

// int LCS(string str1, string str2, int i1, int i2,vector<vector<int>>&dp)
// {
//     // base case
//     if (i1 < 0 || i2 < 0)
//         return 0;
//     if(dp[i1][i2]!=-1) return dp[i1][i2];

//     if (str1[i1] == str2[i2])
//         return dp[i1][i2]=1 + LCS(str1, str2, i1 - 1, i2 - 1,dp);

//     return dp[i1][i2]=max(LCS(str1, str2, i1, i2 - 1,dp), LCS(str1, str2, i1 - 1, i2,dp));
// }

int LCS(string str1, string str2, int i1, int i2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

    //base case


    for(int i1=1;i1<=n1;i1++)
    {
        for(int i2=1;i2<=n2;i2++)
        {
            if (str1[i1-1] == str2[i2-1])
                    dp[i1][i2]=1+dp[i1-1][i2-1];

            else
                 dp[i1][i2]=max( dp[i1][i2-1] , dp[i1-1][i2] );
        }
    }

    return dp[n1][n2];
}

int main()
{
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;

    int n1=str1.length();
    int n2=str2.length();

    // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    cout<<LCS(str1,str2,n1-1,n2-1);

    return 0;
}