#include <iostream>
#include"CircularQueue.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	CircularQueue<char> s1(5);
	s1.Enqueue('b');
	s1.Enqueue('c');
	s1.Enqueue('d');
	s1.Enqueue('e');
	s1.Enqueue('f');
	s1.isFull();
    //s1.Dequeue();
	//s1.Enqueue('g');
	while(!s1.isEmpty())
	{
		cout<<s1.Dequeue()<<endl;
	}
	
	return 0;
}
