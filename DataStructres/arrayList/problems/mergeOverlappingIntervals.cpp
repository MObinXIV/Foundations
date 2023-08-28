// https://leetcode.com/problems/merge-intervals/description/
#include <bits/stdc++.h>

using namespace std;

// brute force -> O(nlogn)+O(2n)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!res.empty() && res.back()[1] >= end) // if I already got it
            continue;
        // loop to merge all the next intervals at ones
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end) // if the beginning of the next interval is less than the end of the previous one this means it overlaps
                // then I change the end to the max one < as I gurantee the first element is alawys smaller
                end = max(intervals[j][1], end);
            // here I got exhausted all the intervals I can merge here
            else
                break;
        }
        res.push_back({start, end});
    }

    return res;
}

// Optimal solution ->O(nlogn)+O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if (res.empty() || intervals[i][0] > res.back()[1]) // if there no possible overlapping or array is empty
            res.push_back(intervals[i]);
        // otherwise there's ans overlapping
        else
            res.back()[1] = max(res.back()[1], intervals[i][1]);
    }

    return res;
}