#include <iostream>
#include "Node.h"
using namespace std;
template <class t>
class Stack
{
private:
    Node<t> *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(t element);
    t pop();
    bool isEmpty();
    t topValue();

}; // End os Class

/// ------------------Function Implementation---------------------------

template <class t>
void Stack<t>::push(t element)
{
    Node<t> *n = new Node<t>(element, 0);
    if (top == NULL)
    {
        top = n;
    }

    else
    {
        n->setnext(top);
        top = n;
    }
}

template <class t>
t Stack<t>::pop()
{
    if (top == NULL)
    {
        cerr << "Stack underflow \n";
    }
    else
    {
        t element = top->getdata();
        Node<t> *temp = top;
        top = top->getnext();
        delete temp;
        return element;
    }
}

template <class t>
bool Stack<t>::isEmpty()
{
    //    if (top == -1)
    //        return true;
    //
    //    else
    //      return false;

    return (top == NULL);
}

template <class t>
t Stack<t>::topValue()
{
    if (top == NULL)
    {
        cerr << "Stack underflow " << endl;
    }

    else
    {
        t element = top->getdata();
        return element;
    }
}