#include <bits/stdc++.h>

using namespace std;

// void printDivisors(int n)
// {
//     for(int i=1;i<n;i++)
//     if(n%i==0)
//     cout<<i<<" ";

// }

// divisors second approach observation

/*
- we observe that , the divisors of number are 2 number
- first number is the number we get 
- second number is our number divided by the first number , if the 2 numbers are n't same (6*6)
- we loop through only sqrt(n) , as after it the numbers 'll grow , and 'll get them again

*/


void printDivisors (int n){
    vector <int>v;
    for (int i = 1; i < sqrt(n); i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if (n/i!=i)
            v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    for (auto it:v)
    cout<<it<<" ";
}
int main()
{
    printDivisors(36);
}