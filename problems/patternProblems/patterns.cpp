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
        for (int j = i; j < n; j++)
            cout << " ";

        // Stars
        for (int k = 0; k < i * 2 + 1; k++)
            cout << "*";

        // Space
        for (int j = 0; j < n; j++)
            cout << " ";
        cout << endl;
    }
}
int main()
{
    int t; 
    cin>>t;

    for (int i =0;i<t;i++)
    {

    }
}