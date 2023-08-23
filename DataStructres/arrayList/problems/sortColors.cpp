// https://leetcode.com/problems/sort-colors/description/
#include <bits/stdc++.h>

using namespace std;

// use count sort -> O(2n)
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int &it : nums)
    {
        if (it == 0)
            cnt0++;
        else if (it == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        nums[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        nums[i] = 1;
    for (int i = cnt0 + cnt1; i < n; i++)
        nums[i] = 2;
}

// DNF -> O(n)
void sortColors(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        // 0->1 range
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++, mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        // unsorted range , so I'm not gurantee if I can be sorted

        else
        {
            swap(arr[mid], arr[high]);
            high--; // I move high only as I'm not sure about the value it can be 0 and I 'll swap it
        }
    }
}