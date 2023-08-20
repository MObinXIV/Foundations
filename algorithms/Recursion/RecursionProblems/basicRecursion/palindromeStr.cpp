
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int i, string &s, int j)
{
    if (i >= j)
        return true;
    while (!isalnum(s[i]))
        i++;
    while (!isalnum(s[j]))
        j--;
    if (tolower(s[i]) != tolower(s[j]))
        return false;
    return isPalindrome(i + 1, s, j - 1);
    
}
bool isPalindrome(int i , string &s)
{
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return isPalindrome(i + 1, s);
    }
// https://leetcode.com/problems/valid-palindrome/description/
bool isPalindrome(string s)
{
    // return isPalindrome(0,s,s.size()-1);
    int i =0,n=s.size()-1;
    while (i<=n)
    {
        if(!isalnum(s[i])){i++; continue;}
        if (!isalnum(s[n]))
        { n--;
            continue;}
            if(tolower(s[i])!=tolower(s[n])) return false;
            else{
                n--;
                i++;
            }
    }
    return true;
    
}
int main()
{
    string s;
    cin>>s;
    bool f= isPalindrome(s);
    cout<<f<<endl;

}