// https://leetcode.com/problems/rotate-array/description/
#include <bits/stdc++.h>

using namespace std;
// right rotation

void rotate(int nums[], int n, int k)
{
    if ((n == 0) || (k <= 0))
    {
        return;
    }

    // Make a copy of nums
    vector<int> numsCopy(n);
    for (int i = 0; i < n; i++)
    {
        numsCopy[i] = nums[i];
    }

    // Rotate the elements.
    for (int i = 0; i < n; i++)
    {
        nums[(i + k) % n] = numsCopy[i];
    }
}

// Optimal observation

void reverse(vector<int> &arr, int l, int r)
{

    while (l < r)
    {
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++, r--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    int r = n - 1;
    reverse(nums, 0, r);
    reverse(nums, 0, k - 1);
    reverse(nums, k, r);
}

// Brute force for left rotation
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n; // simply to eliminate the fixed n rotations for example if array is 7 and we get k as 8 rotations , so we rotate it only 1 at the end
    vector<int> tmp(k);
    for (int i = 0; i < k; i++)
    {
        tmp[i] = nums[i];
    }
    // push elements
    for (int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    }

    // put back tmp
    for (int i = n - k; i < n; i++)
    {
        nums[i] = tmp[i - (n - k)]; // simply here , I treat (n-k) as my 0 , then I increment by i after that
    }
}

// Optimal left rotation

vector<int> rotateArray(vector<int> arr, int k)
{

    vector<int> ans;

    int n = arr.size();

    reverse(arr.begin(), arr.begin() + k);

    reverse(arr.begin() + k, arr.begin() + n);

    reverse(arr.begin(), arr.begin() + n);

    for (int i = 0; i < arr.size(); i++)

    {

        ans.push_back(arr[i]);
    }

    return ans;
}
