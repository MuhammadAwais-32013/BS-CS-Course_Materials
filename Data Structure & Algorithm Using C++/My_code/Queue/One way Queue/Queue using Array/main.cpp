#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue<char> q1(5);
    q1.Enqueue('1');
    q1.Enqueue('2');
    q1.Enqueue('3');
    q1.Enqueue('4');
    q1.Enqueue('5');
    cout << "Front value is : " << q1.frontValue() << endl;
    cout << "Rear value is : " << q1.rearValue() << endl;
    // while (!q1.isEmpty())
    // {
    //     cout << q1.Dqueue() << endl;
    // }
    
    cout<<q1.dqueue_OneGo();
    return 0;
}