#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minComputationCost(vector<int> &fileSizes)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push all file sizes into the priority queue
    for (int size : fileSizes)
    {
        pq.push(size);
    }

    int totalCost = 0;

    // While there are more than one file remaining
    while (pq.size() > 1)
    {
        // Pop two smallest files
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        // Merge them and add the cost to total cost
        int mergeCost = first + second;
        cout<<mergeCost<<endl;
        totalCost += mergeCost;

        // Push the merged file back into the priority queue
        pq.push(mergeCost);
    }

    return totalCost;
}

int main()
{
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> fileSizes(n);
    cout << "Enter the sizes of the files: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> fileSizes[i];
    }

    int result = minComputationCost(fileSizes);
    cout << "Minimum computation cost to merge all files: " << result << endl;

    return 0;
}
