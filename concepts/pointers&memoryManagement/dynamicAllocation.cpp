#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "enter the size of array \n";
    cin >> n;
    int *p;

    // allocate the memory
    p = new int[n];
    cout << "Enter the elements of array \n";
    for (int i = 0; i < n; i++)
        cin >> *(p + i);
    cout << "elements\n";
    for (int i = 0; i < n; i++)
        cout << *(p + i) << " ";
    cout << endl;

    delete[] p; // delete the array to free the memory
}

