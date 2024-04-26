#include<iostream>
using namespace std;
template<class t>
class Node
{
  private:
  t info;
  Node<t> *next;
  public:
  Node(t info , Node<t> *next=NULL)
  {
    this->info=info;
    this->next=next;
  }
  void setinfo(t info);
  void setnext(Node<t> *next);
  t getinfo();
  Node<t>* getnext();
  void displayNode();

};

template<class t>
void Node<t>::setinfo(t info)
{
    this->info=info;
}

template<class t>
void Node<t>::setnext(Node<t> *next)
{
  this->next=next;   //// Segmentation fualt occur when change in SLL class
}
template<class t>
t Node<t>::getinfo()
{
  return this->info;
}

template<class t>
Node<t>* Node<t>::getnext()
{
   return this->next;
}

template<class t>
void Node<t>::displayNode()
{
   cout<<"("<<this<<") |"<<info<<"|"<<next<<endl;
}