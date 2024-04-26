#include <iostream>
#include "Node.h"
using namespace std;
template <class t>
class SLL
{
private:
    Node<t> *head;
    Node<t> *tail;

public:
    SLL()
    {
        head = 0;
        tail = 0;
    }

    void sethead(Node<t> *first);
    void settail(Node<t> *last);
    Node<t> *gethead();
    Node<t> *gettail();
    void addtohead(t element);
    void addtotail(t element);
    void traverse();
    void addAfterGivenE(t existingE, t newE);
    void addBeforeGivenE(t newE, t existingE);
    void removehead();
    void removetail();
    void removegivenE(t element);
    bool searchE(t element);
};

template <class t>
void SLL<t>::sethead(Node<t> *first)
{
    head = first;
}

template <class t>
void SLL<t>::settail(Node<t> *last)
{
    tail = last;
}

template <class t>
Node<t> *SLL<t>::gethead()
{
    return head;
}

template <class t>
Node<t> *SLL<t>::gettail()
{
    return tail;
}

template <class t>
void SLL<t>::addtohead(t element)
{
    Node<t> *n = new Node<t>(element, 0);
    if (head == 0 && tail == 0)
    {
        head = n;
        tail = n; /// if only head=n then get segmentation error in Node class
    }

    else
    {
        n->setnext(head);
        head = n;
    }
} // end

template <class t>
void SLL<t>::addtotail(t element)
{
    Node<t> *n = new Node<t>(element, 0);
    if (head == 0 && tail == 0)
    {
        head = n;
        tail = n;
    }

    else
    {
        tail->setnext(n);
        tail = n;
    }
}

template <class t>
void SLL<t>::traverse()
{
    Node<t> *n = head;
    while (n != 0)
    {
        n->displayNode();
        n = n->getnext();
    }
}

template <class t>
void SLL<t>::addAfterGivenE(t existingE, t newE)
{
    if (head == 0 && tail == 0)
    {
        cerr << "List is empty \n";
    }

    else if (existingE == tail->getinfo())
    {
        addtotail(newE);
    }

    else
    {
        Node<t> *ptr = head;
        while (ptr != tail && existingE != ptr->getinfo())
        {
            ptr = ptr->getnext();
        }

        if (ptr == tail)
        {
            cerr << "Element Not Found \n";
        }

        else
        {
            Node<t> *n = new Node<t>(newE, 0);
            n->setnext(ptr->getnext());
            ptr->setnext(n);
        }
    }
}

template <class t>
void SLL<t>::addBeforeGivenE(t newE, t existingE)
{
    if (head == 0 && tail == 0)
    {
        cerr << "List is empty \n";
    }

    else if (existingE == head->getinfo())
    {
        addtohead(newE);
    }

    else
    {
        Node<t> *ptr = head;
        while (ptr != tail && existingE != ptr->getnext()->getinfo())
        {
            ptr = ptr->getnext();
        }

        if (ptr == tail)
        {
            cerr << "Element Not Found \n";
        }

        else
        {
            Node<t> *n = new Node<t>(newE, 0);
            n->setnext(ptr->getnext());
            ptr->setnext(n);
        }
    }
}

template <class t>
void SLL<t>::removehead()
{
    if (head == 0)
    {
        cerr << "List is empty\n";
    }

    else
    {
        Node<t> *temp = head->getnext();
        delete head;
        head = temp;
    }
}

template <class t>
void SLL<t>::removetail()
{
    if (tail == 0)
    {
        cerr << "List is empty\n";
    }

    else
    {

        Node<t> *ptr = head;
        while (ptr->getnext() != tail)
        {
            ptr = ptr->getnext();
        }

        ptr->setnext(0);
        delete tail;
        tail = ptr;
    }
}

template <class t>
void SLL<t>::removegivenE(t element)
{
    if (head == 0 && tail == 0)
    {
        cerr << "list is empty \n";
    }

    else if (element == head->getinfo())
    {
        Node<t> *temp = head->getnext();
        delete head;
        head = temp;
    }

    else if (element == tail->getinfo())
    {
        Node<t> *ptr = head;
        while (ptr->getnext() != tail)
        {
            ptr = ptr->getnext();
        }

        ptr->setnext(0);
        delete tail;
        tail = ptr;
    }

    else if (head == tail)
    {
        delete head;
        head = tail = 0;
    }

    else
    {
        Node<t> *ptr = head;
        while (ptr != tail && element != ptr->getnext()->getinfo())
        {
            ptr = ptr->getnext();
        }

        if (ptr == tail)
        {
            cerr << "Element not in the list\n";
        }

        else
        {
            /* Node<t> *temp=ptr->getnext();
             delete ptr->getnext();
             ptr->setnext(temp->getnext());  why here is infinite loop */

            Node<t> *temp = ptr->getnext()->getnext();
            delete ptr->getnext();
            ptr->setnext(temp);
        }
    }
}

template<class t>
bool SLL<t>::searchE(t element)
{  
//     if(head==0 && tail==0 )
//     {
//     	return false;
// 	}
	
// 	 Node<t> *ptr=head;
// 	while(ptr!=0 && element!=ptr->getinfo())
// 	{
// 	  ptr=ptr->getnext();
//  }    
//     if(ptr==0)
//     {
//     	return false;
// 	}
// 	  else
// 	  {
// 	  	return true;
// 	  }
	  
// End of search
//bool SLL<t>::searchE(t element)

    
       Node<t> *ptr=head;
       while (ptr!=0)
       {  if (element==ptr->getinfo())
        {
           return true;  
        }
         ptr=ptr->getnext();
       }
     return false;
}
    
