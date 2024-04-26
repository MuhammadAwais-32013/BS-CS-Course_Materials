#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
    Stack<string> s1;
    s1.push("C++");
    s1.push("Java");
    s1.push("Js");

    while (!s1.isEmpty())
    {
       cout<<s1.pop()<<endl;   
    }
    
    return 0;
}