#include <iostream>
using namespace std;
template <class t>
class Stack
{
private:
    int size;
    int top;
    t *arr;

public:
    Stack(int size) // defualt parameter as 5
    {
        top = -1;
        this->size = size;
        arr = new t[this->size];
    }
    void push(t element);
    t pop();
    bool isEmpty();
    bool isFull();
    t topValue();

}; // End os Class

/// ------------------Function Implementation---------------------------

template <class t>
void Stack<t>::push(t element)
{
    if (top == size - 1)
    {
        cerr << "Stack overflow \n";
    }
    else
    {
        top++;
        arr[top] = element;
    }
}

template <class t>
t Stack<t>::pop()
{
    if (top == -1)
    {
        cerr << "Stack underflow \n";
    }
    else
    {
       t element = arr[top];
        top--;
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
      
    return (top==-1);
}

template <class t>
bool Stack<t>::isFull()
{
    if (top == size - 1)
        return true;
}

template <class t>
t Stack<t>::topValue()
{
    if (top == -1)
    {
        cerr << "Stack underflow " << endl;
    }

    else
    {
        t element = arr[top];
        return element;
    }
}