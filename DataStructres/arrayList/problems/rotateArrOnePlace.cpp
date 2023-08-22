// https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278?leftPanelTab=1
#include <bits/stdc++.h>

using namespace std;
// rotate the array by one place
vector<int> rotate(vector<int> &arr, int n)
{
    int tmp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = tmp;
    return arr;
}
