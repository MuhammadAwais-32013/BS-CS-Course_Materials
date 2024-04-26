#include <iostream>
#include "DNode.h"
using namespace std;
template <class t>
class TWLL
{
private:
  DNode<t> *head;
  DNode<t> *tail;

public:
  TWLL()
  {
    head = NULL;
    tail = NULL;
  }

  void setHead(DNode<t> *firstP);
  void setTail(DNode<t> *lastP);
  DNode<t> *getHead();
  DNode<t> *getTail();
  //********Implemenetation of node*********
  void addToHead(t element);
  void addToTail(t element);
  void forwardTraverse();
  

}; // Endo of DNode class

//**************************Functions Definitions*************************

template <class t>
void TWLL<t>::setHead(DNode<t> *firstP)
{
  head = firstP;
} // end

template <class t>
void TWLL<t>::setTail(DNode<t> *lastP)
{
  tail = lastP;
} // end

template <class t>
DNode<t> *TWLL<t>::getHead()
{
  return head;
} // end

template <class t>
DNode<t> *TWLL<t>::getTail()
{
  return tail;

} // end

//**********************Implementation of node****************

template <class t>
void TWLL<t>::addToHead(t element)
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
    n->setnextP(head);
    head->setprevP(n);
    head = n;
  }

} // End of Add To Head

template <class t>
void TWLL<t>::addToTail(t element)
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
    tail = n;
    head = tail;
  }

  else
  {
    DNode<t> *n = new DNode<t>(0, element, 0);
    n->setprevP(tail);
    tail->setnextP(n);
    tail = n;
  }

} // End Add To Tail

template<class t>
void TWLL<t>::forwardTraverse()
{
  DNode<t> *ptr=head;
  while (ptr!=NULL)
  {
    ptr->displayDNode();
    ptr=ptr->getnextP();
  }
  
}
