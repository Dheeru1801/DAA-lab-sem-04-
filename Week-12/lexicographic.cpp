#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations in lexicographic order
void permute(string str, int left, int right, set<string> &result)
{
    if (left == right)
    {
        result.insert(str);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(str[left], str[i]);
            permute(str, left + 1, right, result);
            swap(str[left], str[i]); // backtrack
        }
    }
}

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;

    set<string> permutations;
    permute(input, 0, input.size() - 1, permutations);

    cout << "All possible permutations in lexicographic order:\n";
    for (const auto &perm : permutations)
    {
        cout << perm << endl;
    }

    return 0;
}
