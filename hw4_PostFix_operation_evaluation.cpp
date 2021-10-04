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
		if (ch == ' ')			 // skipping space character
		{  
			continue;
		}
		if (isdigit(ch)) 
		{
			st.push(ch - '0');
		}
		else 
		{     
			if (st.size() < 2)		// stack underflow error
				throw 2;
	
	
			int operand_2 = st.top();
			st.pop();
			int operand_1 = st.top();
			st.pop();
			if (ch == '+')
				st.push(operand_1 + operand_2);
			else if (ch == '-')
				st.push(operand_1 - operand_2);
			else if (ch == '*')
				st.push(operand_1 * operand_2);
			else
			{
				if (operand_2 == 0)					//divide by zero exception
					throw 0;
				st.push(operand_1 / operand_2);
			}
		}
	}

	if (st.size() > 1)    // more than 1 element in stack at last
	{
		throw 1;
	}

	return st.top();
}


int main()
{

	//std::string arr[] = { "4 3 - 5 *", "4 4 3 - 5 *", "4 5 5 - /" };
	//for (int i = 0; i < 3; i++) {
	std::string input;
		try {									
			
			std::cout << "please input: ";
			std::getline(std::cin, input);
			int result = postFix(input);
			std::cout << "(valid expr) " << input << std::endl;
			std::cout << "Final answer: " << result << std::endl;
		}
		catch (int e) {
			/* printing error on the basis of error codes
			 error code zero means divide by zero error
			 error code one means invalid expression error*/
			if (e == 0) 
			{
				std::cout << "(Invalid expr) " << input << " is invalid due to divide-by-zero error." << std::endl;
			}
			else
				std::cout << "(Invalid expr) " << input << " is invalid since the stack will have 2 numbers inside it." << std::endl;

		}
	//}
	



	//std::cout << postFix("3 4 + 5 *") << std::endl;		// 35
	//std::cout << postFix("345++") << std::endl;		// 12
	//std::cout << postFix("34*5+") << std::endl;		// 17
	//std::cout << postFix("345*+") << std::endl;		// 23
	//std::cout << postFix("34-5+") << std::endl;		// 4
	//std::cout << postFix("345-+") << std::endl;		// 2

	return 0;
}