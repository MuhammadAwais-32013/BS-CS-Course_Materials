/*In SLL class g=first we include our user made Header file -> Node.h. In SLL class we Decalared and
defined required function with passage of time. SLL class perform all methods and implementation
of linkedlist*/
#include <iostream> // Standard Headerfile
#include "Node.h"   // user define headerfile
using namespace std;
template <class t> // It's enable the generic variable
class SLL
{
private:
    Node<t> *head; // first Node
    Node<t> *tail; // last Node

public:
    SLL()
    {
        head = 0;
        tail = 0;
    }

    //************** Function Decalarations ****************

    void setHead(Node<t> *first);
    void setTail(Node<t> *last);
    Node<t> *getHead();
    Node<t> *getTail();
    void traverse(); // vist all
    void addToHead(t element);
    void addToTail(t element);
    void addAfterGivenElement(t newE, t existingE);
    void addBeforeGivenElement(t existingE, t newE);
    void searchElement(t element);
    void removeFromTail();
    void removeFromHead();
    /*write a function name remove given element that will take an element as a parameter.
    the function should find the given element and delete it if element is present
    otherwise display an error.*/
    void removeGivenElement(t element);

}; // End of Class SLL

//***************************** Functions Definations ************************

template <class t>
void SLL<t>::setHead(Node<t> *first)
{
    head = first;
} // End of Set Head

template <class t>
void SLL<t>::setTail(Node<t> *last)
{
    tail = last;
} // End of Set Tail

template <class t>
Node<t> *SLL<t>::getHead()
{
    return head;
} // End of Get Head

template <class t>
Node<t> *SLL<t>::getTail()
{
    return tail;
} // End of Get Tail

template <class t>
void SLL<t>::traverse()
{
    Node<t> *n = head;

    while (n != NULL)
    {
        n->display();
        // cout << n->getData()<<endl; // display Data of N
        n = n->getNext(); // get address of next
    }

} // End of traverse

template <class t>
void SLL<t>::addToHead(t element)
{
    /* Check 5 Maping Possiblities

     1- Error -> No
     2- Only Head modify -> Yes b/c we add on head so position change
     3- Only Tail modify -> No
     4- Head and Tail both modify -> No
     5- Nor Head not Tail Modify-> No
     */

    Node<t> *p = new Node<t>(element, NULL);

    if (head == 0 && tail == 0) // empty
    {
        head = p;
        tail = p;
    }

    else // Not empty
    {
        p->setNext(head);
        head = p;
    }

} // End of Add To Head

template <class t>
void SLL<t>::addToTail(t element)
{
    /* Check 5 Maping Possiblities
    1- Error -> No
    2- Only Head modify -> No
    3- Only Tail modify -> Yes b/c we add on tail so position change
    4- Head and Tail both modify -> No
    5- Nor Head not Tail Modify-> No
    */

    Node<t> *ptr = new Node<t>(element, NULL);

    if (head == 0 && tail == 0) // empty
    {
        head = ptr;
        tail = ptr;
    }

    else // Not empty
    {
        tail->setNext(ptr);
        tail = ptr;
    }

} // End of Add To Tail

template <class t>
void SLL<t>::addAfterGivenElement(t newE, t existingE)
{
    /* Check 5 Maping Possiblities
   1- Error -> if empty
   2- Only Head modify -> No
   3- Only Tail modify -> Yes b/c we add on tail so position change
   4- Head and Tail both modify -> No
   5- Nor Head not Tail Modify-> Yes if we add in between
   */

    if (head == 0 && tail == 0) // empty
    {
        cerr << "List is empty So, there no addtion " << endl;
    }

    else if (existingE == tail->getData()) // replace tail
    {
        addToTail(newE);
    }

    // else if(existingE==tail->getData()) // if element on head
    // {
    //     addToTail(newE);
    // }

    else // !Head Nor Tail
    {
        Node<t> *ptr = head;

        while (ptr != tail && existingE != ptr->getData()) // ptr break before excute the loop if element on head
        {
            ptr = ptr->getNext();
        }

        if (ptr == tail) // 1st condition
        {
            cerr << "Element not Found " << endl;
        }

        else // 2nd condition
        {
            Node<t> *n = new Node<t>(newE, 0);
            n->setNext(ptr->getNext());
            ptr->setNext(n);
        }
    }

} // End of Add After Given Element

template <class t>
void SLL<t>::addBeforeGivenElement(t existingE, t newE)
{
    /* Check 5 Maping Possiblities
  1- Error -> if empty
  2- Only Head modify -> No
  3- Only Tail modify -> Yes b/c we add before tail so position change
  4- Head and Tail both modify -> No
  5- Nor Head not Tail Modify-> Yes if we add in between
  */

    if (head == 0 && tail == 0) // empty
    {
        cerr << "List is empty " << endl;
    }

    else if (existingE == head->getData())
    {
        addToHead(newE);
    }
    else // !H && !T
    {
        Node<t> *ptr = head;

        while (ptr != tail && existingE != ptr->getNext()->getData())
        {
            ptr = ptr->getNext();
        }

        if (ptr == tail) // 1st condition
        {
            cerr << "Element Not Found " << endl;
        }

        else // 2nd condtion
        {
            Node<t> *p = new Node<t>(newE, 0);
            p->setNext(ptr->getNext());
            ptr->setNext(p);
        }
    }
} // End of Add Before Given Element

template <class t>
void SLL<t>::searchElement(t element)
{
    /* Check Maping Possiblities
  1- Error -> if empty
  2- Error -> if element not found
  3- Found element
   */

    if (head == 0 && tail == 0) // if empty
    {
        cerr << "list is empty \n";
    }

    else // Not empty
    {
        Node<t> *i = head;

        while (i != 0 && element != i->getData())
        {
            i = i->getNext();
        }

        if (i == 0)
        {
            cerr << element << " is not Found in list \n";
        }

        else
        {
            cout << element << "  is Found in the list \n";
        }
    }
} // End of Search element

template <class t>
void SLL<t>::removeFromTail()
{
    /* Check Maping Possiblities
  1- Error -> if empty
  2- head=tail remove head & tail
  3- tail=last remove  only tail
   */

    if (head == 0 && tail == 0)
    {
        cerr << "Emtpy list can not perform deletion task" << endl;
    }

    else if (head == tail) // Head & Tail
    {
        delete tail;
        head = tail = 0;
    }

    else // only tail

    {
        Node<t> *ptr = head;

        while (ptr->getNext() != tail)
        {
            ptr = ptr->getNext();
        }

        delete tail;
        ptr->setNext(0);
        tail = ptr;
    }
} // End of Remove from tail

template <class t>
void SLL<t>::removeFromHead()
{
    if (head == 0 && tail == 0) // list is empty
    {
        cerr << "list is empty \n";
    }

    else
    {
        Node<t> *ptr = head->getNext();
        delete head;
        head = ptr;
    }
} // End of Remove from Head

template <class t>
void SLL<t>::removeGivenElement(t element)
{
    /* Check 5 Possible Maping
 1- Error -> if empty && element not found in list
 2- Only Head modify ->   if element on head
 3- Only Tail modify -> if element on tail
 4- Head and Tail both modify -> only one element in list that  is the given element
 5- Nor Head not Tail Modify-> Yes if remove  from in  between
 */

    if (head == 0 && tail == 0)
    {
        cerr << "List is empty \n";
    }
    else if (element == head->getData()) // more than one element and element  on head
    {
        removeFromHead();
    }
    else if (element == tail->getData()) // more than one element and element on tail
    {
        removeFromTail();
    }
    else if (head == tail) // only one element in list which is given element
    {
        delete head;
        head = tail = 0;
    }
    else // Not head Nor tail
    {
        Node<t> *ptr = head;

        while (ptr != tail && element != ptr->getNext()->getData())
        {
            ptr = ptr->getNext();
        }

        if (ptr == tail) // 1st condition
        {
            cerr << "Element is not Found in list \n";
        }
        else // 2nd condition
        {
            Node<t> *temp = ptr->getNext()->getNext();
            delete ptr->getNext();
            ptr->setNext(temp);
        }
    }

} // End Remove From Given Element