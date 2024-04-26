#include <iostream>
using namespace std;
template <class t>
class CQueue
{
private:
    int size;
    t front;
    t rear;
    t *arr; // dynamically Allocation of memeory
public:
    CQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = new t[this->size]; /// create an array as Generic type t with size
    }

    void Enqueue(t element);
    t Dqueue();
    bool isEmpty();
    bool isFull();
    t frontValue();
    t rearValue();
    t removeAll();
};

// ********************Implementation of Functions*******************
template <class t>
void CQueue<t>::Enqueue(t element)
{
    /*Possible senarios
    1- Is there sapce in Queue for new element or not
    2- Is the coming element as first in Queue
    3- Is we need to refill the Queue means we have vancant slot in beginning of Queue
       rear is set to 0;
    4- We will inert new element at rear */

    if ((rear == size - 1 && front == 0) || (rear == (front - 1) % (size - 1))) // rear+1=front if refilled
    {
        cerr << "Queue is Full \n";
        return;
    }

    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
    }

    else if (rear == size - 1 && front != 0) // refill
    {
        rear = 0;
    }

    else // f==0 && rear!=size-1
    {
        rear++;
    }
    arr[rear] = element;
}

template <class t>
t CQueue<t>::Dqueue()
{
    /*Possible senarios
    1- Is there element in Queue for new element or not
    2- Is the removing element as only element in Queue
    3- Is we need to refill the Queue means we have vancant slot in beginning of Queue
    4- We will inert new element at rear */

    if (rear == -1 && front == -1)
    {
        cerr << "Queue is Empty \n";
    }

    else if (rear == front)
    {
        t element = arr[front];
        front = -1;
        rear = -1;
        return element;
    }

    else if (front > rear && front == size - 1) // refilled
    {
        t element = arr[front];
        front = 0;
        return element;
    }

    else
    {
        t element = arr[front];
        front++;
        return element;
    }
}

template <class t>
bool CQueue<t>::isEmpty()
{
    if (rear == -1 && front == -1)
        return true;
    return false;
}

template <class t>
bool CQueue<t>::isFull()
{
    if ((rear == size - 1 && front == 0) || rear + 1 == front)
        return true;
    return false;
}

template <class t>
t CQueue<t>::frontValue()
{
    t element = arr[front];
    return element;
}

template <class t>
t CQueue<t>::rearValue()
{
    t element = arr[rear];
    return element;
}

template <class t>
t CQueue<t>::removeAll()
{
    if (rear == -1 && front == -1)
    {
        cerr << "Queue is Empty \n";
        return t();
    }

    else
    {
        t element;
        while (rear!=-1 && front!=-1)
        {
            element += arr[front];
            Dqueue();
        }

        return element;
    }
}
