#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
//     int cnt=0;
//    while(n>0)
//    {
//     n/=10;
//     cnt++;
//    }
        cout <<int(log10(n))<<endl;
        int cnt = int (log10(n)+1);
   cout<<cnt;
}