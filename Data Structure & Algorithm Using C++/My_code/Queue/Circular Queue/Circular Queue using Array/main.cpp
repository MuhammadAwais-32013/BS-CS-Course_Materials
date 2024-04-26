#include<iostream>
#include"CQueue.h"
using namespace std;
int main()
{
    CQueue<char> s1(5);
	s1.Enqueue('b');
	s1.Enqueue('c');
	s1.Enqueue('d');
	s1.Enqueue('e');
	s1.Enqueue('f');
	cout<<s1.isFull()<<endl;
    //s1.Dqueue();
	//s1.Enqueue('g');
	// while(!s1.isEmpty())
	// {
	// 	cout<<s1.Dqueue()<<endl;
	// }
	

    cout<<s1.removeAll()<<endl;
    return 0;
}