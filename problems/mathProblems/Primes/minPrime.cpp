// The problem -> we want to count the numbers than our number is minimum prime number on them

#include <bits/stdc++.h>
using namespace std;
/*
we count all the numbers that our number can create and be minimal
so we start with 2 -> 1e6
mark all factors for example mark all the factors with 2 and count them into 2 index while so we marking them with 0 to not be counted again in 3 or any other number phase
at the end we return our indicated number 
*/
int  createSeive(int n)
{

    vector<int> primes(1e6+ 1, 1);
    primes[0] = primes[1] = 0;

    for (long long i = 2; i * i <= 1e6; ++i)
    {
        if (primes[i]==1)
        {
            for (int j = i * i; j <=1e6; j += i)
            {
               if(primes[j]!=0) // if the number is not marked yet
               {primes[i]++; //count it to my current guy
               primes[j]=0;// mark it with 0 to be not counted again 
               }
            }
        }
    }

    return primes[n];
}

int main()
{
    int n;
    cin>>n;
    int res=createSeive(n);
    cout<<res<<endl;
}