/*Class Node which store the information and address of next node in variable t Data and t Next*/
#include <iostream>
using namespace std;
template <class t> // Generic Data Type
class Node
{
private:
    t data;        // info
    Node<t> *next; // address of next node

public:
    Node(t data, Node<t> *next)
    {
        this->data = data;
        this->next = next;
    }

    void setData(t data);
    void setNext(Node<t> *next);

    t getData();
    Node<t> *getNext();

    void display();

}; // End of class Node

template <class t>
void Node<t>::setData(t data) //::scope resulution operator

{
    this->data = data;
} // End of setData

template <class t>
void Node<t>::setNext(Node<t> *next)
{
    this->next = next;
} // End of setnext

template <class t>
t Node<t>::getData()
{
   return this->data;
} // End

template <class t>
Node<t> *Node<t>::getNext()
{
    return this->next;
} // End

template <class t>
void Node<t>::display()
{
    cout << "(" << this << ") |" << data << "|" << next << "|" << endl;
} // End
