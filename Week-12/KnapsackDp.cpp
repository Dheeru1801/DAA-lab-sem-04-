#include <bits/stdc++.h>
using namespace std;

// Function to perform the 0-1 Knapsack algorithm
void knapsack(int W, vector<int> weights, vector<int> values, int N)
{
    // Create a 2D array to store the maximum value for each subproblem
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build the dp array
    for (int i = 1; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is in dp[N][W]
    int maxValue = dp[N][W];
    cout << "Maximum value: " << maxValue << endl;

    // Find the items that were selected
    vector<int> selectedItems;
    int w = W;
    for (int i = N; i > 0 && maxValue > 0; i--)
    {
        if (maxValue != dp[i - 1][w])
        {
            selectedItems.push_back(i - 1);
            maxValue -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    // Output the selected items
    cout << "Selected items:" << endl;
    for (int i = selectedItems.size() - 1; i >= 0; i--)
    {
        int itemIndex = selectedItems[i];
        cout << "Item " << itemIndex + 1 << ": Weight = " << weights[itemIndex] << ", Value = " << values[itemIndex] << endl;
    }
}

int main()
{
    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> weights(N);
    vector<int> values(N);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < N; i++)
    {
        cin >> values[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    knapsack(W, weights, values, N);

    return 0;
}
