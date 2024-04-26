#include<iostream>
#include<string.h>
#include"Stack.h"
using namespace std;
string stringReversal(string text);
int main()
{  
     //Stack<string> s1(5);
    // s1.push("Aw");
    // s1.push("BS");
    // s1.push("Cs"); 

    // while (!s1.isEmpty())
    // {
    //     cout<<s1.pop()<<endl;
    // }
 string text;      
cout<<"Provide a String to reverse \n";
getline(cin,text);
cout<<stringReversal(text);
    return 0;
}

string stringReversal(string text)
{ 
  Stack<string> s1(text.length());  // s1.(4)
  string r_string="";
  for (int i = 0; i < text.length(); i++)
  {
     s1.push (string(1,text[i])); // what if we put 2 or 0
  }
   
   while (!s1.isEmpty())
   {
       r_string+=s1.pop();
    }
   
  return r_string;
}