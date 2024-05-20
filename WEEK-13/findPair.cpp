#include <bits/stdc++.h>
using namespace std;

void findPairs(vector<int> &arr)
{
    unordered_map<int, pair<int, int>> productMap;
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int product = arr[i] * arr[j];

            // If the product is already in the map, we found a solution
            if (productMap.find(product) != productMap.end())
            {
                pair<int, int> firstPair = productMap[product];
                pair<int, int> secondPair = {arr[i], arr[j]};

                // Ensure all elements are distinct
                if (firstPair.first != secondPair.first && firstPair.first != secondPair.second &&
                    firstPair.second != secondPair.first && firstPair.second != secondPair.second)
                {
                    cout << "Pair (a, b): (" << firstPair.first << ", " << firstPair.second << ")\n";
                    cout << "Pair (c, d): (" << secondPair.first << ", " << secondPair.second << ")\n";
                    return;
                }
            }
            else
            {
                // Otherwise, store the product and the pair
                productMap[product] = {arr[i], arr[j]};
            }
        }
    }

    cout << "No pairs found such that a * b = c * d with distinct elements.\n";
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findPairs(arr);

    return 0;
}
