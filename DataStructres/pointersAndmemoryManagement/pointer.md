# Pointers



## Const in pointers

    `int const* countPtr = new int(10); // The value of the integer pointed to by countPtr cannot be changed.
    *countPtr = 20; // This is an error because the value of the integer pointed to by countPtr cannot be changed.

    const int* countPtr2 = new int(10); // The value of the integer pointed to by countPtr2 cannot be changed, but the pointer countPtr2 itself can be changed.
    countPtr2 = new int(20); // This is valid because the pointer countPtr2 can be changed.`

