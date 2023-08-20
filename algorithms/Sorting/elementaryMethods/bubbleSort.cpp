// push the maximum to the last by adjacent swaps
// T.C-> O(n^2)
#include <bits/stdc++.h>

using namespace std;
void bubble_Sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i > 0; i--)
    {
        int didSwap=0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
               { swap(arr[j], arr[j + 1]);
                didSwap=1;
               }
        }
        if(didSwap==0)
        break;
    }
}
void recursiveBubble(int n, vector<int> &arr,bool didSwap)
{
    if (n == 1 || !didSwap)
    {
        return;
    }

    // code recursive step
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
        swap(arr[i], arr[i + 1]);
        didSwap = 1;
        }
    }
    
        recursiveBubble(n - 1, arr, didSwap);
}