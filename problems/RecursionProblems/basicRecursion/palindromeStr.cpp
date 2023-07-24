#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i , string s, int j)
{
    if(i>=j) return true;
    while(!isalpha(s[i])) i++;
    while (!isalpha(s[j]))
        j--;
    if(tolower(s[i])==tolower(s[j]))
    return isPalindrome(i+1,s,j-1);
    else 
    {
        return false;
    }
}
bool isPalindrome(string s)
{
    int i=0,j=s.size()-1;
    return isPalindrome(i,s,j);
}
int main()
{
    string s;
    cin>>s;
    bool f= isPalindrome(s);
    cout<<f<<endl;

}