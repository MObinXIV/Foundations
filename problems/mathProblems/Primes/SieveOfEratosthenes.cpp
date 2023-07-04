#include <bits/stdc++.h>

using namespace std;

int N=1e6;
int seive[1000001];

void createSeive(int n)
{

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = 0;

    for (long long i = 2; i * i <= n; ++i)
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

// 1st intuition 

int main()
{
    cout<<N;
}