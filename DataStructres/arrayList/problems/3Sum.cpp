// https://leetcode.com/problems/3sum/description/
#include <bits/stdc++.h>

using namespace std;

// Brute force -> using 3 pointers approach takes O(n^3)
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();

    set<vector<int>> st; // avoid duplicates
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    sort(tmp.begin(), tmp.end()); // to show if the vector already here
                    st.insert(tmp);
                }
            }
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

// Using hash , O(n^2logm)
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet; // we always reintialize the hashSet
        for (int j = i + 1; j < n; j++)
        {
            //
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> tmp{nums[i], nums[j], third};
                sort(tmp.begin(), tmp.end());
                st.insert(tmp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

// naive 2 pointers approach
vector<vector<int>> threeSum(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) // Here I do skip duplicates and take care of 0 case
        {
            // take my 3 pointers
            int low = i + 1;
            int high = n - 1;
            while (low < high)
            {
                int sum = arr[i] + arr[low] + arr[high];
                // here I face 3 cases
                if (sum < 0)
                {
                    low++;
                }
                else if (sum > 0)
                {
                    high--;
                }
                else
                {
                    // here for sure this is one of my triplet
                    vector<int> tmp = {arr[i], arr[low], arr[high]};
                    ans.push_back(tmp);
                    low++, high--;
                    while (low < high && arr[low] == arr[low - 1])
                        low++;
                    while (low < high && arr[high] == arr[high + 1])
                        high--;
                }
            }
        }
    }
    return ans;
}