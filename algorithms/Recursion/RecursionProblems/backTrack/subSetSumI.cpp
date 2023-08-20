#include <bits/stdc++.h>

using namespace std;
void subsetSum(int ind, vector<int> &ds, int s, int sum, vector<int> &nums, vector<vector<int>> &ans, int n)
{
    if (ind == n)
    {
        if (s == sum)
            ans.push_back(ds);
        return;
    }

    ds.push_back(nums[ind]);
    s += nums[ind];
    subsetSum(ind + 1, ds, s, sum, nums, ans, n);
    s -= nums[ind];
    ds.pop_back();
    subsetSum(ind + 1, ds, s, sum, nums, ans, n);
}
vector<vector<int>> subsetSum(vector<int> &nums, int sum)
{
    vector<vector<int>> ans;
    vector<int> ds;
    subsetSum(0, ds, 0, sum, nums, ans, nums.size());
    return ans;
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    vector<vector<int>> ans = subsetSum(v, 6);
    for (auto vect1D : ans)
    {
        for (auto x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}