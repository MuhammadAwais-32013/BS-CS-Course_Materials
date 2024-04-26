#include <iostream>
#include"DLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	DLL<int> l1;
	l1.addToHead(20);
	l1.addToHead(10);
	l1.addToHead(15);
	l1.addToTail(23);
	l1.addToTail(43);
	l1.addToTail(53);
    l1.removeFromTail();
	l1.forwardTraverse();
	return 0;
}
