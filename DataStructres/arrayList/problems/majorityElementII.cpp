// https://leetcode.com/problems/majority-element-ii/
#include <bits/stdc++.h>

using namespace std;

/* At maximum we have 2 elements and at minimum we have 0 so the range from 0->2*/

// Brute force solution-> O(n^2)
vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        // check here if the mye lest don't have the element already
        if (res.size() == 0 || res[0] != arr[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                    cnt++;
            }
            if (cnt > n / 3)
                res.push_back(arr[i]);
        }
        // I gurantee there's only 2 elements
        if (res.size() == 2)
            break;
    }
    return res;
}

// nearly O(n)
vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> res;
    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;
    for (auto it : arr)
    {
        mp[it]++;
        if (mp[it] == mini)
            res.push_back(it);
        if (res.size() == 2)
            break;
    }
    return res;
}

// moore's voting algorithm (similuation for the majority /2 elements)
/// remember important thing e1 & e2 are unique elements  as it leads us to one edge case to avoid this
// O(2n)
vector<int> majorityElement(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // we check the case of 0 and with it see if the second element is not the current element as we keep it to count before and we take only unique elements
        if (cnt1 == 0 && el2 != arr[i])
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && el1 != arr[i])
        {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (arr[i] == el1)
            cnt1++;
        else if (arr[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    // manually check the elements
    vector<int> res;
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
            cnt1++;
        if (el2 == arr[i])
            cnt2++;
    }
    int mini = (n / 3) + 1;
    if (cnt1 >= mini)
        res.push_back(el1);
    if (cnt2 >= mini)
        res.push_back(el2);

    return res;
}