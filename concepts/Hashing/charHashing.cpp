#include <bits/stdc++.h>

using namespace std;

int main()

{
   string s;
   cin>>s;
    

    // precompute

    vector<int> hash(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]-'a']++;
    }
    int q;
    cout << "Enter the number of queries U want\n";
    cin >> q;
    while (q--)
    {
        char c;
        cout << "Enter the number U wanna to to get it frequency \n";
        cin >> c;
        // fetch
        cout << hash[c-'a'] << endl;
    }
}