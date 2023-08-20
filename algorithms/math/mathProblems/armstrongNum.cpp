#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    -extract digits 
    - assign sum for digit^3
    */
    int n;
    cout<<"Please enter a number\n";
    cin >> n;
    int sum = 0;
    int x =n;
    while (x > 0)
    {
        int r = x % 10;
        sum+= pow(r,3);
        x /= 10;
    }
    if (n==sum)
    cout<<"Armstrong\n";
    else
    cout<<"NOT\n";
}