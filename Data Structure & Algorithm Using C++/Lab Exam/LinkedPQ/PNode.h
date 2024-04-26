#include <iostream>
#include "Node.h"
using namespace std;
template <class T>
class PNode:public Node<T>
{
	private:
		int prio;	
	public:
		PNode(int prio, T info, PNode<T> *next):Node<T>(info,next)
		{
			this->prio=prio;
		}
		void setPrio(int prio);
		int getPrio();
		void displayNode();
};

template<class T>
void PNode<T>::setPrio(int prio)
{
	this->prio=prio;
}

template<class T>
int PNode<T>::getPrio()
{
	return this->prio;
}
template<class T>
void PNode<T>::displayNode()
{
	cout<<this->getInfo()<<"\t";
	cout<<this->getNext()<<"\t";
	//Node<T>::displayNode();
	cout<<this->prio;
}



