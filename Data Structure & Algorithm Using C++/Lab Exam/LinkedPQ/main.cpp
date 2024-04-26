#include <iostream>
#include "PQ.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	PQ <string> pq1;
	pq1.enqueue(2,"p1");
	pq1.enqueue(0,"p2");
	pq1.enqueue(1,"p3");
	pq1.enqueue(7,"p4");
	pq1.enqueue(5,"p5");
	pq1.enqueue(5,"p6");
	
	while(!pq1.isEmpty())
	{
		
		cout<<pq1.dequeue()<<endl;
		
		
	}
	
	
	return 0;
}
