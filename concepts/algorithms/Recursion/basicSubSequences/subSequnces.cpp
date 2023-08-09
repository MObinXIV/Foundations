#include <bits/stdc++.h>
using namespace std;
void subsets(int ind ,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int n)
{
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(nums[ind]);
    subsets(ind+1,ds,nums,ans,n);
    ds.pop_back();
    subsets(ind+1,ds,nums,ans,n);

}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>>ans;
    vector<int>ds;
     subsets(0,ds,nums,ans,nums.size());
     return ans;
}

int main()
{
    vector<int>v{1,2,3};
    vector<vector<int>>ans =subsets(v);
    for (auto vect1D : ans)
    {
        for (auto x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}