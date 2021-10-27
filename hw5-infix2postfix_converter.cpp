// Hamza Tanveer
// HW 5
// infix to postfix converter
// 10/26/2021

#include<stack>
#include<string>
#include<iostream>



int precdence(char c)        // function for setting up / returning the precedence
{
    if (c == '^')
        return 3;       // higher number = higher precedence
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;      // lowest precedence since it is 1
    else
        return -1;
}

std::string I2PConvertor(std::string s)         // function to convert infix to posfix
{
    std::string result;
    std::stack<char> ms;
    char character;
    

    for (int i = 0; i < s.length(); i++) 
    {
        character = s[i];   // storing the input in Character
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9'))
        {   // if the character is an operand, then add it to the character
            result += character;
        }
        else if (character == '(')
        {   // if it is an open pranthese, push it to the stack
            ms.push('(');
        }
        else if (character == ')')      // if closed pranthesis then while top is not open paranthesis
        {
            while (ms.top() != '(')
            {
                result += ms.top();     // ... concat the result  to what is at the top of stack
                ms.pop();               // .. then remvoe the from the top of the stack
            }
            ms.pop();
        }
        else 
        {   // while ms (my stack) is not empty and the precendence order is less than what is at the top of stack
            while (!ms.empty() && precdence(s[i]) <= precdence(ms.top()))
            {
                result += ms.top();     // contcatenate the result with what is at the top of stack when precedence level is < top
                ms.pop();               // after concatenation remove from the the stack
            }
            ms.push(character);         // else just push it to the stack
        }
    }
    while (!ms.empty())         // continue to concatenate the remaining to the string 
    {
        result += ms.top();
        ms.pop();               // removing rom the top of stack after the concatnation of string is done.
    }

    return result;
}


int main() {
    std::string infix1 = "a*b+c";
    std::string infix2 = "a-b*c";
    std::string infix3 = "(a+b)/c";
    std::string infix4 = "(a+b)*(c-d)";


    // expected: ab*c+
    std::cout << I2PConvertor(infix1) << std::endl;

    // expected: abc*-
    std::cout << I2PConvertor(infix2) << std::endl;

    // expected: ab+c/
    std::cout << I2PConvertor(infix3) << std::endl;

    // expected: ab+cd-*
    std::cout << I2PConvertor(infix4) << std::endl;


    return 0;
}