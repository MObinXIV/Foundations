#include <iostream>

using namespace std;

int main()
{
    int*ptr;

    // allocate space of memory 
    ptr =new int;
    *ptr=5;
    
    // output the value stored in ptr 
    cout<<"the value stored in ptr is :"<<*ptr<<endl;

    // output the location of memory 
    cout<<"the address ptr located at is"<<ptr<<endl;


    delete ptr;
}