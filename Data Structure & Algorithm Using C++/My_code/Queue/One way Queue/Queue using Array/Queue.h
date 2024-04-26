#include <iostream>
using namespace std;

template <class t>
class Queue
{
private:
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Maximum size of the queue
    t *arr;    // Array to store the elements

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new t[this->size];
    }

    // Enqueue operation to insert an element at the rear of the queue
    void Enqueue(t element);

    // Dequeue operation to remove and return the front element from the queue
    t Dqueue();

    // Check if the queue is empty
    bool isEmpty();

    // Check if the queue is full
    bool isFull();

    // Get the value of the front element without removing it
    t frontValue();

    // Get the value of the rear element without removing it
    t rearValue();

    // Remove all elements from the queue and return them as a single value
    t dqueue_OneGo();
};

// Implementation of the Enqueue operation
template <class t>
void Queue<t>::Enqueue(t element)
{
    if (rear == size - 1)
    {
        cerr << "Queue is Full \n";
    }
    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
        arr[rear] = element;
    }
    else
    {
        rear++;
        arr[rear] = element;
    }
}

// Implementation of the Dequeue operation
template <class t>
t Queue<t>::Dqueue()
{
    if (rear == -1 && front == -1)
    {
        cerr << "Queue is Empty \n";
        return t();
    }
    else if (rear == front)
    {
        t element = arr[front];
        rear = front = -1;
        return element;
    }
    else
    {
        t element = arr[front];
        front++;
        return element;
    }
}

// Implementation of the isEmpty operation
template <class t>
bool Queue<t>::isEmpty()
{
    if (rear == -1 && front == -1)
        return true;
    return false;
}

// Implementation of the isFull operation
template <class t>
bool Queue<t>::isFull()
{
    if (rear == size - 1)
        return true;
    return false;
}

// Implementation of the frontValue operation
template <class t>
t Queue<t>::frontValue()
{
    if (rear == -1 && front == -1)
        return -1;
    t element = arr[front];
    return element;
}

// Implementation of the rearValue operation
template <class t>
t Queue<t>::rearValue()
{
    t element = arr[rear];
    return element;
}

// Implementation of the dqueue_OneGo operation
template <class t>
t Queue<t>::dqueue_OneGo()
{
    if (rear == -1 && front == -1)
    {
        cerr << "Nothing is in Queue \n";
       // return t();
    }

    t items;
    while (!isEmpty())
    {
        items += arr[front];
        Dqueue();
    }
    return items;
}
