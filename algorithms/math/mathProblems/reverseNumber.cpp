#include<bits/stdc++.h>

using namespace std;
// leetcode problem
int reverse(int x) {
         long rev=0; 
        while (x!=0)
        {
            rev = rev*10 +x%10;
            
             x/=10;
            
             if( rev >INT_MAX|| rev < INT_MIN)
                return 0; 
            
        }
        return (int) rev;
    }
int main()
{
    int n;
    cin>>n;
    int revNum=0;
    while(n>0)
    {
        int r = n%10;
        revNum=revNum*10+r;
        n/=10;
    }

    cout<<revNum<<endl;
}