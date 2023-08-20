#include <iostream>

using namespace std;
template <class T>
class ArrayList
{
private:
    int size, ind;
    T *internalMemory;

    // Function to expand the size array in case of we get exhausted
    void expand()
    {
        size += 10;
        T *temp = new T[size];

        for (int i = 0; i < size; i++)
            temp[i] = internalMemory[i];

        delete[] internalMemory;
        internalMemory = temp;
    }

public:
    ArrayList()
    {
        size = 10;
        ind = 0;
        internalMemory = new T[size];
    }

    ArrayList(int size)
    {
        this->size = size;
        ind = 0;
        internalMemory = new T[size];
    }

    ~ArrayList()
    {
        if (internalMemory)
        {
            delete[] internalMemory;
            internalMemory = NULL;
        }
    }

    void add(T item)
    {
        if (ind >= size)
            expand();

        internalMemory[ind++] = item;
    }
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index is out of range");
        }

        for (int i = index; i < size - 1; i++)
        {
            // Shift all elements after the specified index one position to the left.
            internalMemory[i] = internalMemory[i + 1];
        }

        size--;
    }

    T &operator[](int ind)
    {
        return internalMemory[ind];
    }
};
int main()
{
    ArrayList<int> arr(5);

    for (int i = 0; i < 5; i++)
        cin >> arr[i];
        arr.remove(1);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}