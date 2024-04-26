#include<iostream>
using namespace std;
template<class t>
class Stack
{
   	 private:
   	 int top;
   	 int size;
   	 //	t arr[size]; // Static declaration/ compile time 
   	 t *arr;
   	  // arr=new t(size) 
   	  public:
   	  	Stack(int size )
   	  	{
   	  		top=-1;
   	  		this->size=size;
   	  		arr=new t(size);
			 }
			 
			 void push(t element);
			 t pop();
			 bool isEmpty();
			 bool isFull();
			 t topValue();
						 
}; // end of class Stack


template<class t>
void Stack<t>::push(t element)
{
	if(top==size-1)
	{
		cerr<<"Stack overflow \n";
	}
	
	else
	{
		top++;
		arr[top]=element;
	}
		
}

template<class t>
t Stack<t>::pop()
{
	if(top<0) // ==-1
	{
		cerr<<"Stack is empty \n";
	}
	
	else
	{   t element=arr[top];
	    top--;
		return element;	
	}
	
}// end of Pop

template<class t>
bool Stack<t>::isEmpty()
{
	if(top==-1)
	
		return true;
	
	
	else
	
		return false;
	// return top==-1;
}

template<class t>
bool Stack<t>::isFull()
{
	if(top==size-1)
	
		return true;
	
	
	else
	
		return false;
	// return top==size-1;
	
}// end


template<class t>
t Stack<t>::topValue()
{ 
    if(top==-1)
    {
    	cerr<<" Stack is underflow \n";
	}
	else
	{
		return arr[top];
	}
}// end










