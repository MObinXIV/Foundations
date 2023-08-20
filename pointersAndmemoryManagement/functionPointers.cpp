#include <iostream>

using namespace std;
int add(int a, int b)
{
    return a + b;
}
int main()
{
    // write pointer to function that should take , and args after
    int (*p)(int, int);
    // p = &add;
    p = add; // function name 'll return us a pointer
    // int c = (*p)(2, 3);
    int c = p(2, 3);
    cout << c << endl;
}