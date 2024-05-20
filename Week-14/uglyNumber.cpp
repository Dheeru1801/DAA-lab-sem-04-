#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n)
{
    vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    int nextUglyNumber = 1;

    for (int i = 1; i < n; ++i)
    {
        nextUglyNumber = min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2)
        {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3)
        {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5)
        {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }

    return uglyNumbers[n - 1];
}

int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    vector<int> results(T);
    for (int t = 0; t < T; ++t)
    {
        int n;
        cout << "Enter the value of n for test case " << t + 1 << ": ";
        cin >> n;
        results[t] = nthUglyNumber(n);
    }

    for (int t = 0; t < T; ++t)
    {
        cout << "The " << t + 1 << "th ugly number is: " << results[t] << endl;
    }

    return 0;
}
