// 0927 stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <stack>

template <class T>
class MyStack {
private:
	std::vector<T> _v;
public:
	MyStack() = default;

	// O(1)
	void push(T t) { _v.push_back(t); }

	// O(1)
	void pop() { _v.pop_back(); }

	// O(1)
	T top() const { return _v.back(); }

	// O(1)
	bool isFull() const { return false; }

	// O(1)
	bool isEmpty() const { return _v.empty(); }

	// O(1)
	size_t size() const { return _v.size(); }


};

template <class T >
class MyStackLL {
private:
	std::list<T> _list;
public:
	MyStackLL() = default;

	void push(T t) { _list.push_front(t); }

	void pop() { _list.pop_front(); }

	T top() const { return _list.front(); }

	size_t size() const { return _list.size(); }

	bool isFull() const { return false; }

	bool isEmpty() const { return _list.empty(); }
};

bool parenthesesChecker(const std::string& str) {

	// for each character from str
	// push on open parentheses
	// pop on closing parentheses

	MyStackLL<char> ms;

	for (auto ch : str) {
		if (ch == '(' || ch == '[' || ch == '{')
			ms.push(ch);
		else if (ch == ')' && !ms.isEmpty() && ms.top() == '(')
			ms.pop();
		else if (ch == ']' && !ms.isEmpty() && ms.top() == '[')
			ms.pop();
		else if (ch == '}' && !ms.isEmpty() && ms.top() == '{')
			ms.pop();
		else
			return false;
	}

	return ms.size() == 0;
}

// app 3: evaluate a postfix expression 
int postFix(const std::string& exp) {
	std::stack<int> st;

	for (auto ch : exp) {
		if (isdigit(ch)) {
			st.push(ch - '0');
		}
		else {
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
				st.push(operand_1 / operand_2);
		}
	}

	return st.top();
}


int main()
{
	MyStack<int> ms;

	//for (auto i : { 1, 2, 3, 4, 5 })
	//	ms.push(i); 

	//while (!ms.isEmpty()) {
	//	std::cout << ms.top() << " "; 
	//	ms.pop(); 
	//}

	// app 1 : convert decimal to binary 

	//int num = 644; 

	//while (num) {
	//	ms.push(num % 2); 
	//	num /= 2; 
	//}

	//while (!ms.isEmpty())
	//{
	//	std::cout << ms.top() << " "; 
	//	ms.pop(); 
	//}


	// app 2:  parentheses balance checker

	//MyStackLL<char> msl; 

	for (auto str : { "[](){}", "[((()))]{}", "[", "[(])", "[[]]]" })
		std::cout << parenthesesChecker(str) << std::endl; 

	// app 3: 
	std::cout << postFix("34+5*") << std::endl;
	std::cout << postFix("345++") << std::endl;


	return 0;
}

