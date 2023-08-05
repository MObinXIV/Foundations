#include <bits/stdc++.h>

using namespace std;
void recursiveBubble(int n, vector<int> &arr, bool didSwap)
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
int main()

{
    vector<int>arr{6,4,8,7,0,-8};
    recursiveBubble(6,arr,1);
    for (int &it:arr)
    cout<<it<<" ";
}
/*
#include <bits/stdc++.h>

using namespace std;

int main()

{

}
*/