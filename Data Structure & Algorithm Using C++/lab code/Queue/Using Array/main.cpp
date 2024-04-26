#include <iostream>
#include"Queue.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue<char> q1(5);// r=-1, f=-1
	q1.Enqueue('a');// f=0 r=1 |a|
	q1.Enqueue('b');
	q1.Enqueue('c');
	q1.Enqueue('d');
	q1.Enqueue('e');
	cout<<"Front value -> "<<q1.frontValue()<<endl;
	cout<q1.Dequeue();
//	q1.Enqueue('h'); // error 
	
	
	while(!q1.isEmpty())
	{
		cout<<q1.Dequeue()<<endl;
	}<<"Rear value -> "<<q1.rearValue()<<endl;
//	cout<<q1.isFull();
//	cout<<q1.Dequeue();
//	cout<<q1.Dequeue();
//	cout<
	
	
	return 0;
}
