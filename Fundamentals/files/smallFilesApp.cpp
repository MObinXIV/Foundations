/*Data that is formatted and written to a sequential file as shown in
Section 14.3 cannot be modified without the risk of destroying other
data in the file*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define TEXT_FILE_PATH "data/data.txt"
#define BIN_FIE_PATH "data/data.bin"

enum class Options
{
    Add = 1,
    View = 2
};
typedef struct
{
    string name;
    double salary;
    string position;
} Employee;

// for binary file
void addToBin(Employee emp, string filePath)
{
    ofstream myFile; // intialize a file to write in
    myFile.open(filePath, ios::out | ios::app | ios::binary);
    myFile.write((char *)&emp, sizeof(emp));
    myFile.close();
    cout << "--> Record is added to file\n";
}
vector<Employee *> readBinFile(string filePath)
{
    vector<Employee *> fileEmployee;
    string line;
    try
    {
        ifstream myfile(filePath, ios::in | ios::binary | ios::ate); // ios::ate put the pointer at the end of file
        if (myfile.is_open())
        {
            /*
            -get an array of the size of the file
            - move the pointer to the beginning of the file
            - read the data from the file
            */
            streampos size = myfile.tellg(); // get the size of the file by the pointer ate we replaced at the end file
            char *memlock = new char[size];  // create an array of the size of file's data
            myfile.seekg(0, ios::beg);       // place the pointer in the beginning of the file
            myfile.read(memlock, size);      // store all file data on this buffer
            myfile.close();
            long long byteIndex = 0;
            while (byteIndex < size)
            {
                Employee *emp = (Employee *)(memlock + byteIndex);
                fileEmployee.push_back(emp);
                byteIndex += sizeof(Employee); // move by employee block
            }
        }
        else
        {
            cout << "--> Unable to open file";
        }
    }
    catch (exception &e)
    {
        cout << "--> Standard exception: " << e.what() << endl;
    }

    return fileEmployee;
}
void addToBin()
{
    string txt;
    int options;
    while (true)
    {
        cout << "-->\n1- Add new record\n2-view records \nAny other key to exit\n";
        cin >> options;
        if (options == (int)Options::Add)
        {
            Employee employee;
            cout << "employee name: ";
            std::cin >> std::ws;
            getline(cin, employee.name);

            cout << "employee position: ";
            getline(cin, employee.position);

            cout << "employee salary: ";
            cin >> employee.salary;

            addToBin(employee, BIN_FIE_PATH);
        }
        else if (options == (int)Options::View)
        {
            cout << "\n============= FileContent =============\n";
            vector<Employee *> fileLines = readBinFile(BIN_FIE_PATH);
            for (auto line = fileLines.begin(); line != fileLines.end(); line++)
            {
                Employee *employee = *line;
                cout << "employee->name: " << employee->name << "\n";
                cout << "employee->position: " << employee->position << "\n";
                cout << "employee->salary: " << employee->salary << "\n";
                cout << "\n-----------\n";
            }
        }
        else
        {
            break;
        }
    }
}
int main()
{
    addToBin();
}