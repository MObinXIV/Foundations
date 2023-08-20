// https://codeforces.com/problemset/problem/1294/C

#include <bits/stdc++.h>

using namespace std;
/*
we keep get the minimum values using greedy approach
*/
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        set<int> used;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0 && !used.count(i))
            {
                used.insert(i);
                n /= i; // till second factor
                break;
            }
        }
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0 && !used.count(i))
            {
                used.insert(i);
                n /= i;//till second factor
                break;
            }
        }
        if (int(used.size()) < 2 || used.count(n) || n == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            used.insert(n);
            for (auto it : used)
                cout << it << " ";
            cout << endl;
        }
    }
    
    }