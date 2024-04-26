#include<iostream>
#include "E:\BSCS 3rd Semester\DSA\My_code\Singly linked list\Node.h"
using namespace std;
template<class t>
class linkedStack
{ 
private:
	Node<t> *top;
	
	public:
		linkedStack()
		{
		  top=0;	
		}
		
		void push(t element);// add to head 
		t pop();// remove from head
		bool isEmpty();
		t topValue();
		
	
}; // End of Class 

template<class t>
void linkedStack<t>::push(t element)
{
	Node<t> *n= new Node<t>( element,NULL);
	if(top==0)
	{
		top=n;
	
		
	}
	else
	{
		n->setNext(top);
		top=n;
	}
}

template<class t>
t linkedStack<t>::pop()
{
	 if(top==0 ) // empty
	{
		cerr<<"List is empty Nothing will remove"<<endl;
		//return NULL;
	}	
      else
	   {
        Node<t>* temp = top;
        t element=top->getData();
        top = top->getNext(); 
        delete temp; 
        return element;
      }
      
      
      ////// remove from tail
      	if(top==0)// error
	{
		cerr<<"List is empty nothing will delete "<<endl;
	}
	
	else if(top->getNext()==0)// h and t
	{   t element=top->getData();
		delete top;
		top=0;
		return element;
	}
	else //t only
	{
		Node<t>  *ptr=top;
		 t element=top->getData();
		top=top->getNext();
        delete ptr;
        return element;
	}
    
} // end

template<class t>
bool linkedStack<t>::isEmpty()
{
	if(top==0)
	
		return true;
}

template<class t>
t linkedStack<t>::topValue()
{
	 if(top==0)
    {
    	cerr<<" Stack is underflow \n";
	}
	else
	{
		return top->getData();
	}
}






