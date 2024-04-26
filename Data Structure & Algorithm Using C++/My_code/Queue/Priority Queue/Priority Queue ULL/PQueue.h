#include <iostream>
#include "PNode.h"
using namespace std;

template <class t>
class PQueue
{
private:
    PNode<t> *front;
    PNode<t> *rear;

public:
    PQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(int prio, t element);
    t Dqueue();
    bool isEmpty();
};

template <class t>
void PQueue<t>::Enqueue(int prio, t element)
{
    // highest priority served first. Highest number value will be highest priority
    PNode<t> *n = new PNode<t>(prio, element, 0);
    if (rear == 0 && front == 0)
    {
        front = rear = n;
    }

    else if (n->getprio() < rear->getprio())
    {
        rear->setNext(n);
        rear = n;
    }

    else if (prio > front->getprio())
    {
        n->setNext(front);
        front = n;
    }
    else
    {
        PNode<t> *ptr = front;
        while (((PNode<t> *)ptr->getNext())->getprio() >= n->getprio())
        {
            ptr = (PNode<t> *)ptr->getNext();
        }
        n->setNext(ptr->getNext());
        ptr->setNext(n);
    }
}

template <class t>
t PQueue<t>::Dqueue()
{
    if (rear == 0 && front == 0)
    {
        cerr << "Queue is Empty \n";
    }

    else
    {
        PNode<t> *temp = front;
        t element =front->getData();
        front = (PNode<t> *)front->getNext();
        delete temp;
        return element;
    }
}

template <class t>
bool PQueue<t>::isEmpty()
{
    if (rear == 0 && front == 0)
        return true;

    else
        return false;
}
