// C++ provides different kinds of smart pointers. We call these pointers “smart” because they automatically get deallocated without explicit instructions from a programmer or garbage collector. While smart pointers have more performance and memory overhead than classical pointers, they help reduce memory leaks.


// unique pointer
#include <iostream>
#include <memory>
using namespace std;
class MyClass
{
public:
    int i;
    MyClass()
    { // Constructor
        std::cout << "\n created\n";
    }
    ~MyClass()
    { // Destructor
        std::cout << "\n destroyed\n";
    }
};
int main()
{
    // using if block to check the work of smart pointer as it 'll allocate and deallocate solo
    if(true)
    {
        unique_ptr<MyClass> ptr(new MyClass());
    }
}