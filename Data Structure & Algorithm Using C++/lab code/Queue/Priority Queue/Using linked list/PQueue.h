#include <iostream>
#include "PNode.h"
using namespace std;
template <class t>
class PQueue
{
private:
    PNode<t> *front; // head
    PNode<t> *rear;  // tail
public:
    PQueue()
    {
        rear = 0;
        front = 0;
    }

    void Enqueue(int prio, t element);
    t Dqueue();
    bool isEmpty();
    t rearvalue();
    t frontValue();
    t allDelete();
}; // End of Class

template <class t>
void PQueue<t>::Enqueue(int prio, t element)
{  
    // Highest priority served first here highest priority means Highest number value
    PNode<t> *n = new PNode<t>(prio, element, 0);

    if (rear == 0 && front == 0)
    {
        rear = front = n;
    }

    else if (n->getprio() < rear->getprio()) // rear/tail modify or rear has greater priority than n
    {
        rear->setNext(n);
        rear = n;
    }

    else if (n->getprio() < front->getprio()) // front/head modify or front has less priority than n
    {
        n->setNext(front);
        front = n;
    }

    else // in between case
    {
        PNode<t> *ptr = front;
        while (((PNode<t> *)ptr->getNext())->getprio() >= n->getprio())
        {
            ptr = (PNode<t> *)ptr->getNext();
        }
        n->setNext(ptr->getNext());
        ptr->setNext(n);
       
    }
} // End

template <class t>
t PQueue<t>::Dqueue()
{
   
    if (rear == 0 && front == 0)
    {
        cerr << "Queue is empty \n";

    }

    else if (rear == front)
    {
       t element = front->getInfo();
        delete front;
        front = rear = 0;
     return element;
    }
    else
    {
        PNode<t> *temp = front;
       t  element =front->getInfo();
        front = (PNode<t> *)front->getNext();
        delete temp;
        return element;
    }
  
} // end Dequeue

template<class t>
bool PQueue<t>::isEmpty()
{
	if(rear==0 && front==0)
	return true;
	
	else
	return false;	
}

template<class t>
t PQueue<t>::rearvalue()
{
	if(rear==0 && front==0)
{
		cerr<<"Queue is empty \n";
}
	else
	{
		t element = rear->getInfo();

	return element;
    }
}

template<class t>
t PQueue<t>::frontValue()
{
	if(rear==0 && front==0)
	{
	cerr<<"Queue is empty \n";
}
	else
	{
		t element = front->getInfo();
	 return element;
    }
}

template<class t>
t PQueue<t>::allDelete()
{
	if(rear==0 && front==0)
	{
	cerr<<"Queue is empty \n";
  }
	
	PNode<t> *ptr=front;
	t element;
	while(ptr!=NULL)
	{
		element+=Dqueue();
		ptr=(PNode<t>*)ptr->getNext();	
	}
	return element;
}
