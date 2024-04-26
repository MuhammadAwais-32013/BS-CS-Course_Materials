#include<iostream>
using namespace std;
template<class t>
class CircularQueue
{
 private:
 	int front;
 	int rear;
 	int size;
 	t *arr;
 	
 	public:
 		CircularQueue(int size=10) // Defualt as well as parametrized
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
void CircularQueue<t>::Enqueue(t element)
{
	if((front==0 && rear==size-1) || rear+1==front)// error
	{
		cerr<<"Queue is full \n";
		return;
	}
	
	else if(rear==-1 && front==-1)// first element 
	{
		rear++;
		front++;
	//	arr[rear]=element;
	
	}
	
	else if(front>0 && rear==size-1) // refill we can remove front>0 (why)
	{  
		rear=0;
		//arr[rear]=element;
	}
	else  // in between element 
	{
		rear++;
	//	arr[rear]=element;
		
	}
	arr[rear]=element;
}// End Enqueue

template<class t>
bool CircularQueue<t>::isEmpty()
{
    if(rear==-1 && front==-1)
	return 	true;
}// End 

template<class t>
bool CircularQueue<t>::isFull()
{
	if((front==0 &&rear==size-1 )|| rear+1==front)
	return true;
}// End

template<class t>
t CircularQueue<t>::Dequeue()
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
	
	else if(front>rear && front==size-1) // refill happened
	{    
	  t element = arr[front];
		front=0;
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
t CircularQueue<t>::frontValue()
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
t CircularQueue<t>::rearValue()
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










