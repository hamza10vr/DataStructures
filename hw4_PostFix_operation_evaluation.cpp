/*
      *** Stack Application: postfix expression evaluation ***
	  ***  Hamza Tanveer ****
	  ***   HW 4 ***

 */

#include <iostream>
#include <string>
#include <cctype>
#include <stack>





int postFix(const std::string& exp) 
{
	std::stack<int> st;

	for (auto ch : exp) 
	{	
		// ignoring blank spaces
		if (ch == ' ')			 
		{  
			continue;
		}
		if (isdigit(ch)) 
		{	// if it is a number between  0 - 9 push it onto the stack
			st.push(ch - '0');
		}
		else 
		{    // if not enough in the stack 
			if (st.size() < 2)		
				throw 2;
	
			// from the top of the stack store the operands into variables and remove from stack
			int operand_2 = st.top();
			st.pop();
			int operand_1 = st.top();
			st.pop();

			// performing arithmatic based on the operator
			if (ch == '+')
				st.push(operand_1 + operand_2);
			else if (ch == '-')
				st.push(operand_1 - operand_2);
			else if (ch == '*')
				st.push(operand_1 * operand_2);
			else
			{	
				//divide by zero exception
				if (operand_2 == 0)					
					throw 99;
				st.push(operand_1 / operand_2);
			}
		}
	}
	// throw if stack has 2 or more numbers inside of it
	if (st.size() > 1)    
	{
		throw 1;
	}
	
	return st.top();
}


int main()
{


	std::string input;
		try
		{
			/****** Hard coded expression for testing different test cases ******/
			//std::cout << "3 4 + 5 * : " << postFix("3 4 + 5 *") << std::endl;		// Answer: 35
			//std::cout << "3 4 5 + + : " << postFix("3 4 5 + +") << std::endl;		// Answer: 12
			//std::cout << "3 4 * 5 + : " << postFix("3 4 * 5 +") << std::endl;		// Answer: 17
			//std::cout << "3 4 5 * + : " << postFix("3 4 5 * +") << std::endl;		// Answer: 23
			//std::cout << "3 4 - 5 + : " << postFix("3 4 - 5 +") << std::endl;		// Answer: 4
			//std::cout << "3 4 5 - + : " << postFix("3 4 5 - +") << std::endl;		// Answer: 2
			//std::cout << postFix("4 4 3 - 5 *") << std::endl;						// Answer: stack will have 2 or more numbers
			//std::cout << postFix("4 5 5 - /") << std::endl;						// Answer: divide-by-Zero error
			//std::cout << postFix("4 - 5 *") << std::endl;							// Answer: stack underflow


			std::cout << "please input a post fix expression for evaluation: ";
			std::getline(std::cin, input);
			int result = postFix(input);
			std::cout << "(valid expr) " << input << std::endl;
			std::cout << "Final answer: " << result << std::endl;

		}
		catch (int e)
		{
			// printing error when exception caught with specefic message
			if (e == 99)
			{
				std::cout << "(Invalid expr) " << input << " is invalid due to divide-by-zero error." << std::endl;
			}
			else if (e == 2)
			{
				std::cout << "(Invalid expr) " << input << " is invalid not enough operands. stack underflow." << std::endl;
			}
			else
			{
				std::cout << "(Invalid expr) " << input << " is invalid since the stack will have 2 numbers inside it." << std::endl;
			}
		}

	return 0;
}