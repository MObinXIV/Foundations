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

void pattern5(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
            cout << "*";
        cout << endl;
    }
}

void pattern6(int n)
{
    int start=1;
    for (int i =0;i<n;i++)
    {
        if(i%2==0) start=1;
        else start =0;
        for(int j =0;j<i;j++)
        {
            cout<<start;
            start=1-start;
        }
    cout<<endl;
    }
}

void pattern7(int n){
    int num=1;

    for (int i = 1 ; i<=n;i++)
    {
        for (int j=1;j<=i;j++){
            cout<<num<<" ";
            num+=1;
        }
        cout<<endl;
    }
}

void pattern8(int n)
{
    for  (int i=0;i<n;i++)
    {
        for (char ch='A';ch <='A'+i;ch++)
        cout<<ch;
        cout<<endl;

    }
}

void pattern9(int n){
    for (int i =0;i<n;i++)
    {
        for (char ch='A';ch<='A'+(n-i-1);ch++)
        cout<<ch<<" ";
        cout<<endl;
    }
}
void pattern10(int n){
    char ch='A';
    for (int i =0;i<n;i++)
    {
        for(int j =0;j<=i;j++)
        cout<<ch;
        ch++;
        cout<<endl;
    }
}
void pattern11(int n){
    for (int i =0;i<n;i++)
    {
        //space 
        for(int j = 0 ; j<n-i-1;j++)
        cout<<" ";

    char ch='A';
        // breakPoint idea
        int breakPoint = (2*i+1)/2;
        for (int j =1;j<=2*i+1;j++)
        {
        cout << ch;
        if (j <= breakPoint)
            ch++;
        else
            ch--;
        }

        for (int j = 0; j < n - i - 1; j++)
        cout << " ";
        cout <<endl;
    }
}

void pattern12(int n){
    for (int i=0;i<n;i++)
    {
        for (char ch ='E'-i;ch<='E';ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern13(int n){
    int sp=0;
    for (int i = 0;i<n;i++)
    {
        //stars -> we print (n-i) stars

        for (int j =1;j<=(n-i);j++)
        cout<<"*";

        //spaces
        for(int j=0;j<sp;j++)
        cout<<" ";

        // stars

        for (int j = 1; j <= (n - i); j++)
        cout << "*";
        sp += 2;

        cout<<endl;
    }
    sp =2*n-2;
    for (int i =1;i<=n;i++){
        // stars -> we print (n-i) stars

        for (int j = 1; j <=i; j++)
        cout << "*";

        // spaces
        for (int j = 0; j < sp; j++)
        cout << " ";

        // stars

        for (int j = 1; j <=i; j++)
        cout << "*";
        sp -= 2;

        cout << endl;
    }
}

void pattern14(int n){
    int sp = 2 * n - 2;
    for (int i=1;i<2*n-1;i++){
        //stars
        int stars=i;

        if (i>n) // break the half point
        stars=2*n-i;

        for (int j =1;j<=stars;j++)
        cout<<"*";

        //spaces
        for (int j = 1; j <= sp; j++)
        cout << " ";
        //stars
        for (int j = 1; j <= stars; j++)
        cout << "*";

        cout <<endl;

        if(i<n) sp-=2;
        else
        sp+=2;
    }
}
void pattern15(int n)
{
    for (int i =0;i<n;i++)
    {
        if(i==0 || i==n-1){
            for (int j =0;j<n;j++)
            cout<<"*";
            cout<<endl;
        }
        else{
            cout<<"*";
            int sp=n-2;
            for (int j =1;j<=sp;j++)
            cout<<" ";
            cout<<"*";
            cout<<endl;
        }
    }
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

//    pattern14(5);

pattern15(6);
}

