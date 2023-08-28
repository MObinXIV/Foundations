// https://leetcode.com/problems/next-permutation/description/
#include <bits/stdc++.h>

using namespace std;

/*
1st approach is that
Step 1: Find all possible permutations of elements present and store them.

Step 2: Search input from all possible permutations.

Step 3: Print the next permutation present right after it.

O(N!*N)
*/

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

/*
1- find the break point , the point which break the increasing from behind dictionary (a[i]<a[i+1])
2- find the 1st element which is greater your current i element , meaning the smallest bigger element
3- try to place remaining in a sorted order(to fill it as small which gives me the next)
*/

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1) // edge case if I'm already sorted
        reverse(nums.begin(), nums.end());

    else
    {
        // seek to find the 1st element greater than U
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
}