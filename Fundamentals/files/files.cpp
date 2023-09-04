/*Data that is formatted and written to a sequential file as shown in
Section 14.3 cannot be modified without the risk of destroying other
data in the file*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define TEXT_FILE_PATH "data/data.txt"
enum class Options
{
    Add = 1,
    View = 2
};
// create a function to write in file in specific path
void addToTextFile(string txt, string filePath)
{
    ofstream myFile; // intialize a file to write in
    myFile.open(filePath, ios::out | ios::app);
    myFile << txt + "\n";
    myFile.close();
}

vector<string> readFromTextFile(string filePath)
{
    vector<string> fileLines;
    ifstream myFile(filePath);
    string line;
    if (myFile.is_open())
    {
        // get the file lines ,line by line
        while (getline(myFile, line))
        {
            fileLines.push_back(line);
        }
    }
    else
    {
        cout << "-> Unable to open the file\n";
    }
    return fileLines;
}
int main()
{
    string txt;
    int options;
    while (true)
    {
        cout << "-->\n1- Add new record\n2-view records \nAny other key to exit\n";
        cin >> options;
        if (options == (int)Options::Add)
        {
            cout << "Enter txt\n";
            std::cin >> std::ws;
            getline(cin, txt);
            addToTextFile(txt, TEXT_FILE_PATH);
        }
        else if (options == (int)Options::View)
        {
            cout << "\n==========FileContent===========\n";
            vector<string> fileLines = readFromTextFile(TEXT_FILE_PATH);
            for (auto it : fileLines)
                cout << it << endl;
        }
        else
        {
            break;
        }
    }
}