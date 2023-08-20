#include <bits/stdc++.h>

using namespace std;

int secondLargest(vector<int> &arr, int n)
{
    int secondLarge, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            secondLarge = maxi;
            maxi = arr[i];
        }
        else if (arr[i] < maxi && secondLarge < arr[i])
            secondLarge = arr[i];
    }

    return secondLarge;
}
int secondSmallest(vector<int> &arr, int n)
{
    int secondSmall, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
        {
            secondSmall = mini;
            mini = arr[i];
        }
        else if (arr[i] > mini && secondSmall > arr[i])
            secondSmall = arr[i];
    }

    return secondSmall;
}
vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    vector<int> res;
    int secMax, secMin;

    secMax = secondLargest(arr, n);
    secMin = secondSmallest(arr, n);
    res.push_back(secMax);
    res.push_back(secMin);

    return res;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{

    /*
    we do the loops to check the equality case
    for example -> 1,2,3,5,5   here we get 2 of 5s , but the second biggest value is 3
    */
    sort(a.begin(), a.end());
    vector<int> res;
    int maxi = a[a.size() - 1], mini = a[0];
    int secMax, secMin;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < maxi)
        {
            secMax = a[i];
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] > mini)
        {
            secMin = a[i];
            break;
        }
    }
    res.push_back(secMax);
    res.push_back(secMin);

    return res;
}
