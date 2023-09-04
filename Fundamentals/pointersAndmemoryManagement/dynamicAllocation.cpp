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


///2d 

// note that the rows part is n't dynamic so we first specify that then dynamically assign columns

#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter ther number of rows and columns\n";
    cin >> rows >> cols;
    // create array of arrays
    int **table = new int *[rows]; // inialize the number of rows in the table

    // for each row 're going to create the column
    for (int i = 0; i < rows; i++)
        table[i] = new int[cols]; // for each row assign cols number of columns

    // some code
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> table[i][j];
    cout << "-------------" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // deallocation steps

    // step.1 -> deallocate the columns in each row , by delete every element in cols

    for (int i = 0; i < rows; i++)

        delete[] table[i]; // go to every row and delete it columns (the elements in each row)

    // 2. delete the empty row pointers
    delete[] table;
    // make the table pointer itself points to null , prevent some errors , but maybe not used 
    table = NULL;
}
