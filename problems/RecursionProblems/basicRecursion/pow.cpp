#include <bits/stdc++.h>

using namespace std;
// first solution -> O(n)
int myPow(double x, int n)
{
    if (n == 0)
        return 1;
        return x*myPow(x,n-1);
    
}
// The optimized one ->O(log n)
int myPow(double x, int n)
{
        if (n == 0)
        return 1;
        return n % 2 ? myPow(x, n / 2) * myPow(x, n / 2) * x : myPow(x, n / 2) * myPow(x, n / 2);
}
int main()

{
    cout<<myPow(2,4);
}

