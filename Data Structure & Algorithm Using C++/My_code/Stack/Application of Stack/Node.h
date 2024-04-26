#include<iostream>
using namespace std;
template<class t>
class Node
{
  private:
   Node<t>* Next;
   t Data;

   public:
     Node(t Data, Node<t>* Next) 
     {
        this->Data=Data;
        this->Next =Next;
     }

    void setdata(t element);
    void setnext(Node<t>* Next);
    t getdata();
    Node<t>* getnext();
};

template<class t>
void Node<t>::setdata(t data)
{
    this->Data=data;
}

template<class t>
void Node<t>::setnext(Node<t> *Next)
{
    this->Next= Next;
}

template<class t>
t Node<t>::getdata()
{
    return this->Data;
}

template<class t>
Node<t>* Node<t>::getnext()
{
    return this->Next;
}