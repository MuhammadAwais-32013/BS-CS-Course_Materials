#include <iostream>
#include <stack>
using namespace std;
template <class t>

/// Queue using one Stack 
class M3_Queue
{
    stack<t> s;

private:
    t *rear;
    t *front;

public:
    M3_Queue()
    {
        front = 0;
        rear = 0;
    }

    void Enqueue(t element);
    t Dqueue();
    bool isEmpty();
};

template <class t>
void M3_Queue<t>::Enqueue(t element)
{
    s.push(element);
}

template <class t>
t M3_Queue<t>::Dqueue()
{
  if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }
  
        // pop an item from the stack
        int x = s.top();
        s.pop();
  
        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;
  
        // recursive call
        int item = deQueue();
  
        // push popped item back to the stack
        s.push(x);
  
        // return the result of deQueue() call
        return item;
    }   


template<class t>
bool M3_Queue<t>::isEmpty()
{
    if (s.empty())
    return true;
    return false;
    
}