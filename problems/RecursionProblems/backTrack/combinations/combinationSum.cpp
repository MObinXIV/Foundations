// https://leetcode.com/problems/combination-sum/description/

// Tc-> 2^p *k (2^p we can't know , k insertion of ds into ans)
// Sc-> k *x
#include <bits/stdc++.h>

using namespace std;
void combinationSum(int ind, vector<int> &arr, int tar, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        if (tar == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (arr[ind] <= tar)
    {
        ds.push_back(arr[ind]);
        combinationSum(ind, arr, tar - arr[ind], ds, ans);
        ds.pop_back(); // backTrack
    }
    // non-pick move forward only
    combinationSum(ind + 1, arr, tar, ds, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combinationSum(0, candidates, target, ds, ans);
    return ans;
}
int main()

{
    vector<int> arr = {2, 3, 6, 7};
    int tar = 7;
    vector<vector<int>> ans;
    ans = combinationSum(arr, tar);
    for (auto vect1D : ans)
    {
        for (auto x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}