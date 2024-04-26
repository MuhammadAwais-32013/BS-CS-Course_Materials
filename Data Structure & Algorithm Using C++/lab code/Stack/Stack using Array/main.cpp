#include <iostream>
#include  <bits/stdc++.h>
#include"Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Declaraed a function string reversal that will take a string as a parameter which return reverse string*/
string stringReversal(string text);
using namespace std;
int main(int argc, char** argv) {
	Stack<char> s1(5);
//	s1.push('c');
//	s1.push('d');
//	s1.push('f');
//	s1.push('g');
//	s1.push('A');
//	cout<<"Top value is -> "<<s1.topValue();
//   while(!s1.isEmpty())// s1.isEmpty==false
//	{
//	
// 	cout<<s1.pop()<<endl;
// }

string text;
cout<<"Provide a string to reverse \n";
//// cin>>text;
 getline(cin,text);
 cout<<stringReversal(text);
	return 0;
}

string stringReversal(string text)
{
	Stack<char> s1(text.length());
	string output="";
	for(int i=0; i<text.length(); i++)
	{
		s1.push(text[i]);	
	}
	
	while(!s1.isEmpty())// s1.isEmpty==false
	{
	
	output=output+s1.pop();
}

return output;
}
