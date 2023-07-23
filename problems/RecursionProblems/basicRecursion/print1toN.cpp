#include <iostream>
#include <vector>
using namespace std;

// the logic without using vector 

void print(int x)
{
    if(x<1) return;

    // forcing the function to print using backtrack
    print(x-1); // I 'll keep going till I reach the base case 
    cout<<x<<" ";
}


vector<int> printNosRecursive(int x)
{
    if (x <= 0)
    {
        return {}; // Base case: Return an empty vector when x becomes 0 or negative
    }

    vector<int> numbers = printNosRecursive(x - 1); // Recursive call with a smaller value of x
    numbers.push_back(x);                           // Add the current value of x to the vector

    return numbers; // Return the vector containing the numbers from 1 to x
}

int main()
{
    int n;
    cout << "Enter a number: ";
    // cin >> n;

        print(5);
    // vector<int> result = printNosRecursive(n);

    // cout << "Numbers from 1 to " << n << ": ";
    // for (int num : result)
    // {
    //     cout << num << " ";
    // }
    // cout << endl;

    return 0;
}
