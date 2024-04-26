#include <iostream>
#include "DNode.h"
using namespace std;
template <class t>
class DLL
{
private:
    DNode<t> *head;
    DNode<t> *tail;

public:
    DLL()
    {
        head = 0;
        tail = 0;
    }

    void setHead(DNode<t> *first);
    void setTail(DNode<t> *last);
    DNode<t> *getHead();
    DNode<t> *getTail();
    //*********Implementation of nodes********************
    void addToHead(t element);
    void addToTail(t element); // // Part of Assignment 
    void forwardTraverse();
    void reverseTraverse(); // // Part Of Assignment
    void addBeforeGivenE(t newE, t existingE);
    void addAfterGivenE(t existingE, t newE); // // Part Of Assignment
    void removeFromHead();                    // // Part Of Assignment
    void removeFromTail();
    void removeGivenElement(t element); // // Part of Assignment
    bool searchElement(t element);  // // Part of Assignment
    void midElement();

}; // End of DLL class

//***********************Functions Definitation***************

template <class t>
void DLL<t>::setHead(DNode<t> *first)
{
    head = first;
} // end

template <class t>
void DLL<t>::setTail(DNode<t> *last)
{
    tail = last;

} // End

template <class t>
DNode<t> *DLL<t>::getHead()
{
    return head;

} // end

template <class t>
DNode<t> *DLL<t>::getTail()
{
    return tail;

} // end

template <class t>
void DLL<t>::addToHead(t element)
{
    /*5 possible scenarios
   1-> Error -> No
   2-> Modify head only -> if list one or more having element
   3-> Modify tail only -> No
   4-> Modify head and tail-> if list is empty
   5-> Neither head nor tail modify -> No
    */

    DNode<t> *n = new DNode<t>(0, element, 0);
    if (head == 0 && tail == 0)
    {
        head = tail = n;
    }

    else
    {
        n->setNext(head); //  why not typecasting
        head->setprev(n);
        head = n;
    }

} // end of Add To Head

template <class t>
void DLL<t>::addToTail(t element)
{
    /*5 possible scenarios
1-> Error -> No
2-> Modify head only -> No
3-> Modify tail only -> if list is having one or more element
4-> Modify head and tail-> if list is empty
5-> Neither head nor tail modify -> No
 */

    DNode<t> *n = new DNode<t>(0, element, 0);
    if (head == 0 && tail == 0)
    {
        head = tail = n;
    }

    else
    {
        tail->setNext(n);
        n->setprev(tail);
        tail = n;
    }

} // End of Add To Tail

template <class t>
void DLL<t>::forwardTraverse()
{
    DNode<t> *ptr = head;
    while (ptr != NULL)
    {
        ptr->displayDNode();
        cout << endl;
        ptr = (DNode<t> *)ptr->getNext(); // typcasting explicit
    }
} // End of Forward Traverse

template <class t>
void DLL<t>::reverseTraverse()
{
    DNode<t> *ptr = tail;
    while (ptr != NULL)
    {
        ptr->displayDNode();
        cout << endl;
        ptr = ptr->getprev();   //why not here
    }

} // End of Reverse traverse

template <class t>
void DLL<t>::addBeforeGivenE(t newE, t existingE)
{
    /*5 possible scenarios
1-> Error -> yes if empty
2-> Modify head only -> if element is on head
3-> Modify tail only -> No
4-> Modify head and tail-> No
5-> Neither head nor tail modify -> if element is in between of list
*/

    if (head == 0 && tail == 0)
    {
        cerr << "List is empty \n";
    }

    else if (existingE == head->getInfo())
    {
        addToHead(newE);
    }

    else
    {
        DNode<t> *ptr = head;
        while (ptr != tail && existingE != ptr->getNext()->getInfo()) // why not typcasting
        {
            ptr = (DNode<t> *)(ptr->getNext()); // why here is typcasting
        }

        if (ptr == tail) // 1st condition
        {
            cerr << "Existing element Not found \n";
        }

        else // Found
        {
            DNode<t> *n = new DNode<t>(0, newE, 0);
            n->setNext(ptr->getNext());
            n->setprev(ptr);
            ptr->setNext(n);
            ((DNode<t> *)n->getNext())->setprev(n);
        }
    }
} // End of Add Before Given Element

template <class t>
void DLL<t>::addAfterGivenE(t existingE, t newE)
{
    /*5 possible scenarios
  1-> Error -> yes if empty
  2-> Modify head only -> No
  3-> Modify tail only -> if element is on tail
  4-> Modify head and tail-> No
  5-> Neither head nor tail modify -> if element is in between of list
   */
    if (head == 0 && tail == 0)
    {
        cerr << "List is empty \n";
    }

    else if (existingE == tail->getInfo())
    {
        addToTail(newE);
    }

    else
    {
        DNode<t> *ptr = head;
        while (ptr != tail && existingE != ptr->getInfo()) // what if we use ptr!=tail
        {
            ptr = (DNode<t> *)ptr->getNext();
        }

        if (ptr == tail)
        {
            cerr << existingE<<"  is Not Found \n";
        }

        else
        {
            DNode<t> *n = new DNode<t>(0, newE, 0);
            n->setNext(ptr->getNext());
            n->setprev(ptr);
            ptr->setNext(n);
            ((DNode<t> *)n->getNext())->setprev(n);
        }
    }

} // End of Add After Given Element

template <class t>
void DLL<t>::removeFromHead()
{
    /*5 possible scenarios
1-> Error -> yes if empty
2-> List have node (may be one or more)->Delete Head
 */
    if (head == 0 && tail == 0)
    {
        cerr << "List is empty So, nothing will delete \n";
    }
    else if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        DNode<t> *temp = (DNode<t> *)head->getNext();
        temp->setprev(0);
        delete head;
        head = temp;
    }

} // End of Remove from Head

template <class t>
void DLL<t>::removeFromTail()
{
    /*5 possible scenarios
1-> Error -> yes if empty
2-> List have node (may be one or more)->Delete Tail
 */
    if (head == 0 && tail == 0)
    {
        cerr << "List is empty So, nothing will delete \n";
    }
    else if (head == tail)
    {
        delete tail;
        head = tail = 0;
    }
    else
    {
        DNode<t> *temp = tail->getprev();
        temp->setNext(0);
        delete tail;
        tail = temp;
    }

} // End of Remove from Tail

template <class t>
void DLL<t>::removeGivenElement(t element)
{
    /*5 possible scenarios
1-> Error -> yes if empty
2-> Delete head only -> if element is on head
3-> Delete tail only -> if element is on tail
4-> Delete head and tail-> only one element in list
5-> Neither head nor tail delete -> if element is in between of list
 */

    if (head == 0 && tail == 0) // empty
    {
        cerr << "List is empty, Deletion can not possible \n";
    }

    else if (head == tail) // delete head and tail
    {
        delete head;
        head = tail = 0;
    }

    else if (element == head->getInfo()) // delete head
    {
        removeFromHead();
    }

    else if (element == tail->getInfo()) // delete tail
    {
        removeFromTail();
    }

    else // // delete neither head nor tail
    {
        DNode<t> *ptr = head;

        while (ptr != tail && element != ptr->getInfo()) // what if element on tail
        {
            ptr = (DNode<t> *)ptr->getNext();
        }

        if (ptr == tail)
        {
            cerr <<element<< " is not exist \n";
        }

        else
        {
            // ptr->setNext(ptr->getNext()->getnext())
            // DNode<t> *temp = ((DNode<t> *)ptr->getNext()->getNext());
            // temp->setprev(ptr);
            // delete ptr->getNext();
            // ptr->setNext(temp);
             DNode<t> *temp=ptr;
            ptr=(DNode<t>*)ptr->getNext();
           
            ptr->setprev(temp->getprev());
            temp->getprev()->setNext(ptr);
            delete temp;
        }
    }

} // End of Remove Given Element

template<class t>
bool DLL<t>::searchElement(t element)
{
    DNode<t> *ptr=head;
    while (ptr!=tail && element!=ptr->getNext()->getInfo())
    {
        ptr=(DNode<t>*)ptr->getNext();
    }
    
    if (ptr==tail)
    {
        return false;
    }
    
   else
   {
       return true;
   }
}// End of Search Element Class

template<class t>
void DLL<t>::midElement()
{ 
     DNode<t> *ptr=head;
     float counter=0;
     float mid=0;
     while (ptr!=NULL)
     {
        ptr=(DNode<t>*)ptr->getNext();
        counter++;
     }
     
     ptr=head;
     mid=counter/2;
     cout<<"Conter is "<<counter<<endl;
      cout<<"Mid is "<<mid<<endl;

     for (float i = 1; i < mid; i++)
     {
         ptr=(DNode<t>*)ptr->getNext();
     }
      
      cout<<"Information on mid is  "<<ptr->getInfo();
      cout<<endl;
      cout<<"Address of Mid  is "<<ptr<<endl;
      cout<<"Next of Mid  is "<<ptr->getNext();

}// End Mid Element