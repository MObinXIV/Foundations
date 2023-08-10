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

// The following code shows that shared pointers are similar to unique pointers, except that they allow us to create multiple copies of a pointer and safely delete the object only when all the pointers are out of scope.

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
        // Scope of the MyClass object is this if-block
        shared_ptr<MyClass> ptr = make_shared<MyClass>();

        // Copying is allowed with shared pointers. Yes!
        shared_ptr<MyClass> ptr2 = ptr;

        // Can use both pointers without any errors
        ptr2->i = 5;
        std::cout << "\n"
                  << ptr2->i << ", " << ptr->i << "\n";
    }

    // The pointer gets deallocated automatically at this point.
    // Thus, the destructor of MyClass is called here.

    return 0;
}

//Smart pointers help reduce memory leaks and deallocate memory. However, they don’t completely eliminate the need for us to manually deallocate memory. For instance, in a resource-constrained device, we may need to manually free memory immediately after its last use, even before a pointer is out of scope.

// Unique pointer is created
std::unique_ptr<MyClass> ptr(new MyClass());

// Some code here to use it.
//. . .

// When we do not need it, we can manually release and delete it.
// After release pointer is not automatically managed
MyClass *raw = ptr.release();
// Manually delete it.
delete raw;

// While smart pointers reduce the likelihood of memory leaks, they don’t eliminate them entirely. For instance, if we use cyclic shared pointers, our reference count will never be zero and memory will never be automatically released. In such a situation, we must either avoid smart pointers altogether or resort to manually deallocating the smart pointers.

//The following code example demonstrates the use of cyclic pointers, where shared pointers will not be able to deallocate memory automatically:

#include <iostream>
#include <memory>

class Cyclic
{
public:
    std::shared_ptr<Cyclic> myObj;
    int k;

    Cyclic(int j)
    {
        k = j;
        std::cout << "\n created\n";
    }

    ~Cyclic()
    {
        std::cout << "\n destroyed\n";
    }

    void setObject(std::shared_ptr<Cyclic> obj)
    {
        myObj = obj;
    }
};

//  ptr
//  /   \
//ptr2  ptr
int main()
{
    if (true)
    {
        // First shared pointer
        std::shared_ptr<Cyclic> ptr = std::make_shared<Cyclic>(5);

        // Second shared pointer
        std::shared_ptr<Cyclic> ptr2 = std::make_shared<Cyclic>(6);

        // Creating cyclic dependencies.
        ptr->setObject(ptr2);
        ptr2->setObject(ptr);
    }
    // Even outside of scope the object continues to exist.
    // Thus, destructor is never called and "destroyed" never get printed
    return 0;
}