#include <bits/stdc++.h>

using namespace std;
void shellSort(vector<int> &arr)
{
    int n = arr.size();
    // start the gap with n/2
    for (int gap = n / 2; gap > 0; gap /= 2) // keep dividing gap by 2
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}
int main()

{
    vector<int> arr{1, 9, 5, 7, 3, 70, 2, 0};
    shellSort(arr);
    for (auto it : arr)
        cout << it << " ";
}