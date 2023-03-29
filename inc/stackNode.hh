#ifndef STACK_NODE_HH
#define STACK_NODE_HH

#include <memory>

template <class T>
class stackNode
{
    int _nodeNumber;
    int _nodeSize;
    T _nodeElement;
    std::shared_ptr<stackNode<T>> _next;

public:
    stackNode<T>(T nodeElem)
    {
        _nodeElement = nodeElem;
        _next = nullptr;
    }
    stackNode<T>(T nodeElem, int newNodeNumber, int newNodeSize)
    {
        _nodeSize = newNodeSize;
        _nodeElement = nodeElem;
        _nodeNumber = newNodeNumber;
        _next = nullptr;
    }
    ~stackNode<T>()
    {
        std::cout << "Kokoko" << std::endl;
    }

    T &getElement()
    {
        return _nodeElement;
    }
    T getElement() const
    {
        return _nodeElement;
    }

    void setNext(std::shared_ptr<stackNode<T>> nextElem)
    {
        _next = nextElem;
    }

    std::shared_ptr<stackNode<T>> &getNext()
    {
        return _next;
    }

    int getNodeNumber()
    {
        return _nodeNumber;
    }

    int getNodeSize()
    {
        return _nodeSize;
    }
};

#endif