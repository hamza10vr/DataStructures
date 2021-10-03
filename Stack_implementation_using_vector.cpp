#include <iostream>
#include <vector>


template <class T>
class MyStack
{
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

	bool isFull() const { return false; }		// never full

	// O(1)

	bool isEmpty() const { return _v.empty(); }

	// O(1)

	size_t  size() const { return _v.size(); }

};

int main()
{
	MyStack <int> ms;

	for (auto i : { 1,2,3,4,5,6 })
		ms.push(i);

	while (!ms.isEmpty()) 
	{
		std::cout << ms.top() << " ";
		ms.pop();

	}


}