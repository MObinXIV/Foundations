#include<iostream>

using namespace std;

int main()
{
    int k =1;
    int l=4;// l=i-1
    for (int i =1;i<=5;i++)
    {
        for(int h  = 0 ;h<l;h++)
        cout<<" ";
        for (int j = 1;j<=k;j++)
        cout<<"*";
        cout<<endl;
        k+=2;
        l--;
    }
}