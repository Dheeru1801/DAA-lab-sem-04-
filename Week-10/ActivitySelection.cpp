#include<bits/stdc++.h>
using namespace std;

void activitySelection(vector<int>startTime,vector<int>endTime,int n)
{
    int count=0;

    vector<pair<int,pair<int,int>>>activity(n);
    for(int i=0;i<n;i++)
    {
        activity[i]={endTime[i],{startTime[i],i+1}};
    }

    sort(activity.begin(),activity.end());
    vector<int>result;
    int currentEnd=-1;

    for(int i=0;i<n;i++)
    {
        if(currentEnd<=activity[i].second.first)
        {
            currentEnd=activity[i].first;
            count++;
            result.push_back(activity[i].second.second);
        }
    }

    sort(result.begin(),result.end());
    cout<<"no of non-conflicting activities : "<<count<<endl;
    cout<<"List of selected activities : ";
    for(int i:result)
        cout<<i<<",";

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>startTime(n);
    vector<int>endTime(n);
    for(int i=0;i<n;i++)
    {
        cin>>startTime[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> endTime[i];
    }

    activitySelection(startTime,endTime,n);

    return 0;
}