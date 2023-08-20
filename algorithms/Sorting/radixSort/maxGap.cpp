// https://leetcode.com/problems/maximum-gap/description/
//  I first try to use radix sort
#include <bits/stdc++.h>

using namespace std;
int getMax(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(vector<int> &arr, int div)
{
    vector<int> output(arr.size());
    vector<int> count(10, 0); // hash the digits from 0->9
    int n = arr.size();
    for (int i = 0; i < n; i++)
        count[(arr[i] / div) % 10]++; // increment the count of the current digit

    // accumulative sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i]; // store the output of digit count
        count[(arr[i] / div) % 10]--;                    // decrement it's hash
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr)
{
    int m = getMax(arr);
    for (int div = 1; m / div > 0; div *= 10)
        countingSort(arr, div);
}

int maximumGap(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;
    radixSort(nums); // sort the array
    int n =nums.size();
    int gap =0;
    for (int i = 1 ; i<n;i++)
        gap=max(nums[i]-nums[i-1],gap);
        
    return gap;
}