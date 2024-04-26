#include <iostream>
#include "PNode.h"
using namespace std;
template <class T>
class PQ
{
private:
	PNode<T> *rear;	 // tail
	PNode<T> *front; // head

public:
	PQ()
	{
		rear = front = 0;
	}
	void enqueue(int prio, T element);
	T dequeue(); // removeFromHead
	bool isEmpty();
};
template <class T>
void PQ<T>::enqueue(int prio, T element)
{
	PNode<T> *n = new PNode<T>(prio, element, 0);

	if (rear == 0 && front == 0) // first E
	{
		rear = front = n;
	}
	else if (n->getPrio() > rear->getPrio())
	{
		rear->setNext(n);
		rear = n;
	}
	else if (n->getPrio() < front->getPrio()) // new node has highest prio
	{
		n->setNext(front);
		front = n;
	}
	else
	{
		PNode<T> *ptr = front;
		while (((PNode<T> *)ptr->getNext())->getPrio() <= n->getPrio())
		{
			ptr = (PNode<T> *)ptr->getNext();
		}
		n->setNext(ptr->getNext());
		ptr->setNext(n);
	}

} // Enqueue

template <class T>
T PQ<T>::dequeue()
{
	// rempoveFromHead
	// replace head with front
	// replace tail with rear
	if (rear == 0)
	{
		cerr << "nothing to dequeue \n";
	}
	else if (rear == front)
	{
		T element = front->getInfo();
		delete front;
		front = rear = 0;
		return element;
	}
	else
	{
		T element = front->getInfo();
		PNode<T> *ptr = front;
		front = (PNode<T> *)front->getNext();
		delete ptr;
		return element;
	}
}
template <class T>
bool PQ<T>::isEmpty()
{
	return (front == 0 && rear == 0);
}
