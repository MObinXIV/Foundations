// https://leetcode.com/problems/4sum/description/
#include <bits/stdc++.h>

using namespace std;

// Brute force solution naive one like 3 sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    set<vector<int>> st;

    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// O(n^3logn)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    set<vector<int>> st;

    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// O(n^3)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // duplicates check
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // don't forget check here
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            // now let's define a 2 pointers
            int l = j + 1;
            int k = n - 1;
            while (l < k)
            {
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> tmp{nums[i], nums[j], nums[k], nums[l]};
                    res.push_back(tmp);
                    l++, k--;
                    while (l < k && nums[l] == nums[l - 1])
                        l++;
                    while (l < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum < target)
                    l++;
                else
                    k--;
            }
        }
    }
    return res;
}