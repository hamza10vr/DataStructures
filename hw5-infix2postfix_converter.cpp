// #include<bits/stdc++.h>
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
    

    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            ms.push('(');
        else if (c == ')') 
        {
            while (ms.top() != '(')
            {
                result += ms.top();
                ms.pop();
            }
            ms.pop();
        }
        else 
        {
            while (!ms.empty() && precdence(s[i]) <= precdence(ms.top()))
            {
                result += ms.top();
                ms.pop();
            }
            ms.push(c);
        }
    }
    while (!ms.empty())
    {
        result += ms.top();
        ms.pop();
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

    //cout << "Postfix of " << infix1 << ": " << I2PConvertor(infix1) << endl;
    //cout << "Postfix of " << infix2 << ": " << I2PConvertor(infix2) << endl;
    //cout << "Postfix of " << infix3 << ": " << I2PConvertor(infix3) << endl;
    //cout << "Postfix of " << infix4 << ": " << I2PConvertor(infix4) << endl;
    return 0;
}