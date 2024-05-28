// Rabin Karp Algorithm

#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(string pat, string txt, int q)
{
    int M = pat.length(), N = txt.length(), i, j, p = 0, t = 0, h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string pat, txt;
    cout << "Enter the pattern : ";
    getline(cin, pat);
    cout << "Enter the text :  ";
    getline(cin, txt);
    int q = INT_MAX;

    search(pat, txt, q);
    return 0;
}
