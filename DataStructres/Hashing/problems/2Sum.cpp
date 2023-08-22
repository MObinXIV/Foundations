// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>

using namespace std;
//*very naive approach is using nested loops* O(n^2)//

// O(nlogn)
vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (mp.find(target - arr[i]) != mp.end())
        {
            return {mp[target - arr[i]], i};
        }
        mp[arr[i]] = i;
    }

    return {-1, -1};
}