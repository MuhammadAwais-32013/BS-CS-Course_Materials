#include <iostream>
#include<cctype>
#include"linkedStack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Declaraed a function string reversal that will take a string as a parameter which return reverse string*/
string stringReversal(string text);
/* Decalare a function infix to posfix that take an infix as a paramerter and return postfix
equelent */
string infixToPostfix(string infix); // take infix return posfix
int prec(char op); // For precedence 
string infixToPrefix(string infix);// infix to prefix
string postfixEvoluation(string postfix); // postfix Evoluation 
using namespace std;
int main(int argc, char** argv) {
	linkedStack<char> s1;
	int op;
	//string infix;
	//cin>>op;
	string text;
	do
	{
	cout<<"Press 1 to stack Reversal \n";
	cout<<"Press 2 to convert infix to postfix  \n";
	cout<<"Press 3 to convert infix to prefix  \n";
	cout<<"Press 0 to exist \n";
	cin>>op;
	switch(op)
	{
	case 1:
	//string text;
     cout<<"Provide a string to reverse \n";
  // cin>>text;
     cin>>text;
     cout<<stringReversal(text);
   break;
   case 2:
   	cout<<"Give infix Expression  \n";
   	 cin>>text;
   	 cout<<"Postfix of Given Expression \n";
   	 cout<<infixToPostfix(text);
   	 cout<<endl;
   	 break;
   case 3:
   	cout<<"Give infix Expression  \n";
   	 cin>>text;
   	 cout<<"Prefix of Given Expression \n";
   	 cout<<infixToPrefix(text);
   	 cout<<endl;
	 break;
  case 0:
  	exit(-1);
  	
	}
}while(true);
	return 0;
}

string stringReversal(string text)
{
	//Stack<char> s1(text.length());
	linkedStack<char> s1;
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
}// End of String Reversal

 //// Function infix to posfix
string infixToPostfix(string infix)
{
  	linkedStack<char> s1;// point 01
  	string postfix=""; // output 
  	for (int i=0; i<infix.length(); i++)// point 02
  	{
  	  if(isalpha(infix[i]))// 2.1 operend
		 {
		 	postfix+=infix[i]; // 	postfix=postfix+infix[i]
		}// end 2.1	 
	
	  else if(infix[i]=='(')// 2.2 opening 
	  {
	  	s1.push(infix[i]);
		}// end 2.2		
				  
	  else if(infix[i]=='+' || infix[i]=='-'|| infix[i]=='/' || infix[i]=='*') // 2.3 operator
	  {
	  	 if(s1.isEmpty())// 2.3.1 empty 
	  	 {
	  	 	s1.push(infix[i]);
		   }// Emd of 2.3.1
		   
		else // 2.3.2 not empty
		{
			while(!s1.isEmpty() && s1.topValue()!='(' && prec(s1.topValue()) >= prec(infix[i]) )
			{
			  postfix+=s1.pop();	
			  
			}// End of while
			s1.push(infix[i]);
		} // End of  2.3.2
		
		
		}// end 2.3	
		
	else if(infix[i]==')') // 2.4 closing 
	{
		while(s1.topValue()!='(')
		{
		 postfix+=s1.pop();
		 
		}// End 
       s1.pop();
	}	// end 2.4	

}// End of point 02

  if(!s1.isEmpty()) // we can remove if 
  {
  	while(!s1.isEmpty())
		{
		 postfix+=s1.pop();
		 
		}// End 
  }

  return postfix;
}
// End of string infix To Postfix

int prec(char op)
{
	if(op=='^')
	 return 3;
	 
	 else if(op=='*' || op=='/')
	 return 2;
	 
	 else if(op=='+' || op=='-')
	 return 1;
}// end 

///  Infix to prefix 

string infixToPrefix(string infix)
{
	linkedStack<char> s1; // 01
	string prefix=""; // 02
	string r_infix=stringReversal(infix); // 03
	
	for (int i=0; i<r_infix.length(); i++)// point 04
  	{
  	  if(isalpha(r_infix[i]))// 2.1 operend
		 {
		 	prefix+=r_infix[i]; // 	postfix=postfix+infix[i]
		}// end 4.1	 
	
	  else if(r_infix[i]==')')// 2.2 opening 
	  {
	  	s1.push(r_infix[i]);
		}// end 2.2		
				  
	  else if(r_infix[i]=='+' || r_infix[i]=='-'|| r_infix[i]=='/' || r_infix[i]=='*') // 2.3 operator
	  {
	  	 if(s1.isEmpty())// 4 empty 
	  	 {
	  	 	s1.push(r_infix[i]);
		   }// Emd of 4
		   
		else // 4 not empty
		{
			while(!s1.isEmpty() && s1.topValue()!=')' && prec(s1.topValue()) > prec(infix[i]) )
			{
			  prefix+=s1.pop();	
			  
			}// End of while
			s1.push(r_infix[i]);
		} // End of 4
		
		
		}// end 4
		
		
	else if(r_infix[i]=='(') // 2.4 closing 
	{
		while(s1.topValue()!=')')
		{
		 prefix+=s1.pop();
		 
		}// End 
       s1.pop();
	}	// end 4	

}// End of point 04
	
 // 05 // we can remove if 
  
  	while(!s1.isEmpty())
		{
		 prefix+=s1.pop();
		 
		}// End 05
		
string r_prefix=stringReversal(prefix);
return r_prefix;	
}// end of infix to prefix

string postfixEvoluation(string postfix)
{
	
}// End of postfix Evoluation
