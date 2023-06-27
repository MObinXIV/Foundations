#include<iostream>

using namespace std;

int main()
{
    int t; 
    cout<<"enter the number of levels\n";
    cin>>t;
   
    for (int i =0;i<t;i++)
    {
        // Space 
        for (int j =i;j<t;j++)
        cout<<" ";

        // Stars 
        for(int k = 0 ; k< i*2+1;k++)
        cout<<"*";

        // Space
        for (int j = 0; j < t; j++)
        cout << " ";
        cout<<endl;
    }
}

