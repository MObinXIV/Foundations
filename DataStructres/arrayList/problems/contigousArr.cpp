// https://leetcode.com/problems/contiguous-array/description/
#include <bits/stdc++.h>

using namespace std;

/*
generate every possible subArr and keep 2 counters
- one for the 0s
- other for the 1s
- check equality
- get the max postion
*/
int findMaxLength(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt0 = 0, cnt1 = 0; // keep 2 counters one for the 0s and the other for the 1s
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                cnt0++;
            else
                cnt1++;
            if (cnt1 == cnt0)
                maxi = max(maxi, j - i + 1);
        }
    }
    return maxi;
}

// approach similar to longest 0s problem
/*
we flip 0s to -1 and when we reach 0 we convert it into maximum 0 problem
*/
int findMaxLength(vector<int> &arr)
{
    int n = arr.size();
    int max_len = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] == 0 ? -1 : 1;
        if (sum == 0)
            max_len = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
                max_len = max(max_len, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return max_len;
}