#include<iostream>
using namespace std;
template<class T>
class Node
{
	private:
		T info;
		Node<T> *next;
	public:
		Node(T info, Node<T> *next)
		{
			this->info=info;
			this->next=next;
		}
		void setInfo(T info);
		void setNext(Node<T> *next);
		T getInfo();
		Node<T>* getNext();
		void displayNode();
};//EOC

template<class T>
void Node<T>::setInfo(T info)
{
	this->info=info;
}//setInfo

template<class T>
void Node<T>::setNext(Node<T> *next)
{
	this->next=next;
}//setInfo

template<class T>
T Node<T>::getInfo()
{
	return this->info;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return this->next;
}

template<class T>
void Node<T>::displayNode()
{
	cout<<"("<<this<<") |"<<info<<"|"<<next<<"|";
}
