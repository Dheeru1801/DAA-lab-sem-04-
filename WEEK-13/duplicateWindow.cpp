#include <bits/stdc++.h>
using namespace std;

void checkDuplicatesInWindow(const vector<int> &arr, int k)
{
    unordered_set<int> windowElements;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i > k)
        {
            // Remove the element that is out of the current window
            windowElements.erase(arr[i - k - 1]);
        }
        // If the current element is already in the set, we found a duplicate
        if (windowElements.find(arr[i]) != windowElements.end())
        {
            cout << "Duplicate present in window " << k << "." << endl;
            return;
        }
        // Add the current element to the set
        windowElements.insert(arr[i]);
    }
    cout << "Duplicate not present in window " << k << "." << endl;
}

int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    while (T--)
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
        int k;
        cout << "Enter the value of k: ";
        cin >> k;

        checkDuplicatesInWindow(arr, k);
    }
    return 0;
}
