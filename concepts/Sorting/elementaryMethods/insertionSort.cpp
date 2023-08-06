// take an element and place in it's correct order
// O(n^2)
#include <bits/stdc++.h>

using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

void recursiveInsertion(int ind ,vector<int>&arr)
{
    if(ind==arr.size())
    {
        return;
    }
    int j = ind;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
        j--;
    }
    recursiveInsertion(ind+1,arr);
}
