#include<iostream> // Standard headerfile --> <>
#include "Node.h"  // LL contain obkj of Node class // is our own headerfiles --> ""
using namespace std;
template<class t>
class SLL
{
	private:
		Node<t> *head;// first node
		Node<t> *tail;// last node
	public:
		SLL()
		{
		  head=0;
		  tail=0;	
		}
		
		void setHead(Node<t>* first);
		void setTail(Node<t> *last);
		Node<t>* getfirst();
		Node<t>* getlast();
		void traverse();// vist all one by one's
		void addTohead(t element);
		void addTotail(t element);
		void addAfterGivenelement(t newE, t existingE);
		void addBeforGivenelement(t existingE, t newE);
		bool search(t element);
		void removeFromTail();
		void removeFromHead();
		/*write a function name remove given element that will take an element as a parameter. 
		the function should find the given element and delete it if element is present 
		otherwise display an error.*/
		void removeGivenElement(t element);
		
}; // end class
        
template<class t>
void SLL<t>::setHead(Node<t>* first)
{
	head=first;
 } // set

template<class t>
void SLL<t>::setTail(Node<t>* last)
{
	tail=last;
 } //set

template<class t>
Node<t>* SLL<t>::getfirst()
{
	return head;
 } 

template<class t> 
Node<t>* SLL<t>::getlast()
{
	return tail;
 } 

template<class t>
void SLL<t>:: traverse()
{
	Node<t>* i=head;
	while(i!=0)
	{    
		//cout<<i->getInfo()<<endl;
		i->displayNode();
		i=i->getNext();
	}
}//end traverse

template<class t>
void SLL<t>::addTohead(t element)
{
	Node<t> *n= new Node<t>( element,NULL);
	if(head==0 && tail==0)
	{
		head=n;
		tail=n;
		
	}
	else
	{
		n->setNext(head);
		head=n;
	}
}// End

template<class t>
void SLL<t>::addTotail (t element)
{
	Node<t> *n = new Node<t>(element,0);
	
	if(head==0 && tail==0)// empty
	{
		head=n;
		tail=n;
	}
	
	else // non-empty
	{
		tail->setNext(n);
		tail=n;
	}
}// End add to tail

template<class t>
void SLL<t>::addAfterGivenelement(t newE, t existingE)
{
       if(head==0 && tail==0)// error
	   {
	   	 cerr<<"List is empty \n"; // cerr use to cout error function
		}	
		else if(existingE==tail->getInfo())//tail only
		{
			addTotail(newE);
		}
		
		else //H! && T!
		{
		  	Node<t> *ptr=head;
		  	while(ptr!=0 && existingE!=ptr->getInfo())
		  	{
		  		ptr=ptr->getNext();
			  }
			  
			  if(ptr==0) //1st condition
			  {
			  	cerr<<"Existing Element not found"<<endl;
			  }
			  
			  else //2nd conditio
			  {
			  	Node<t> *n= new Node<t>(newE,0);
			  	n->setNext(ptr->getNext());
			  	ptr->setNext(n);
			  }
		}
}// End of addAfterGivenelement

template<class t>
void SLL<t>::addBeforGivenelement(t existingE, t newE)
{
	
       if(head==0 && tail==0)// error
	   {
	   	 cerr<<"List is empty \n"; // cerr use to cout error function
		}	
		else if(existingE==tail->getInfo())//tail only
		{
			addTohead(newE);
		}
		
		else //H! && T!
		{
		  	Node<t> *ptr=head;
		  	while(ptr!=0 && existingE!=ptr->getNext()->getInfo())
		  	{
		  		ptr=ptr->getNext();
			  }
			  
			  if(ptr==0) //1st condition
			  {
			  	cerr<<"Existing Element not found"<<endl;
			  }
			  
			  else //2nd condition
			  {
			  	Node<t> *n= new Node<t>(newE,0);
			  	n->setNext(ptr->getNext());
			  	ptr->setNext(n);
			  }
		}
}// End of addBeforGivenelement

template<class t>
bool SLL<t>::search(t element)
{  
    if(head==0 && tail==0 )
    {
    	return false;
	}
	
	 Node<t> *ptr=head;
	while(ptr!=0 && element!=ptr->getInfo())
	{
	  ptr=ptr->getNext();
 }    
    if(ptr==0)
    {
    	return false;
	}
	  else
	  {
	  	return true;
	  }
	  
}// End of search

template<class t>
void SLL<t>::removeFromTail()
{
	if(head==0 && tail==0)// error
	{
		cerr<<"List is empty nothing will delete "<<endl;
	}
	
	else if(head==tail)// h and t
	{
		delete tail;
		head=tail=0;
	}
	else //t only
	{
		Node<t>  *ptr=head;
		
		while(ptr->getNext()!=tail)
		{
			ptr=ptr->getNext();
		}
        delete tail;
        ptr->setNext(0);
        tail=ptr;
	}
}// End of Remove From Tail

template<class t>
void SLL<t>::removeFromHead()
{     
//        Node<t>* ptr;
//    if(head==0 && tail==0) // empty
//	{
//		cerr<<"List is empty Nothing will remove"<<endl;
//		//return NULL;
//	}	
//    
//	else if(head=tail) // head tail both remove
//	{
//		delete head;
//		tail=head=0;
//		//return NULL;
//	}
//
//	else // only head remove
//	{
//        ptr =head;
//		head=ptr->getNext();
//		delete ptr;
//		//return head;
//	}
      
     if (head==0 && tail==0)
     {
     	cerr<<"List is empty \n";
	 }
	
      else
	  {
        Node<t>* temp = head;
        head = head->getNext(); 
        delete temp; 
      }
    }
    
template<class t>
void SLL<t>::removeGivenElement(t element)
{
	/* Check 5 Maping Possiblities

     1- Error -> Yes empty or existing not found
     2- Only Head modify -> Yes if given elemnet presenet on head
     3- Only Tail modify -> Yes if given elemnet presenet on tail
     4- Head and Tail both modify -> if only one element and info of that node is same as provided element
     5- Nor Head not Tail Modify-> yes if in between 
     */
     
     if(head==0 && tail==0) // empty
     {
     	cerr<<"List is empty"<<endl;
	 }//End
	 
	 else if(head==tail && element==head->getInfo())
	 {
	 	 delete head;
	 	 head=tail=0;
	 }//End
	 
	 else if(element==head->getInfo()) // more than one node and element on head
	 {
	 	   removeFromHead();
	 }//End
	 else if(element==tail->getInfo()) // more than one node and element on tail
      {
      	     removeFromTail();
	    }//End
	  
	  else 
	  {
	  	   Node<t>* ptr=head;
	  	   
	  	   while(ptr!=tail && element!=ptr->getNext()->getInfo())
	  	   {
	  	   	    ptr->getNext();
			 }
			 
			 if(ptr==tail)
			 {
			 	cerr<<"Element Does't Found"<<endl;
			 }
			 
			 else
			 {
			 	Node<t>* temp=ptr->getNext()->getNext();
			 	delete ptr->getNext();
			 	ptr->setNext(temp);
			 	
			 }
	  }//End
	  
}// End












