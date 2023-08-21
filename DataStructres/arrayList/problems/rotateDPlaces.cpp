// https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>

using namespace std;
// O(nlogn)
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    set<int> st;
    for (auto it : nums)
        st.insert(it); // I got only unique elements
    int ind = 0;
    for (auto it : st)
    {
        nums[ind] = it;
        ind++;
    }
    return ind;
}

// O(n)
int removeDuplicates(vector<int> &nums)
{
    int l = 1;
    int n = nums.size();
    if (n == 0)
        return 0;
    // I need to figure out someone who not equavlante to my current one
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] != nums[i])
        {
            nums[l++] = nums[i];
        }
    }

    return l;
}

