#include<iostream>
#include"E:\BSCS 3rd Semester\DSA\lab code\L3P3 Singular link List\Node.h"
using namespace std;
template<class t>
class DNode:public Node<t>   // Extend  parent class
{
private:
    DNode<t> *prev;

public:
    DNode(DNode<t> *prev, t info, DNode<t> *next):Node<t>(info,next) // inhe parent funcnalities
    {
        this->prev = prev;
    }

    void setprev(DNode<t> *prev);
   
    DNode<t> *getprev();
    void displayDNode();

};// End of DNode class

// *************************Function Definitions***********************

template <class t>
void DNode<t>::setprev(DNode<t> *prev)
{
    this->prev = prev;
} // end

template <class t>
DNode<t> *DNode<t>::getprev()
{
    return this->prev;
} // end


template<class t>
void DNode<t>::displayDNode()
{   
    Node<t>::displayNode();
    cout<<prev<<")|";
}// End of Display

