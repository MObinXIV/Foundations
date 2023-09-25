#include<iostream>
#include "linkedList.hpp"
using namespace std;

int main()
{
    CLinkedList<int> *linkedList = new CLinkedList<int>();
    linkedList->addFront(4);
    linkedList->addFront(5);
    linkedList->addBack(7);
    linkedList->addBack(90);
    cout << linkedList->deleteBack() << endl;
    linkedList->addBack(700);
    linkedList->addAtIndex(2, 80);
    linkedList->deleteAtIndex(2);
    linkedList->print();
    cout << linkedList->size() << endl;
    cout << "The value at index" << 2 << " is:" << linkedList->get(2);
    delete linkedList;
    return 0;
}