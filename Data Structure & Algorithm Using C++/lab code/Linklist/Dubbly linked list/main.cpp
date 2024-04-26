#include <iostream>
#include "DLL.h"
using namespace std;

int main(int argc, char **argv)
{
  DLL<int> l1;
  // l1.addToHead(1);
  // l1.addToHead(2);
  l1.addToTail(4);
  l1.addToTail(9);
  l1.addToTail(19); // Part of Assignment
  l1.addToHead(0);
  // l1.addAfterGivenE(4, 33);
  l1.addToHead(20);
   l1.addToTail(21);
  // l1.forwardTraverse();
  // cout<<"After remove Given Element \n";
  l1.addBeforeGivenE(7, 9);
  l1.addBeforeGivenE(2, 7);
  // l1.forwardTraverse();
   l1.addAfterGivenE(4, 33);  // element on head
  // l1.addAfterGivenE(19, 29); // element on tail  // Part Of Assignment
  // l1.addAfterGivenE(33, 34); // element in between
  // l1.addAfterGivenE(35, 77); // element not found
  // l1.removeFromHead(); // Part Of Assignment
  //l1.forwardTraverse();
  // cout << endl;
  // cout<<"Below is reverse Traverse \n";
  // l1.reverseTraverse();
  //  cout<<"After Remove Tail \n";
  //  l1.removeFromTail();
   l1.removeGivenElement(20); // Part of Assignment
  //  l1.removeGivenElement(100);
  //  l1.forwardTraverse();
    l1.forwardTraverse();

  //cout << l1.searchElement(19);
  cout << endl; // Part of Assignment
  // cout<<l1.searchElement(99);
   l1.reverseTraverse(); // Part Of Assignment
  //l1.midElement();

  return 0;
}