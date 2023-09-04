// This code creates a random access file, writes some data to it, reads the data back, and appends some more data to the file.

#include <iostream>
#include <fstream>

using namespace std;
#define TEXT_FILE_PATH "data/data.txt"

int main()
{

    // Create a random access file.
    // The ios::out flag tells the fstream class that the file will be opened for writing.
    // The ios::binary flag tells the fstream class that the file will be opened in binary mode.
    fstream file(TEXT_FILE_PATH, ios::out | ios::binary);

    // Write some data to the file.
    // The write() function writes the data to the file.
    // The first argument to the write() function is the data to be written, and the second argument is the number of bytes to write.
    file.write("This is some random data", 16);

    // Close the file.
    file.close();

    // Open the file in read mode.
    // The ios::in flag tells the fstream class that the file will be opened for reading.
    // The ios::binary flag tells the fstream class that the file will be opened in binary mode.
    file.open(TEXT_FILE_PATH, ios::in | ios::binary);

    // Move the file pointer to the beginning of the file.
    // The seekg() function moves the file pointer to a specific location in the file.
    // The first argument to the seekg() function is the offset from the beginning of the file, and the second argument is the seek mode.
    file.seekg(0, ios::beg);

    // Read 16 bytes from the file.
    // The read() function reads data from the file.
    // The first argument to the read() function is the buffer where the data will be stored, and the second argument is the number of bytes to read.
    char data[16];
    file.read(data, 16);

    // Print the data.
    // The cout object is used to print data to the console.
    cout << data << endl;

    // Move the file pointer to the end of the file.
    file.seekg(0, ios::end);

    // Get the file size.
    // The tellg() function returns the current position of the file pointer.
    int file_size = file.tellg();

    // Close the file.
    file.close();

    // Print the file size.
    cout << "File size: " << file_size << endl;

    // Append some data to the file.
    // The ios::app flag tells the fstream class that the data will be appended to the end of the file.
    file.open(TEXT_FILE_PATH, ios::out | ios::binary | ios::app);
    file.write("This is some appended data", 19);
    file.close();

    // Read the data from the file again.
    file.open(TEXT_FILE_PATH, ios::in | ios::binary);
    file.seekg(0, ios::beg);
    file.read(data, 16);
    cout << data << endl;

    // Close the file.
    file.close();

    // Return 0 to indicate that the program has terminated successfully.
    return 0;
}
