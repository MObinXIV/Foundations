// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>

using namespace std;

// Brute force -> O(n^3)
// get every possible window
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// more optimal solution -> O(n^2)
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// Kadane's algorithm ->move forward and always maximize yourself , O(n)
int maxSubArray(vector<int> &nums)
{
    int s = 0;
    int maxi = INT_MIN;
    for (auto it : nums)
    {
        s += it;
        maxi = max(maxi, s);
        // don't take the negative guys as they 'll reduce U as U go
        if (s < 0)
            s = 0;
    }

    return maxi;
}

// printing -> the trick is that whenever, we have

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    int maxi = INT_MIN;
    int start = 0, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i; // mark my start
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]\n";
    return maxi;
}