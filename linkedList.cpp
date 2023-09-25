#include "linkedList.hpp"
#include<iostream>

using namespace std;
template <class T>
CLinkedList<T>::~CLinkedList()
{
    while (head != nullptr)
        deleteFront();
}

template <class T>
void CLinkedList<T>::addBack(T element)
{
    Node<T> *newNode = new Node<T>{element, nullptr};

    if (empty())
    {
        head = newNode;
    }
    else
    {
        Node<T> *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    length++;
}

template <class T>
void CLinkedList<T>::addAtIndex(int index, T value)
{
    // unvalid index
    if (index < 0 || index > length)
    {
        cout << "outOfScope\n";
        return;
    }

    // insert first case
    if (index == 0)
        addFront(value);
    else if (index == length)
        addBack(value);
    else
    {
        Node<T> *newNode = new Node<T>{value, nullptr};
        int ind = 1;
        Node<T> *tmp = head;
        while (ind < index)
        {
            tmp = tmp->next;
            ind++;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    length++;
}

template <class T>
T CLinkedList<T>::deleteFront()
{
    if (empty())
    {
        cout << "List is empty\n";
        return 0;
    }
    T value = head->val;
    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
    length--;
    return value;
}

template <class T>
T CLinkedList<T>::deleteBack()
{

    if (empty())
    {
        cout << "List is empty\n";
        return 0;
    }
    Node<T> *tmp = head;
    while (tmp->next->next != nullptr)
    {
        tmp = tmp->next;
    }
    T value = tmp->next->val;
    delete tmp->next;
    tmp->next = nullptr;

    length--;
    return value;
}

template <class T>
void CLinkedList<T>::deleteAtIndex(int index)
{
    if (head == nullptr)
    {
        return;
    }
    if (index < 0 || index >= length)
    {
        cout << "ERROR: Out of range" << endl;
        return;
    }
    if (head->next == nullptr)
        deleteFront();
    else if (index == length - 1)
        deleteBack();
    else
    {
        int ind = 1;
        Node<T> *tmp = head;
        while (ind < index)
        {
            tmp = tmp->next;
            ind++;
        }
        //        tmp->next=tmp->next->next;
        //        delete tmp->next ;
        Node<T> *nextNode = tmp->next;
        tmp->next = nextNode->next;
        delete nextNode;
    }
    length--;
}

template <class T>
T CLinkedList<T>::front()
{
    return head->val;
}

template <class T>
int CLinkedList<T>::size()
{
    return length;
}

template <class T>
T CLinkedList<T>::get(int index)
{
    if (index == 0)
        return front();
    Node<T> *tmp = head->next;
    int ind = 1;
    while (ind < index)
    {
        tmp = tmp->next;
        ind++;
    }
    return tmp->val;
}

template <class T>
void CLinkedList<T>::addFront(T element)
{
    Node<T> *newNode = new Node<T>;
    newNode->val = element;
    if (empty())
    {
        head = newNode;
        head->next = nullptr;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

template <class T>
bool CLinkedList<T>::empty()
{
    return length == 0;
}

template <class T>
CLinkedList<T>::CLinkedList()
{
    head = nullptr;
    length = 0;
}

template <class T>
void CLinkedList<T>::print()
{
    Node<T> *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
