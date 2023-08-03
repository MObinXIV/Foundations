// push the maximum to the last by adjacent swaps
// T.C-> O(n)
#include <bits/stdc++.h>

using namespace std;
void bubble_Sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
int main()

{
    vector<int> arr{1, 9, 5, 7, 3, 2};
    bubble_Sort(arr);
    for (auto it : arr)
        cout << it << " ";
}