#include <bits/stdc++.h>

using namespace std;

// the first solution is the linear search solution -> O(n^2)

int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // let's search for i , in the whole array
        bool f = 0;
        for (int j = 0; j < n; j++)
        {
            // let's check if there's an i
            if (nums[j] == i)
            {
                f = 1; // mark as found
                break;
            }
        }
        if (f == 0)
            return i;
    }
    // if it's not anyone in the array then it's the last one
    return n;
}
// Sorting -> O(nlogn)+O(n)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int x;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            x = i;
            break;
        }
    }
    return x;
}
// hashing approach -> O(2n)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    int i;
    for (i = 0; i < n; i++)
    {
        if (!mp.count(i))
        {
            break;
        }
    }

    return i;
}

// sum trick -> the supposed sum - the real sum , O(n)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2; // sum formula
    int s = 0;
    for (auto it : nums)
        s += it;
    return sum - s;
}

// O(nlogn)+O(logn)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // Initialize the left and right pointers.
    int left = 0, right = n;

    // Loop until the left pointer is equal to the right pointer.
    while (left < right)
    {

        // Calculate the middle index.
        int mid = (left + right) / 2;

        // If the element at the middle index is greater than the middle index, then the missing number is in the left half of the array.
        if (nums[mid] > mid)
        {
            right = mid;
        }

        // Otherwise, the missing number is in the right half of the array.
        else
        {
            left = mid + 1;
        }
    }

    // Return the left pointer, which is the index of the missing number.
    return left;
}

// Xor trick ->O(n)
int missingNumber(vector<int> &nums)
{
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        // they 'll cancel each other and I 'll get my only element guy
        res ^= nums[i];
        res ^= i;
    }
    return res;
}
