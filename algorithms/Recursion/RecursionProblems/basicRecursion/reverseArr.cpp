#include <bits/stdc++.h>

using namespace std;
// First way to think
void reverseArr(vector<int>&arr,int i, int j)
{
    if (i>=j) return;
    swap(arr[i],arr[j]);
    reverseArr(arr,i+1,j-1);
}
// let's get rid off one of the pointers and get it with the other
void reverseArr1(vector<int> &arr, int i, int n)
{
    if (i >= n/2)
        return;
    swap(arr[i], arr[n-i-1]);
    reverseArr(arr, i + 1, n);
}
int main()
{
    vector<int> arr { 1, 2, 3,4,5 };
    int n = arr.size() - 1;
     reverseArr(arr, 0, n);
    for(auto it:arr)
    cout<<it<<" ";
}