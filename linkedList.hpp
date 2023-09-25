template <class T>
struct Node
{
    T val;
    Node<T> *next;
};
template <class T>
class CLinkedList
{
public:
    CLinkedList();
    ~CLinkedList();
    void addFront(T element);
    void addBack(T element);
    void addAtIndex(int index, T value);
    T deleteFront();
    T deleteBack();
    void deleteAtIndex(int index);
    bool empty();
    T front();
    int size();
    T get(int index);
    void print();

private:
    Node<T> *head;
    int length;
};