#include <iostream>
#include "LinkedTree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedTree<int> t1;//root=0
	t1.insert(12);
	t1.insert(14);
	t1.insert(16);
	t1.insert(5);
	t1.insert(8);
	t1.insert(7);
	t1.insert(10);
	t1.insert(15);	
	
	//cout<<t1.isBSTree(t1.getRoot())<<endl;
	 t1.preOrder(t1.getRoot());
	 cout<<endl;
	 cout<<t1.findLeftSuccessor(t1.getRoot());
	// cout<<endl;
	// cout<<"Iterative Search \n";
	// cout<<t1.search(14);
	// cout<<endl;
	// cout<<t1.search(10);
	// cout<<"\n Recursive Search \n";
	// cout<<t1.searchRecursively(t1.getRoot(),8);
	// cout<<endl;
	// cout<<t1.recursiveSum(t1.getRoot());
	
	return 0;
}
