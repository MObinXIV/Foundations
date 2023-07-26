#include <bits/stdc++.h>

using namespace std;
int subsetSum(int ind,  int s, int sum, vector<int> &nums, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }

   
    s += nums[ind];
    int l= subsetSum(ind + 1, s, sum, nums,  n) ; // count the left recursion calls
        
    s -= nums[ind];
    int r = subsetSum(ind + 1,  s, sum, nums,  n); // count the right recursion calls

    // after U finish give the left guy with right guy
    return l+r;
}
int subsetSum(vector<int> &nums, int sum)
{
    int res=subsetSum(0,  0, sum, nums,  nums.size());
    return res;
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    int ans = subsetSum(v, 6);
    cout<<ans<<endl;
    
}