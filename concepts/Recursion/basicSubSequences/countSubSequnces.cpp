#include <bits/stdc++.h>

using namespace std;
int subsetSum(int ind, vector<int> &ds, int s, int sum, vector<int> &nums, vector<vector<int>> &ans, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            ans.push_back(ds);
            return 1;
        }
        return 0;
    }

    ds.push_back(nums[ind]);
    s += nums[ind];
    int l= subsetSum(ind + 1, ds, s, sum, nums, ans, n) ; // count the left recursion calls
        
    s -= nums[ind];
    ds.pop_back();
    int r = subsetSum(ind + 1, ds, s, sum, nums, ans, n); // count the right recursion calls

    // after U finish give the left guy with right guy
    return l+r;
}
int subsetSum(vector<int> &nums, int sum)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int res=subsetSum(0, ds, 0, sum, nums, ans, nums.size());
    return res;
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    int ans = subsetSum(v, 6);
    cout<<ans<<endl;
    
}