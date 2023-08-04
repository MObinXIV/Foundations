// 1- pick a pivot & place in correct place in a sorted array
// 2- Smaller on the left and larger on the right
// Tc-> O(n*log(n))
// doesn't use extra space to store unlike mergeSort
#include <bits/stdc++.h>

using namespace std;
int partition(vector<int>&arr,int low, int high)
{
    int pivot = arr[low];
    int i = low,j=high;
    while(i<j)
    {
        // this grantee I 'll find the first element greater than my pivot
        while(arr[i]<=pivot && i<high)
        i++;
        // this grantee I 'll find the first element lesser than my pivot
        while(arr[j]>=pivot && j>low)
        j--;
        
        // swap them to make the left of the pivot less than him and the right bigger than him
        if(i<j) 
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>&arr,int low , int high)
{
    if(low<high)
    {
        int pIndex=partition(arr,low,high);
        // Sort the left guy after the pivot
        quickSort(arr, low, pIndex - 1);
        // Sort the right guy after the pivot
        quickSort(arr, pIndex+1, high);
    }
}
