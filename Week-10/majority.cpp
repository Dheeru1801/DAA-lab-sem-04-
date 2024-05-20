#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the majority element using Boyer-Moore Voting Algorithm
int findMajorityElement(vector<int> &nums)
{
    int candidate = -1, count = 0;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    // Verify the candidate
    count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }
    return (count > nums.size() / 2) ? candidate : -1;
}

// Function to find the median
double findMedian(vector<int> &nums)
{
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
    if (n % 2 == 1)
    {
        return nums[n / 2];
    }
    else
    {
        int a = nums[n / 2];
        nth_element(nums.begin(), nums.begin() + n / 2 - 1, nums.end());
        int b = nums[n / 2 - 1];
        return (a + b) / 2.0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Find the majority element
    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    // Find the median
    double median = findMedian(nums);
    cout <<"Median of the array : "<< median << endl;

    return 0;
}
