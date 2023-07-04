// https://codeforces.com/problemset/gymProblem/102267/B#:~:text=A%20prime%20number%20is%20a,such%20pair%20of%20primes%20exists.
#include <bits/stdc++.h>

using namespace std;
bool prime1(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
           return false;
        }
    }
    return true;
   
    
}
int main()
{
    int n ;
    cin>>n;

    if (prime1(n - 2))
    {
        cout << 2 << " " << n - 2 << endl;
        
    }
    else 
    {
        cout << -1 << endl;
    }
    
}