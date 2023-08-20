// get the minimum & swap it
// O(n^2)
#include <bits/stdc++.h>

using namespace std;
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    vector<int>sortedArr;
    int mini;
    for (int i =0 ; i<n-1;i++)
    {
        mini = i;
        for (int j = i ; j<n;j++)
        {
            if(arr[mini]>arr[j])
            mini=j;
        }
        swap(arr[mini],arr[i]);
        
    }
}
