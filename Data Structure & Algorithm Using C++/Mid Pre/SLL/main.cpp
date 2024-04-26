#include<iostream>
#include"SLL.h"
using namespace std;
int main(int agrs, char** avgr)
{  
    SLL<int> l1;
    l1.addtohead(7);
    l1.addtohead(78);
    l1.addtotail(9);
    l1.addAfterGivenE(9,14);
    l1.addBeforeGivenE(99,14);
    l1.removegivenE(99);
    // l1.removehead();
    // l1.removetail();
    l1.traverse();
    cout<<l1.searchE(9)<<endl;
    l1.traverse();
    return 0;
}