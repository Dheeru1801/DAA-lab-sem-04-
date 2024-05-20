#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the character array: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Enter the elements of the character array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Use an unordered_map to count the frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char c : arr)
    {
        frequencyMap[c]++;
    }

    // Store characters in a vector and sort them
    vector<char> distinctChars;
    for (auto &entry : frequencyMap)
    {
        distinctChars.push_back(entry.first);
    }
    sort(distinctChars.begin(), distinctChars.end());

    // Output the characters and their frequencies
    cout << "Characters present in the array in alphabetical order and their frequencies:\n";
    for (char c : distinctChars)
    {
        cout << c << ": " << frequencyMap[c] << endl;
    }

    return 0;
}
