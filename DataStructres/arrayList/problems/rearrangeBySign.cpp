// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
#include <bits/stdc++.h>

using namespace std;

// Brute force -> O(n)+O(n/2)
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> negArr, posArr;
    for (auto it : nums)
    {
        if (it < 0)
            negArr.push_back(it);
        else
            posArr.push_back(it);
    }
    int n = nums.size();
    for (int i = 0; i < n / 2; i++)
    {
        nums[i * 2] = posArr[i];
        nums[i * 2 + 1] = negArr[i];
    }
    return nums;
    // int l=0,r=0;
    // vector<int>res;
    // while(l<posArr.size() && r<negArr.size())
    // {
    //     res.push_back(posArr[l]);
    //     res.push_back(negArr[r]);
    //     l++;
    //     r++;
    // }
    // return res;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int posInd = 0, negInd = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            ans[negInd] = nums[i];
            negInd += 2;
        }
        else
        {
            ans[posInd] = nums[i];
            posInd += 2;
        }
    }

    return ans;
}

// another variety of the problem , here we aren't gurantee equality
// https://www.codingninjas.com/studio/problems/alternate-numbers_6783445

#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n)
{

    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++)
    {

        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    // If positives are lesser than the negatives.
    if (pos.size() < neg.size())
    {

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for (int i = 0; i < pos.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        // Fill the remaining negatives at the end of the array.
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {

            A[index] = neg[i];
            index++;
        }
    }

    // If negatives are lesser than the positives.
    else
    {

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for (int i = 0; i < neg.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        // Fill the remaining positives at the end of the array.
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {

            A[index] = pos[i];
            index++;
        }
    }
    return A;
}