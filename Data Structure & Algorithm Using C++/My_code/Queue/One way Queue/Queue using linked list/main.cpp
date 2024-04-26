#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue<char> q1;
    q1.Enqueue('a');
    q1.Enqueue('b');
    q1.Enqueue('c');
    q1.Enqueue('d');
    q1.Enqueue('e');
    q1.Enqueue('f');
    cout<<q1.getcount();
    // cout<<q1.isFull();
     while (!q1.isEmpty())
     {
         cout << q1.Dqueue() << endl;
     }

    return 0;
}