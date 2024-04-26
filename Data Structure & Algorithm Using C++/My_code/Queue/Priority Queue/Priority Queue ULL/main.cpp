#include <iostream>
#include "PQueue.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{

    PQueue<string> pq1;
    pq1.Enqueue(2, "p1");
    pq1.Enqueue(0, "p2");
    pq1.Enqueue(4, "p3");
    pq1.Enqueue(5, "pp");
    pq1.Enqueue(5, "p4");
    pq1.Enqueue(3, "p5");
    // cout << "\n";
    // cout << "Front value is : " << pq1.frontValue() << endl;
    // cout << "Rear value is : " << pq1.rearvalue() << endl;
    // cout <<"Delete all in one Go : "<< pq1.allDelete();
    while (!pq1.isEmpty())
    {
        cout << pq1.Dqueue() << endl;
    }

    return 0;
}