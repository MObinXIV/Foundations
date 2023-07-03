#include <iostream>

using namespace std;
void prime1(int n)
{
    // bool f = false;
    // for (int i = 2; i < n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         f = true;
    //         break;
    //     }
    // }
    // if (f == true)
    //     cout << "Not Prime \n";
    // else
    //     cout << "Prime \n";

    // other intuition using similar idea

    /*
    here we assume that if the number has only 2 factors (number and 1) that means it's prime
    */
   int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
           cnt++;
        }
    }

        if (cnt==2)
        cout<<"Prime \n";
        else
        cout<<"Not Prime \n";
    
}
int main()
{
    int n ;
    cout<<"Please enter the number \n";
    cin>>n;
    prime1(n);
}