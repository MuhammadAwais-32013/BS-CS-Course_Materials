#include<iostream>
using namespace std;
template<class t> // t is generic data type
class Node
{   private:
     t info; // data Hiding
 	 Node<t> *next;
   	public :
   		Node(t info,Node<t> *next)
   		{
   			 this->info=info;
   			 this->next=next;
		   }
		   void setInfo(t info);
		   void setNext(Node *next);
		   t getInfo();
		   Node<t>* getNext();
		   void displayNode();
	
};// end of Node class 

 // Its C++ standard to implement attribute of outside of class
template<class t>
void Node<t>:: setInfo(t info) //:: scope resulution operator
{
	this->info=info;
	
}//set info

template<class t>
void Node<t>:: setNext(Node<t>* next) //:: scope resulution operator
{
	this->next=next;
	
}//set *next

template<class t>
t Node<t>:: getInfo()
{
	return this->info;
}//set 

template<class t>
Node<t>* Node<t>:: getNext()
{
	return this->next;
}//set

template<class t>
void Node<t>::displayNode()
{
	cout<<"("<<this<<") |"<<info<<"|"<<next<<"|";
}
