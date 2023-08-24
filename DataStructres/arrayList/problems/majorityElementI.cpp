// https://leetcode.com/problems/majority-element/description/
#include <bits/stdc++.h>

using namespace std;
// brute force -> nested loops take O(n^2)

// TC -> O(nlogn)+O(n)
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
        if (mp[it] > (n + 1) / 2)
            return it;
    }
    return -1;
}

// moore's voting algorithm -> the last man standing

int majorityElement(vector<int> &nums)
{
    int cnt = 0;
    int el;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (nums[i] == el)
        {
            cnt++;
        }
        else
            cnt--;
    }
    return el;
    // this part is unnecessary in leetcode problem which gurantee the element always exists
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
            cnt1++;
    }
    if (cnt1 > n / 2)
        return el;

    return -1;
}