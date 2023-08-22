// https://leetcode.com/problems/move-zeroes/
#include <bits/stdc++.h>

using namespace std;

// Brute force -> O(n) , space also O(n)
void moveZeroes(vector<int> &nums)
{
    vector<int> tmp;
    for (auto it : nums)
    {
        if (it != 0)
            tmp.push_back(it);
    }
    for (auto it : nums)
    {
        if (it == 0)
            tmp.push_back(it);
    }
    nums = tmp;
}

// in place solution optimal
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[k] = nums[i];
            k++;
        }
    }
    for (k; k < n; k++)
        nums[k] = 0;
}

// another optimal form , O(n)
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = -1;

    // lets find the first possible 0 , to start the swapping process
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    // if I find none 0's
    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        // let's swap the position of the 0's to end alwayyyyyys
        if (nums[i] != 0) // the first guy not 0
        {
            swap(nums[i], nums[j]);
            // move j forward to first next 0 , I gurantee that from my condition
            j++;
        }
    }
}
