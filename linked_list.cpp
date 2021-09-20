// Linked list



#include <iostream>




struct Node
{
	int num;
	Node* next;
	Node() = delete;
	Node(int num) : num{ num }, next{ nullptr } {}


};


typedef Node* NodePtr;

//traverse linked list
//O(n)
void traverse(const NodePtr& node)
{
	NodePtr temp = node;
	while (temp != nullptr)
	{
		std::cout << temp->num << " ";

		temp = temp->next;

	}
}

//


// add a node at the head of the linked list
//O(1)
void add_at_head(NodePtr& head, int num) 
{
	// step 1: create a new node
	NodePtr temp = new Node(num); 

	// step 2 : assign new node to the head
	NodePtr oldHead = head;
	head = temp;

	// step 3 : assign old head to new node's next field
	head->next = oldHead;
}


//add a node at the tail of linked list
//O(n)

void add_at_tail(NodePtr& head, int num)
{
	//step 0: when the list is empty, call add at head
	if (!head)
	{
		add_at_head(head, num);
	}


	// step 1: createa a new node
	NodePtr newNode = new Node(num);

	//step 2 : find the tail node
	NodePtr temp = head;
	while (temp && temp->next)
	{
		temp = temp->next;
	}

	//step 3 : link newNode to the list
	temp->next = newNode;
}

void addHead(NodePtr& head, int num)
{
	NodePtr newNode = new Node(num);

	NodePtr oldhead = head;
	head = newNode;

	head->next = oldhead;
}

//search a number in the linked list
// O (n)

bool llsearch(const NodePtr head, int target)
{
	NodePtr temp = head;
	while (temp != nullptr)  /// same as while (temp)
	{
		if (temp->num == target)
			return true;

		temp = temp->next;
	}

	return false;
}

//delete target number
// O(n)
void del(NodePtr& head, int target)
{
	// case 1 : the linked list is empty
	if (!head)
		return;

	// Case 2: head node is teh one to be deleted
	if (head && head->num == target)
	{
		NodePtr temp = head;
		head = head->next;			// works even head->next is nullptr
		delete temp;
		temp = nullptr;
		return;

	}

	// other cases
	NodePtr prev = nullptr;
	NodePtr temp = head;

	while (temp && temp->num != target)
	{
		prev = temp;
		temp = temp->next;
	}

	//case 3: tem is empty , searched linked list but no math
	if (!temp)
		return;

	// case 4 : temp isnot empty and temp-> is target
	prev-> next = temp->next;
	delete temp;
	temp = nullptr;



}


int main()
{
	
	using std::cout;
	using std::endl;

	NodePtr head{ nullptr };

	//head = new Node{ 10 };

	//// how can i refer to the next
	//// assign the newly created node's addreess to the next fille dinside the head/first node
	//head->next = new Node{ 20 };
	////(*head).next = new Node{ 20 };

	//head->next->next = new Node{ 30 };

	//head->next->next->next = new Node{ 40 };

	//head->next->next->next->next = new Node{ 750 };

	del(head, 23);

	for (auto i : { 50,30,20,10 })
		add_at_head(head, i);

	for (auto i : { 101, 202, 303, 404 })
		add_at_tail(head, i);

	traverse(head);

	cout << endl << std::boolalpha << llsearch(head, 202) << endl;
	cout << std::boolalpha << llsearch(head, 22) << endl;

	std::cout << std::endl;
	del (head, 10);
	traverse(head);

	std::cout << std::endl;
	del(head, 5050);
	traverse(head);

	std::cout << std::endl;
	del(head, 101);
	traverse(head);

	std::cout << std::endl;
	del(head, 404);
	traverse(head);

	return 0;


}