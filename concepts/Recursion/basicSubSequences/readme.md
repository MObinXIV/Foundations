# Subsequence

here, we use recursion to print subsequences.

## Code:
`void subsets(int ind ,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int n)
{
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[ind]);
    subsets(ind+1,ds,nums,ans,n);
    ds.pop_back();
    subsets(ind+1,ds,nums,ans,n);}`

-T.c -> O(2^n *n)
-S.c -> O(n)
