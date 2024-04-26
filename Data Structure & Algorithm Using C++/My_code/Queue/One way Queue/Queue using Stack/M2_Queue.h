#include <iostream>
#include <stack>
using namespace std;
template <class t>

/// Queue using two Stack
class M2_Queue
{
    stack<t> s1, s2;

private:
    t *rear;
    t *front;

public:
    M2_Queue()
    {
        front = 0;
        rear = 0;
    }

    void Enqueue(t element);
    t Dqueue();
    bool isEmpty();
};

template <class t>
void M2_Queue<t>::Enqueue(t element)
{
    // move element from s1 to s1
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    // push element in s1
    s1.push(element);

    // Push back element in s1 to s2

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

template <class t>
t M2_Queue<t>::Dqueue()
{
    if (s1.empty())
    {
        cerr << "Queue is empty! \n";
        exit(0);
    }

    t item = s1.top();
    s1.pop();

    return item;
}

template<class t>
bool M2_Queue<t>::isEmpty()
{
    if (s1.empty())
    return true;
    return false;
    
}