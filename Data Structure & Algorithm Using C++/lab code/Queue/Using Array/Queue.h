#include<iostream>
using namespace std;
template<class t>
class Queue
{
 private:
 	int front;
 	int rear;
 	int size;
 	t *arr;
 	
 	public:
 		Queue(int size=10) // Defualt as well as parametrized
 		{
 		 rear=-1;
		  front=-1;
		  this->size=size;
		  arr=new t(this->size); 	
		 }
		 
 		void Enqueue(t element);
 		t Dequeue();
 		bool isEmpty();
 		bool isFull();
	    t frontValue();
 		t rearValue();
	
}; // End of Class

template<class t>
void Queue<t>::Enqueue(t element)
{
	if(rear==size-1)// error
	{
		cerr<<"Queue is full \n";
	}
	
	else if(rear==-1 && front-1)// first element 
	{
		rear++;
		front++;
		arr[rear]=element;
	
	}
	
	else  // in between element 
	{
		rear++;
		arr[rear]=element;
		
	}
}// End 

template<class t>
bool Queue<t>::isEmpty()
{
    if(rear==-1 && front==-1)
	return 	true;
}// End 

template<class t>
bool Queue<t>::isFull()
{
	if(rear==size-1)
	return true;
}// End

template<class t>
t Queue<t>::Dequeue()
{  
	if(rear==-1 && front==-1)// error
	{
		cerr<<"Queue is empty \n";
	}
	
	else if(rear==front)// element on first  
	{
		
		t element=arr[front];
		rear=-1;
		front=-1;
		return element;
	}
	
	else //  more than one element 
	{
	    
	    t element=arr[front];
	     front++;
		return element;
	}
}// end of Dequeue



template<class t>
t Queue<t>::frontValue()
{
	if(front==-1)// error
	{
		cerr<<"Queue is empty \n";
	}

	
	else  
	{
		return arr[front];
	}
		
}// End frontValue

template<class t>
t Queue<t>::rearValue()
{
	if(rear==-1)// error
	{
		cerr<<"Queue is empty \n";
	}

	
	else  
	{
		return arr[rear];
	}
		
}// End frontValue










