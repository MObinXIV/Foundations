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

#include <iostream>
#include <memory>

class MyClass
{
public:
    int i;

    MyClass()
    {
        std::cout << "\n created\n";
    }

    ~MyClass()
    {
        std::cout << "\n destroyed\n";
    }
};

int main()
{
    if (true)
    {
        // Scope of the following MyClass object is this if-block
        std::unique_ptr<MyClass> ptr(new MyClass());

        /*Uncommenting the following line will produce an error as
        copying of unique pointers is not allowed */
        // std::unique_ptr<MyClass> ptr2 = ptr;

        // Instead move will safely transfer the object ownership from ptr to ptr2
        std::unique_ptr<MyClass> ptr2 = std::move(ptr);
        // Must not use the old pointer now.
        ptr2->i = 5;
        std::cout << "\n"
                  << ptr2->i << "\n";
    }
    // The pointer gets deallocated automatically at this point.
    // Thus, the destructor of MyClass is called here.
    return 0;
}
