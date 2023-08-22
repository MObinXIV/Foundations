// https://leetcode.com/problems/intersection-of-two-arrays/description/
#include <bits/stdc++.h>

using namespace std;

// hashSet solution -> O(m + n)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> st1, st2;

    for (auto it : nums1)
        st1.emplace(it);

    for (auto it : nums2)
        st2.emplace(it);

    vector<int> res;

    for (auto it : st1)
    {
        if (st2.count(it))
            res.push_back(it);
    }

    return res;
}

// 2pointers approach -> O(m log m + n log n)

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while (i1 < n1 && i2 < n2)
    {
        if (nums1[i1] == nums2[i2])
        {
            res.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if (nums1[i1] > nums2[i2])
        {
            i2++;
        }
        else
        {
            i1++;
        }

        /*
        skip the duplicates step
        */

        while (i1 > 0 && i1 < n1 && nums1[i1] == nums1[i1 - 1])
            i1++;
        while (i2 > 0 && i2 < n2 && nums2[i2] == nums2[i2 - 1])
            i2++;
    }
    return res;
}

// binary search approach -> optimal O(m log n).

bool SearchTarget(vector<int> &nums, int target)
{
    int n = nums.size();
    int h = n - 1, l = 0;
    while (l <= h)
    {
        int mid = (h + l) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[mid] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> hash_set;
    sort(nums2.begin(), nums2.end());
    for (auto it : nums1)
    {
        if (SearchTarget(nums2, it))
            hash_set.emplace(it);
    }
    vector<int> ans;
    for (auto it : hash_set)
    {
        ans.push_back(it);
    }
    return ans;
}
