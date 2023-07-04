#include <bits/stdc++.h>

using namespace std;
bool prime1(int n)
{
    bool f = false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            f = true;
            break;
        }
    }
    return f;
   
    
}

int  prime2(int n)
{
    /*
   here we assume that if the number has only 2 factors (number and 1) that means it's prime
   */
    int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cnt++;
    //     }
    // }

    // if (cnt == 2)
    //     cout << "Prime \n";
    // else
    //     cout << "Not Prime \n";

    // better optimization , from the square root idea idea
    // for (int i = 1; i <= sqrt(n); i++)
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;

            if(n/i !=i) // the other factor to get n is not the same as i
            cnt++;
        }
    }

    // if (cnt == 2)
    //     cout << "Prime \n";
    // else
    //     cout << "Not Prime \n";
    return cnt;
}


int main()
{
    // int n ;
    // cout<<"Please enter the number \n";
    // cin>>n;
    // prime2(n);

    
}