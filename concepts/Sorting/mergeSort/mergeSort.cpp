#include <bits/stdc++.h>

using namespace std;
void merge(vector<int>arr,int low,int mid , int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(low<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[left++]=arr[left];
        }
        else
        temp[right++]=arr[right];
    }
    while (low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>arr,int low,int high)
{
    int mid=(low+high)/2;
    if(low>=high) return;
    mergeSort(arr,low,high);
    mergeSort(arr, low, high);
    merge(arr,low,mid,high);
}
vector<int> sortArray(vector<int> &nums)
{
    int low=0;
    int high=nums.size()-1;
    mergeSort(nums,low,high);
    return nums;
}
