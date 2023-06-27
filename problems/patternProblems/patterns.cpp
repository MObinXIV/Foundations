#include <iostream>

using namespace std;
void pattern1( int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < n-i-1; j++)
            cout << " ";

        // Stars
        for (int k = 0; k < i * 2 + 1; k++)
            cout << "*";

        // Space
        for (int j = 0; j < n-i-1; j++)
            cout << " ";
        cout << endl;
    }
}

void pattern3 (int n){
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < i; j++)
            cout << " ";

        // Stars
        for (int k =0 ; k < 2 * n - (2 * i + 1); k++)
            cout << "*";

        // Space
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << endl;
    }
}

void pattern4(int n){
    pattern2(n);
    pattern3(n);
}
int main()
{
    // int t; 
    // cin>>t;

    // for (int i =0;i<t;i++)
    // {
    //     int n ; 
    //     cin>>n;
    // }
    
}

