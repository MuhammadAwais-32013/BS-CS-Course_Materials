#include <iostream>
#include <string.h>
#include <cctype>
#include "Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Declaraed a function string reversal that will take a string as a parameter which return reverse string*/
string stringReversal(string text);
/* Decalare a function infix to posfix that take an infix as a paramerter and return postfix
equelent */
string infixToPostfix(string infix);      // take infix return posfix
int prec(char op);                        // For precedence
string infixToPrefix(string infix);       // infix to prefix
double postfixEvoluation(string postfix); // postfix Evoluation
void bracketBalancing(string Expression); // barcket Balancing
string postfixToInfix(string postfix);    // Postfix to Infix
string prefixToInfix(string prefix);      // Prefix to infix
string prefixToPostfix(string prefix);     // Prefix to Postfix
string postfixToPrefix(string postfix);   // Prefix to Postfix
using namespace std;
int main(int argc, char **argv)
{
    Stack<char> s1;
    int op;
    // string infix;
    // cin>>op;
    string text;
    do
    {
        cout << "Press 1 to  Reversal Expression \n";
        cout << "Press 2 to convert infix to postfix  \n";
        cout << "Press 3 to convert infix to prefix  \n";
        cout << "Press 4 to Evaluation of postfix \n";
        cout << "Press 5 for Symbol Balancing \n";
        cout << "Press 6 to convert Postfix to Infix  \n";
        cout << "Press 7 to convert Prefix to Infix  \n";
        cout << "Press 8 to convert Prefix to Postfix  \n";
        cout << "Press 9 to convert Postfix to Prefix  \n";
        cout << "Press 0 to exist \n";
        cin >> op;
        cin.ignore(); //(2,'\n) add this statement to consume the newline character
        switch (op)
        {
        case 1:
            // string text;
            cout << "Provide a string to reverse \n";
            // cin>>text;
            getline(cin, text);
            cout << stringReversal(text) << "\n";
            break;
        case 2:
            cout << "Give infix Expression  \n";
            cin >> text;
            cout << "Postfix of Given Expression \n";
            cout << infixToPostfix(text);
            cout << endl;
            break;
        case 3:
            cout << "Give infix Expression  \n";
            cin >> text;
            cout << "Prefix of Given Expression \n";
            cout << infixToPrefix(text);
            cout << endl;
            break;
        case 4:
            cout << "Give Postfix Expression  \n";
            cin >> text;
            cout << "Evaluation of Given Postfix \n";
            cout << postfixEvoluation(text);
            cout << endl;
            break;
        case 5:
            cout << "Give an of Brackets Expression  \n";
            cin >> text;
            cout << "Bracket  balancing ...........\n";
            bracketBalancing(text);
            cout << endl;
            break;
        case 6:
            cout << "Give an of Postfix Expression  \n";
            cin >> text;
            cout << "Postfix to infix  conversion ...........\n";
            cout << postfixToInfix(text);
            cout << endl;
            break;
        case 7:
            cout << "Give an of Prefix Expression  \n";
            cin >> text;
            cout << "Prefix to infix  conversion ...........\n";
            cout << prefixToInfix(text);
            cout << endl;
            break;
        case 8:
            cout << "Give an of Prefix Expression  \n";
            cin >> text;
            cout << "Prefix to Postfix  conversion ...........\n";
            cout << prefixToPostfix(text);
            cout << endl;
            break;
        case 9:
            cout << "Give an of Postfix Expression  \n";
            cin >> text;
            cout << "Postfix to Prefix  conversion ...........\n";
            cout << postfixToPrefix(text);
            cout << endl;
            break;
        case 0:
            exit(-1);
        }
    } while (true);
    return 0;
}

//*****************************Functions Implementations******************************

string stringReversal(string text)
{
    Stack<char> s1;
    string r_exp = "";

    for (int i = 0; i < text.length(); i++)
    {
        s1.push(text[i]);
    }

    while (!s1.isEmpty())
    {
        r_exp += s1.pop();
    }

    return r_exp;
} // End of String Reversal

int prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
}

string infixToPostfix(string infix)
{
    Stack<char> s2;      // 1. Create a stack to store operators
    string postfix = ""; // 1. Create an empty string to store the postfix expression

    for (int i = 0; i < infix.length(); i++) // 2. Loop through each character in the infix expression
    {
        if (isalpha(infix[i])) // 2.1. If the character is a letter (operand)
        {
            postfix += infix[i]; // 2.1.1. Add it to the postfix expression
        }

        else if (infix[i] == '(') // 2.2. If the character is an opening parenthesis
        {
            s2.push(infix[i]); // 2.2.1. Push it onto the stack
        }

        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') // 2.3. If the character is an operator
        {
            if (s2.isEmpty()) // 2.3.1. If the stack is empty
            {
                s2.push(infix[i]); // 2.3.1.1. Push the operator onto the stack
            }

            else // 2.3.2. If the stack is not empty
            {
                while (!s2.isEmpty() && s2.topValue() != '(' && prec(s2.topValue()) >= prec(infix[i])) // 2.3.2.1. Pop operators from the stack while the top operator has higher or equal precedence and is not an opening parenthesis
                {
                    postfix += s2.pop(); // 2.3.2.1.1. Add each popped operator to the postfix expression
                }

                s2.push(infix[i]); // 2.3.2.2. Push the current operator onto the stack
            }
        }
        else if (infix[i] == ')') // 2.4. If the character is a closing parenthesis
        {
            while (s2.topValue() != '(') // 2.4.1. Pop operators from the stack until the top operator is an opening parenthesis
            {
                postfix += s2.pop(); // 2.4.1.1. Add each popped operator to the postfix expression
            }
            s2.pop(); // 2.4.2. Pop the opening parenthesis from the stack
        }
    }

    if (!s2.isEmpty()) // 3. Pop any remaining operators from the stack and add them to the postfix expression
    {
        while (!s2.isEmpty())
        {
            postfix += s2.pop();
        }
    }

    return postfix; // 4. Return the postfix expression
}

string infixToPrefix(string infix)
{
    Stack<char> s2;                            // Step 1: Create a stack to store operators
    string prefix = "";                        // Step 2: Initialize an empty string to store the prefix expression
    string r_infix = stringReversal(infix);    // Step 3: Reverse the infix expression
    for (int i = 0; i < r_infix.length(); i++) // Step 4: Traverse the reversed infix expression
    {
        if (isalpha(r_infix[i])) // Step 4.1: If the current character is an operand, add it to the prefix expression
        {
            prefix += r_infix[i];
        }

        else if (r_infix[i] == ')') // Step 4.2: If the current character is a closing bracket, push it onto the stack
        {
            s2.push(r_infix[i]);
        }

        else if (r_infix[i] == '+' || r_infix[i] == '-' || r_infix[i] == '*' || r_infix[i] == '/') // Step 4.3: If the current character is an operator
        {
            if (s2.isEmpty()) // Step 4.3.1: If the stack is empty, push the operator onto the stack
            {
                s2.push(r_infix[i]);
            }

            else // Step 4.3.2: If the stack is not empty
            {
                while (!s2.isEmpty() && s2.topValue() != ')' && prec(s2.topValue()) > prec(r_infix[i])) // Compare the precedence of the current operator with the operator on the top of the stack
                {
                    prefix += s2.pop(); // Pop operators from the stack and add them to the prefix expression until the current operator has higher or equal precedence
                }

                s2.push(r_infix[i]); // Push the current operator onto the stack
            }
        }
        else if (r_infix[i] == '(') // Step 4.4: If the current character is an opening bracket
        {
            while (s2.topValue() != ')') // Pop operators from the stack and add them to the prefix expression until a closing bracket is encountered
            {
                prefix += s2.pop();
            }
            s2.pop(); // Pop the closing bracket from the stack
        }
    }

    if (!s2.isEmpty()) // Step 5: Pop any remaining operators from the stack and add them to the prefix expression
    {
        while (!s2.isEmpty())
        {
            prefix += s2.pop();
        }
    }

    string r_prefix = stringReversal(prefix); // Step 6: Reverse the prefix expression to get the final result
    return r_prefix;
} // End of infixToPrefix function

double postfixEvoluation(string postfix)
{
    Stack<double> s1;                                  // 1. Create a stack to store operands
    string::iterator i;                                // Iterator to traverse the postfix string
    for (i = postfix.begin(); i != postfix.end(); i++) // 2. Iterate through each character in the postfix string
    {
        if (isdigit(*i)) // 2.1. If the character is a digit
        {
            double Postfix = static_cast<double>(*i - '0'); // Convert the digit character to a double and push it to the stack
            s1.push(Postfix);
        }
        else // 2.2. If the character is an operator
        {
            double num1 = s1.pop(); // Pop the top operand from the stack
            double num2 = s1.pop(); // Pop the second top operand from the stack

            switch (*i) // Perform the corresponding operation based on the operator
            {
            case '+':
                s1.push(num2 + num1); // Add the two operands and push the result to the stack
                break;
            case '-':
                s1.push(num2 - num1); // Subtract the top operand from the second top operand and push the result to the stack
                break;
            case '/':
                s1.push(num2 / num1); // Divide the second top operand by the top operand and push the result to the stack
                break;
            case '*':
                s1.push(num2 * num1); // Multiply the two operands and push the result to the stack
                break;
            default:
                break;
            }
        }
    }

    if (s1.isEmpty()) // Check if the stack is empty
    {
        cerr << " Invalid Expression \n"; // If the stack is empty, it means the expression was invalid
    }

    return s1.pop(); // Return the final result by popping the top element from the stack
} // End of  postfixEvoluation

bool arePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else if (opening == '<' && closing == '>')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    return false;
}

void bracketBalancing(string Expression)
{
    Stack<char> s1;
    // Step 1: Iterate over the expression
    for (int i = 0; i < Expression.length(); i++)
    {
        // Step 2.1: If the current character is an opening symbol, push it to the stack
        if (Expression[i] == '(' || Expression[i] == '[' || Expression[i] == '{' || Expression[i] == '<')
        {
            s1.push(Expression[i]);
        }
        // Step 2.2: If the current character is a closing symbol
        else if (Expression[i] == ')' || Expression[i] == ']' || Expression[i] == '}' || Expression[i] == '>')
        {
            // Step 2.2.1: If the stack is empty, report missing opening symbol
            if (s1.isEmpty())
            {
                cerr << "Opening Symbol is Missing \n";
            }
            // Step 2.2.2: If the stack is not empty and the current symbol matches the top of the stack, pop the stack
            else if (!s1.isEmpty() && arePair(s1.topValue(), Expression[i]))
            {
                s1.pop();
            }
            // Step 2.2.3: If the current symbol doesn't match the top of the stack, report symbol mismatch
            else
            {
                cerr << "Symbol mismatched \n";
            }
        }
    }

    // Step 3: Check if there are any remaining symbols in the stack
    if (!s1.isEmpty())
    {
        cerr << "Invalid Expression \n";
        return;
    }

    cout << "Symbol is Balanced \n";
} // End of Symbol Balancing

string postfixToInfix(string postfix)
{
    Stack<string> s1;  // Step 1: Create a stack to store operands
    string infix = ""; // Initialize the infix string

    for (size_t i = 0; i < postfix.length(); i++) // Step 2: Iterate over the postfix expression
    {
        if (isalpha(postfix[i])) // Step 2.1: If the current character is an alphabet (operand)
        {
            s1.push(string(1, postfix[i])); // Push the operand to the stack
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') // Step 2.2: If the current character is an operator
        {
            string op1 = s1.pop();                              // Pop the top operand from the stack
            string op2 = s1.pop();                              // Pop the second top operand from the stack
            string result = "(" + op2 + postfix[i] + op1 + ")"; // Create a string with the operands and the operator
            s1.push(result);                                    // Push the result back to the stack
        }
    }

    infix = s1.pop(); // Step 3: The final infix expression is the remaining element in the stack
    return infix;
} // End of Postfix to Infix

string prefixToInfix(string prefix)
{

    Stack<string> s1;                         // Step 1: Create a stack to store operands
    string r_prefix = stringReversal(prefix); // Step 2: Reverse the prefix Expression
    string infix = "";                        //  Initialize the infix string

    for (size_t i = 0; i < r_prefix.length(); i++) // Step 3: Iterate over the postfix expression
    {
        if (isalpha(r_prefix[i])) // Step 3.1: If the current character is an alphabet (operand)
        {
            s1.push(string(1, r_prefix[i])); // Push the operand to the stack
        }
        else // Step 3.2: If the current character is an operator
        {
            string op1 = s1.pop();                               // Pop the top operand from the stack
            string op2 = s1.pop();                               // Pop the second top operand from the stack
            string result = ")" + op2 + r_prefix[i] + op1 + "("; // Create a string with the operands and the operator
            s1.push(result);                                     // Push the result back to the stack
        }
    }

    infix = s1.pop();                       // The final infix expression is the remaining element in the stack
    string r_infix = stringReversal(infix); // step 4: Reverse the final infix expression and return
    return r_infix;
} // End of Prefix to Infix

string prefixToPostfix(string prefix)
{
  string infix = prefixToInfix(prefix);
  string postfix=infixToPostfix(infix);
  return postfix;
}// End of Prefix to Postfix

string postfixToPrefix(string postfix)
{
  string infix = postfixToInfix(postfix);
  string prefix=infixToPrefix(infix);
  return prefix;
}// End of Postfix to Prefix