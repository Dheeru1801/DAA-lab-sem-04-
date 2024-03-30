#include <bits/stdc++.h>

using namespace std;

void maxFreq(string str)
{
    unordered_map<char, int> umap;
    for (char c : str)
    {
        umap[c]++;
    }
    int max = 0;
    char maxChar;
    for (const auto a : umap)
    {
        if (a.second > max)
        {
            max = a.second;
            maxChar = a.first;
        }
    }
    if (max != 1)
        cout << "Max occurance character : " << maxChar << "-" << max << endl;
    else
        cout << "No duplicate element found" << endl;
}

// void maxFreqString(string str)
// {
//     unordered_map<string, int> umap;

//     stringstream ss(str);
//     string word;
//     while(ss>>word)
//     {
//         umap[word]++;
//     }
    
//     int max = 0;
//     string maxStr;
//     for (const auto a : umap)
//     {
//         if (a.second > max)
//         {
//             max = a.second;
//             maxStr = a.first;
//         }
//     }
//     if (max != 1)
//         cout << "Max occurance word : " << maxStr << "-" << max << endl;
//     else
//         cout << "No duplicate word found" << endl;
// }

int main()
{
    string charArray;
    string str;

    cout << "Enter the character array : ";
    cin>>charArray;

    cout << "Enter the string : ";
    getline(cin, str);

    maxFreq(charArray);
    
    maxFreq(str);
}

