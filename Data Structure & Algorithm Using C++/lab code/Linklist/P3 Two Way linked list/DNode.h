#include<iostream>
#include"E:\BSCS 3rd Semester\DSA\lab code\L3P3 Singular link List\node.h"
using namespace std;
template <class t>
class DNode: public Node<t>  // : used to inherited parent
{
	private:
		DNode<t> *prev;
	public:
		DNode(DNode<t> *prev, t info, DNode<t> *next ): Node<t>(info, next) // Parent constructor 
		// we can go from child to parent not parent to child
		{
			this->prev=prev;
		}
		
		void setPrev(DNode<t> *prev);
		DNode<t>* getPrev();
		void displayNode();
}; //End of DNode Class
//*********************Function Definations******************
template <class t>
void DNode<t>::setPrev(DNode<t> *prev)
{
  this->prev=prev;	
}
template <class t>
DNode<t>* DNode<t>:: getPrev()
{
	return this->prev;
}
template <class t>
void DNode<t>::displayNode()
{
	Node<t>::displayNode();
	cout<<this->prev<<") |"; // we can remove this->
}
