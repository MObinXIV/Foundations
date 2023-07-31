#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    cin>>arr[i];

    //pre-compute
    unordered_map<int, int> mpp;
    for(int i =0;i<n;i++)
    mpp[arr[i]]++;

    int q;
    cout<<"Enter the number of queries U wanna execute\n";
    cin>>q;
    while (q--)
    {
        int num;
        cout<<"Enter a number U wanna see it's frequency\n";
        cin>>num;
        cout<<mpp[num];
    }
    

}