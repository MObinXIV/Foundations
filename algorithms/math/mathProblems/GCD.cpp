#include <bits/stdc++.h>

using namespace std;

// gcd -> recursion approach , using eculdian way
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a,b;
    cout<<"enter 2nums\n";
    cin>>a>>b;
    gcd(a,b);
    // int gcd =1;
    // for (int i=2;i<min(a,b);i++)
    // {
    //     if (a%i==0 && b%i==0)
    //     gcd =i;
    // }


// more elegant way
    // for (int i =min(a,b);i>1;i--)
    // {
    //     if(a%i==0 && b%i==0)
    //     {
    //         gcd=i;
    //         break;
    //     }
    // }
    // cout<<gcd<<endl;
}