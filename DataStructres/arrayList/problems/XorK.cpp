#include <bits/stdc++.h>

using namespace std;
// O(n^2) brute force solution
int subarraysWithXorK(vector<int> &arr, int b)
{
    int n = arr.size();
    int cnt = 0;
    // subArr generating
    for (int i = 0; i < n; i++)
    {
        int xori = 0;
        for (int j = 0; j < n; j++)
        {
            xori ^= arr[j];
        }
        if (xori == b)
            cnt++;
    }
    return cnt;
}

// O(n)
int subarraysWithXorK(vector<int> &arr, int b)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int Xr = 0;
    mp[Xr]++; // to insert 0 in the map to use it
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        Xr ^= arr[i];
        // let's find if I got the element when I xor Xr with k
        int x = Xr ^ b;
        if (mp.find(x) != mp.end())
            cnt += mp[x];
        mp[Xr]++;
    }

    return cnt;
}