/// Memory leaks occur when memory isn’t deallocated, even after it is no longer required. This could lead to the program running out of the maximum memory available to it.(allocate memory and not to deallocate it)
#include <iostream>

void memLeak()
{
    // Pointer to integer
    int *ptr;
    // Allocates memory for an integer
    ptr = new int;
    // Memory is not deallocated here (as the following line is commented)
    // delete ptr;
}
int main()
{
    memLeak();
    // Pointer (ptr) is no longer accessible
    // but memory is still allocated for an int.
    return 0;
}

/// Segmentation fault is another well-known dynamic memory management bug. This bug occurs when a program accesses a memory location that is neither allocated to it nor in the address space of the program. Address space refers to the region of memory where a program is allowed to allocate memory.
#include <iostream>

void segFault()
{
    // A pointer to integer
    int *ptr;
    // Allocating memory for an integer.
    ptr = new int;
    while (true)
    {
        // The following will throw a segmentation fault
        // when we run out of the program's address space.
        *(ptr++) = 5;
    }
}

int main()
{
    segFault();
    return 0;
}