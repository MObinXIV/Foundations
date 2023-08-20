#include <bits/stdc++.h>

using namespace std;
void combine(int i, int n, vector<int> &ds, vector<vector<int>> &ans, int k)
{
    if (i > n) // if I cross the line
    {
        if (k == 0)
            ans.push_back(ds);
        return;
    }
    ds.push_back(i);
    combine(i + 1, n, ds, ans, k - 1);
    ds.pop_back();
    combine(i + 1, n, ds, ans, k);
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combine(1, n, ds, ans, k);
    return ans;
}
int main()

{

    vector<vector<int>> ans = combine(4, 2);
    for (auto vect1D : ans)
    {
        for (auto x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}