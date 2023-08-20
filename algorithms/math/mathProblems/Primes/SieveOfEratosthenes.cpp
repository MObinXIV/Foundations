#include <bits/stdc++.h>

using namespace std;

// 1st intuition
void createSeive1(int n)
{

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = 0;

    for (long long i = 2;  i <= n; ++i)
    {
        if (primes[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

// 1st optimization -> is we begin from i*i as we got the multiples 
// second optimization -> running till sqrt 
// Time complexity -> O(n log(log n))
void createSeive(int n)
{

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = 0;

    for (long long i = 2; i * i <= n; ++i)
    {
        if (primes[i])
        {
            for (int j = i *i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}


int main()
{
    createSeive(5);
}