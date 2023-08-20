#include <bits/stdc++.h>

using namespace std;

// sorting solution -> nlogn
// optimal -> O(n)
int largestElement(vector<int> &arr, int n)
{
    int maxi = -1e9;
    for (int &it : arr)
        maxi = max(it, maxi);

    return maxi;
}
