#include <iostream>
#include "BSTree.h"
using namespace std;
int main()
{
   BSTree<int> t1; // root=0
    t1.Insert(50);
    t1.Insert(17);
    t1.Insert(19);
    t1.Insert(75);
    t1.Insert(95);
    t1.Insert(18);
    cout<<t1.isBSTree(t1.getRoot());

   //t1.recursiveSearch(t1.getRoot(), 19);
//     t1.preOrderTraverse(t1.getRoot());
//     cout<<endl;
//    t1.inOrderTraverse(t1.getRoot());
//     cout<<endl;
//     t1.postOrderTraverse(t1.getRoot());
    
   // cout<<t1.totalNode(t1.getRoot());
  // t1.Search(17);
    return 0;
}