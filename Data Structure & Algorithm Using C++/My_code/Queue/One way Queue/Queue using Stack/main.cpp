#include<iostream>
#include"M1_Queue.h"
using namespace std;
int main()
{ 
    M1_Queue<char> q1;
    q1.Enqueue('1');
    q1.Enqueue('2');
    q1.Enqueue('3');
    q1.Enqueue('4');
   cout<<q1.frontValue()<<endl;
   while (!q1.isEmpty())
   {
      cout<<q1.Dqueue()<<endl;
   }
   

    return 0;
}