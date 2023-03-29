#ifndef STACK_LIST_HH
#define STACK_LIST_HH

#include <memory>
#include <iostream>
#include <fstream>
#include "stackNode.hh"

template <class T>
class stackList
{
    /* Pointer to the head of the stack */
    std::shared_ptr<stackNode<T>> _head;
    /* Pointer to the bottom of the stack */
    std::shared_ptr<stackNode<T>> _tail;
    /* Number of elements on the stack */
    int _stackSize = 0;

public:
    /* CONSTRUCTORS AND DESTRUCTOR */
    stackList<T>()
    {
        _head = nullptr;
        _tail = nullptr;
    }
    ~stackList<T>()
    {
    }

    /* ACCESS TO ATTRIBUTES */
    T &top();

    /*! \brief int top_number()- return the number of top node */
    int top_number() { return _head->getNodeNumber(); }

    /*! \brief Method returning the shared pointer to the head of list */
    std::shared_ptr<stackNode<T>> getHead();

    /*!
        \brief Method returning the const copy of
        element stored in the head node
    */
    T top() const { return _head->getElement(); }

    /* TOOLS FOR THE STACK */
    void push(T newElem);
    void push(T newElem, int newElemNumber, int newNodeSize);
    T pop();
};

/*!
    top()- return the element from the top node
*/
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
        2. Set the current head of the stack (_head) as the next node
        after new node.
        3. Set new head of stack- newly created node.
        4. If stack was empty, before push(), then set the tail to the
        new node of the stack.
        5. Increment value of attribute _stackSize;

    \retval void method- no return value
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
void stackList<T>::push(T newElem, int newNodeNumber, int newNodeSize)
{
    std::shared_ptr<stackNode<T>> newNodePtr(new stackNode<T>(newElem, newNodeNumber, newNodeSize)); // 20

    newNodePtr->setNext(_head); // 4
    if (_head == NULL) // 6
    {
        _tail = newNodePtr;
    }
    _head = newNodePtr; // 3
}

template <typename T>
T stackList<T>::pop()
{
    std::shared_ptr<stackNode<T>> elementNode = _head;
    _head = _head->getNext();

    return elementNode;
}

/*!
    getHead()- get the pointer to the top node of the stack
*/
template <typename T>
std::shared_ptr<stackNode<T>> stackList<T>::getHead()
{
    return _head;
}

/* OVERLOADED OPERATORS */
template <typename T>
std::ostream &operator<<(std::ostream &out, stackList<T> &list)
{
    std::shared_ptr<stackNode<T>> tmpPtr = list.getHead();
    while (tmpPtr != NULL)
    {
        std::cout << tmpPtr->getElement() << std::endl;
        tmpPtr = tmpPtr->getNext();
    }

    return out;
}
#endif