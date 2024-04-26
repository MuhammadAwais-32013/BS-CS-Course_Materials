#include <iostream>
#include <stack>
using namespace std;
template <class t>

/// Queue using two Stack 
class M1_Queue
{
    stack<t> s1, s2;

private:
    t *rear;
    t *front;

public:
    M1_Queue()
    {
        front = 0;
        rear = 0;
    }

    void Enqueue(t element);
    t Dqueue();
    bool isEmpty();
    t frontValue();
};

template <class t>
void M1_Queue<t>::Enqueue(t element)
{
    s1.push(element);
}

template <class t>
t M1_Queue<t>::Dqueue()
{
    if (s1.empty() && s2.empty())
    {
        cerr << "Queue is empty! \n";
        exit(0);
    }

    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    t item = s2.top();
    s2.pop();

    return item;
}

template<class t>
bool M1_Queue<t>::isEmpty()
{
    if (s1.empty() && s2.empty())
    return true;
    return false;
    
}

template<class t>
t M1_Queue<t>::frontValue()
{
    t element = s1.front();
    return element;
}
