#include<iostream>
#include"TWLL.h"
using namespace std;
int main(int argc, char** argv)
{  

    TWLL<int> l1;
    l1.addToHead(4);
    l1.addToHead(3);
    l1.addToTail(6);
    l1.addToTail(7);
    l1.forwardTraverse();
    return 0;
}