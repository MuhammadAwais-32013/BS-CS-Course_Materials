#include <iostream>
using namespace std;
template <class t>
class DNode
{
private:
    DNode<t> *prevP;
    t value;
    DNode<t> *nextP;

public:
    DNode(DNode<t> *prevP, t value, DNode<t> *nextP)
    {
        this->prevP = prevP;
        this->value = value;
        this->nextP = nextP;
    }

    void setprevP(DNode<t> *prevP);
    void setvalue(t value);
    void setnextP(DNode<t> *nextP);
    DNode<t> *getprevP();
    t getvalue();
    DNode<t> *getnextP();
    void displayDNode();

};// End of DNode class

// *************************Function Definitions***********************

template <class t>
void DNode<t>::setprevP(DNode<t> *prevP)
{
    this->prevP = prevP;
} // end

template <class t>
void DNode<t>::setvalue(t value)
{
    this->value = value;
} // end

template <class t>
void DNode<t>::setnextP(DNode<t> *nextP)
{
    this->nextP = nextP;
} // end

template <class t>
DNode<t> *DNode<t>::getprevP()
{
    return this->prevP;
} // end

template <class t>
t DNode<t>::getvalue()
{
    return this->value;
    ;
} // end

template <class t>
DNode<t> *DNode<t>::getnextP()
{
    return this->nextP;
} // end

template<class t>
void DNode<t>::displayDNode()
{
    cout<<"("<<this<<") |"<<value<<" |"<<nextP<<" |"<<prevP<<"|"<<endl;
}// End of Display