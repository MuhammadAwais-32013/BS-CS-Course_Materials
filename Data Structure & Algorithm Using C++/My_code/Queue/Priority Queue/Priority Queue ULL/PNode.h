#include <iostream>
#include "E:\BSCS 3rd Semester\DSA\My_code\linked list\Singly linked list\Node.h"
using namespace std;
template <class t>
class PNode : public Node<t>
{
private:
    int prio;

public:
    PNode(int prio, t data, Node<t> *next) : Node<t>(data, next)
    {
        this->prio = prio;
    }

    void setprio(int prio);
    int getprio();
    void displayPNode();
};

template <class t>
void PNode<t>::setprio(int prio)
{
    this->prio = prio;
} // End

template <class t>
int PNode<t>::getprio()
{
    return this->prio;
} // end

template <class t>
void PNode<t>::displayPNode()
{
    cout << this->data << "\t";
    cout << this->next << "\t";
    cout << this->prio;
}