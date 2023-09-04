#include <iostream>
using namespace std;
int *add(int *a, int *b)
{
    int *c = new int;
    *c = *a + *b;
    return c;
}
int main()
{
    int a = 2;
    int b = 3;
    int *ptr = add(&a, &b);
    cout << *ptr << endl;
    delete ptr;
}

#include <iostream>
using namespace std;

int add(int *a, int *b)
{

    // Add the two integers pointed to by a and b.
    int sum = *a + *b;

    // Return the sum.
    return sum;
}

int main()
{

    // Create two integer variables.
    int a = 2;
    int b = 3;

    // Call the add() function, passing in the addresses of the two integer
    // variables.
    int sum = add(&a, &b);

    // Print the value of the sum.
    cout << "The sum is: " << sum << endl;

    return 0;
}
