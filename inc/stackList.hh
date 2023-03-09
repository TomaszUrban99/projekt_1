#ifndef STACK_LIST_HH
#define STACK_LIST_HH

#include <memory>
#include "stackNode.hh"

template <class T>
class stackList
{
    std::shared_ptr<stackNode<T>> _head;
    std::shared_ptr<stackNode<T>> _tail;
    int _stackSize = 0;

public:
    stackList<T>()
    {
        _head = nullptr;
        _tail = nullptr;
    }
    ~stackList<T>()
    {
    }

    T &top();
    void push(T newElem);

    std::shared_ptr<stackNode<T>> getHead();
};

template <typename T>
T &stackList<T>::top()
{
    return _head->getElement();
}

/*!
    push()- method for putting element on the top of the stack

    \arg T newElem- element to put on the top of the stack

    Function:
        1. Create a new instance of stackNode class, which will
        be pointed by std::shared_ptr<> newNodePtr
        2. Set the head of the stack (_head) to the newly created object
        3. If stack was empty, before push(), then set the tail to the
        new node of the stack, otherwise
*/
template <typename T>
void stackList<T>::push(T newElem)
{
    std::shared_ptr<stackNode<T>> newNodePtr(new stackNode<T>(newElem));

    newNodePtr->setNext(_head);
    _head = newNodePtr;

    if (_stackSize == 0)
        _tail = newNodePtr;

    _stackSize++;
}

template <typename T>
std::shared_ptr<stackNode<T>> stackList<T>::getHead()
{
    return _head;
}

#endif