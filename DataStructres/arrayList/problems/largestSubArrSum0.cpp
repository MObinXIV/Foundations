#include <bits/stdc++.h>

using namespace std;

// generate subsest sun => O(n^2)
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        int cur_Sum = 0;
        for (int j = i; j < n; j++)
        {
            cur_Sum += arr[j];
            if (cur_Sum == 0)
                max_len = max(max_len, j - i + 1);
        }
    }
    return max_len;
}

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int max_Len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_Len = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                max_Len = max(max_Len, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return max_Len;
}