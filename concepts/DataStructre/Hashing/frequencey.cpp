#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n;
    cin>>n;//5
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    cin>>arr[i];

    // precompute

    vector<int>hash(n,0);
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]+=1;
    }
    int q;
    cout << "Enter the number of queries U want\n";
    cin>>q;
    while(q--)
    {
        int number;
        cout<<"Enter the number U wanna to to get it frequency \n";
        cin>>number;
        // fetch
        cout<<hash[number]<<endl;

    }
}