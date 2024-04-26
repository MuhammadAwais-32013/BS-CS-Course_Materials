#include<iostream>
#include"DNode.h"
using namespace std;
template<class t>
class DLL
{
  private:
   DNode<t> *head;
   DNode<t> *tail;
public:
		DLL()
		{
		  head=0;
		  tail=0;	
		}
		
		void setHead(DNode<t>* first);
		void setTail(DNode<t> *last);
		DNode<t>* getHead();
		DNode<t>* getTail();
		void addToHead(t element);
		void addToTail(t element);// task
		void reverseTraverse();// task
		void forwardTraverse();// from head to tail
		void addBefore(t newE,t existingE);
	//	void addAfter(t existingE,t newE); task
	//  void removeFromHead(); task
	//  void removeGivenElement(); task
	    void removeFromTail();
			
}; // End Of class DLL

// *********************Function Defination*********************

template<class t>
void DLL<t>::setHead(DNode<t> *first)
{
	head=first;
 } // set

template<class t>
void DLL<t>::setTail(DNode<t> *last)
{
	tail=last;
	
 } //set

template<class t>
DNode<t>* DLL<t>::getHead()
{
	return head;
	
 } // get

template<class t> 
DNode<t>* DLL<t>::getTail()
{
	return tail;
	
 } // get
 
template<class t> 
void DLL<t>::addToHead(t element)
{
	
	DNode<t> *n =new DNode<t>(0, element,0);
	
	if(head==0 && tail==0)
	{  
	  head=tail=n;	
	}
	
	else  // if list is no empty
	{
		n->setNext(head); // Type casting implicity and explicity
		head->setPrev(n);
		head=n;
		
	}		
}// End 

template<class t> 
void DLL<t>::addToTail(t element)
{
    DNode<t> *n=new DNode<t>(0,element,0);
	
	if(head==0 && tail==0)	
	{
		head=tail=n;
	}
	
	else
	{
//		DNode<t> *ptr=head;
//		
////		while(ptr!=tail)
////		{
////			ptr=(DNode<t>*)ptr->getNext();
////		}
////	   
//	   if(ptr==tail)
//	   {
//	   	 n->setPrev(ptr);
//	   	 ptr->setNext(n);
//	   	 tail=n;
//	   }
	   
	   tail->setNext(n);
	   n->setPrev(tail);
	   tail=n;
	   
	}
	
		
}// End

template<class t>
void DLL<t>::forwardTraverse()
{
	
	DNode<t> *ptr=head;
	while(ptr!=0)
	{
		ptr->displayNode();
		cout<<endl;
		ptr=(DNode<t>*)ptr->getNext();
	}	
}//end

template<class t>
void DLL<t>::addBefore(t newE,t existingE)
{
	
	if(head==0 && tail==0) //error
	{
		cerr<<"list is empty existing is not there \n";
	}//end
	
	else if(existingE==head->getInfo()) // head only
	{
		addToHead(newE);
		
	}//end
	
	else // neither head nor tail
	{  
		 DNode<t> *ptr=head;
		 
		 while(ptr!=tail && existingE!=ptr->getNext()->getInfo() )
		 {
		 	ptr=(DNode<t>*)ptr->getNext();
		 }
		 
		 if(ptr==tail)
		 {
		 	cerr<<"Existing is not there \n";
		 }
		 
		 else
		 {
           DNode<t> *n=new DNode<t>(0,newE,0);
           n->setPrev(ptr);
           n->setNext(ptr->getNext());
           ptr->setNext(n);
           ((DNode<t>*)n->getNext())->setPrev(n);
		 }
		
	}	
	
}// end

template<class t>
void DLL<t>::removeFromTail()
{
	
	if(head==0 && tail==0)
	{
		cerr<<"list is empty \n";
	}
	
	else if(head==tail) // only one node H and T 
	{
		delete tail;
		head=tail=0;
	}
	
	else // more than one node T only
	{
		
		DNode<t> *ptr=tail->getPrev();
		delete tail;
		ptr->setNext(0);
		tail=ptr;
		
	}
	
	
	
}// End



