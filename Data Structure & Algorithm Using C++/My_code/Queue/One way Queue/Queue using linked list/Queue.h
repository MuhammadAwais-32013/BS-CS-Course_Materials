#include <iostream>
#include "E:\BSCS 3rd Semester\DSA\lab code\L3P3 Singular link List\node.h"
using namespace std;
template <class t>
class Queue
{
private:
    Node<t> *front;
    Node<t> *rear;
    int counter;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        counter=0;
    }
    void Enqueue(t element);
    t Dqueue();
    bool isFull();
    bool isEmpty();
    t frontValue();
    t rearValue();
    t removeAll();
    int getcount();
}; // End of Queue class

template <class t>
void Queue<t>::Enqueue(t element)
{
    // if (getcount()==5)
    // {
    //     cerr<<"List is Full \n";
    //     exit(-1);
    // }
    
    Node<t> *n = new Node<t>(element, 0);
     if (rear == 0 && front == 0)
    {
        rear = front = n;
        counter++;
    }

    else
    {
        rear->setNext(n);
        rear = n;
        counter++;
    }
}

template <class t>
t Queue<t>::Dqueue()
{
    if (rear == 0 && front == 0)
    {
        cerr << "Queue is Empty \n";
    }

    else
    {
        Node<t> *temp = front;
        t element = temp->getInfo();
        front = front->getNext();
        delete temp;
        counter--;
        return element;
    }
}

template<class t>
int Queue<t>::getcount()
{
    return counter;
}
template <class t>
bool Queue<t>::isEmpty()
{
    return (rear == 0 && front == 0);
}

template <class t>
bool Queue<t>::isFull()
{
    if (getcount() == 5)
        return 1;
    return 0;
}

template <class t>
t Queue<t>::frontValue()
{
    t element = front->getInfo();
    return element;
}

template <class t>
t Queue<t>::rearValue()
{
    t element = rear->getInfo();
    return element;
}

template <class t>
t Queue<t>::removeAll()
{
    t element;
    while (!isEmpty())
    {
        element += Dqueue();
    }
    return element;
}
