// https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>

using namespace std;

/*
-1st type of problems:Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
- we observe that if we have ncr for example 7c2 it= 7*6/2*1 and so on so force ncr=n*n-1..r times / r*r-1..r times
*/

int nCr(int n, int r)
{

    // calculating ncr
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    return element;
}

// The second variation is to print any given row

// the brute force solution is to use the formula to print every element in the row ->O(n*r)

void pascalTriangle(int n)
{
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "\n";
}

// optimal solution -> we observe that , the ans is the ans of the previous col *(row-col)/col, O(n)
void pascalTriangle(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int c = 1; c < n; c++)
    {
        ans = ans * (n - c);
        ans /= c;
        cout << ans << " ";
    }
    cout << endl;
}

// the 3rd is leetcode problem

// naive -> O(n^3)
vector<vector<int>> pascal(int n)
{
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++)
        {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

vector<int> generateRow(int row)
{
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans *= (row - col);
        ans /= col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

// dp tabulation solution
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> r(numRows);
    for (int i = 0; i < numRows; i++)
    {
        // mak the size of the current  row of the size of pascal
        r[i].resize(i + 1);
        // I gurante that every begin is 1
        r[i][0] = r[i][i] = 1;
        for (int j = 1; j < i; j++)
            // generate the triangle
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    return r;
}