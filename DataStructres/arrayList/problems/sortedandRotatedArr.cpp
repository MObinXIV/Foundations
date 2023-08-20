// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#include <bits/stdc++.h>

using namespace std;

/*
Compare all neignbour elements (a,b) in A,
the case of a > b can happen at most once.

Note that the first element and the last element are also connected.

If all a <= b, A is already sorted.
If all a <= b but only one a > b,
we can rotate and make b the first element.
Other case, return false.
*/
bool check(vector<int> &arr)
{
    int n = arr.size();
    int a = 0; // I think it's to check the rotation beginning
    for (int i = 0; i < n; i++)
    {
        // if(arr[i]>arr[(i+1)%n] && a > 1) can write it like that by the way
        if (arr[i] > arr[(i + 1) % n]) // check each element and also last element and first element
            a++;

        // the case of a > b can happen at most once (as we , only can rotate once)
        if (a > 1)
            return false; // if I break that ,then it can't be orignally sorted and rotate once
    }

    return true;
}
