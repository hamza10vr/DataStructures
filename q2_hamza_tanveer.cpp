// Quiz 2
// Hamza Tanveer
// Oct 5, 2021


//Singly linked list

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
	std::cout << std::endl;
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

//a search function that searches a given target. Return a node address if found, and return nullptr otherwise
NodePtr search(const NodePtr& head, NodePtr& target)
{
	// step 1: create a new node
	// step 2: search for target as long as pointer is not nullptr
	NodePtr temp = head;		 
	while (temp != nullptr)		
	{
		if (temp == target) 
		{
			
			return temp;
		}
		temp = temp->next;
	}

	// if target not found, returns null pointer
	temp = nullptr; 


	return temp;
}

NodePtr findTail(NodePtr& head) {
	NodePtr cur = head;
	while (cur) 
	{
		if (!(cur->next))
			break;
		cur = cur -> next;
	}
	return cur;
}






void quiz2(NodePtr& head1, NodePtr& target, NodePtr& head2)
{
	


	auto found_target =  search(head1, target);
	
	if (!found_target) 
	{
		std::cout << "Target not found : ";
		
		NodePtr tail = findTail(head1);

		if (!tail)	// if list 1 is empty 
		{
			head1 = head2;	// list 1 = list 2
			head2 = nullptr;
			return;
		}

		
		tail->next = head2;		// connecting list 1 tail to list 2
		head2 = nullptr;		

		
	}
	else 
	{
		std::cout << "\nTarget Found : ";
		NodePtr cur_remove = target->next;
		
		while (cur_remove != nullptr)
		{
			NodePtr succ = cur_remove->next;
			delete cur_remove;
			cur_remove = succ;
		
		}
		target->next = head2;	
		head2 = nullptr;
	}


}


void delList(NodePtr& head) {

	NodePtr cur = head;
	NodePtr nxt;
	while (cur) {
		nxt = cur->next;
		delete cur;
		cur = nxt;
	}
	head = NULL;

}
void createTestData(NodePtr& head1, NodePtr& head2) {

	for (auto i : {  40,30,20,10 })
		add_at_head(head1, i);
	for (auto i : { 13,12,11 })
		add_at_head(head2, i);


}
int main()
{

	NodePtr head1{ nullptr };
	NodePtr head2{ nullptr };

	createTestData(head1, head2);
	quiz2(head1, head1->next, head2);
	traverse(head1);
	delList(head1);


	createTestData(head1, head2);
	quiz2(head1, head2, head2);
	traverse(head1);
	delList(head1);


	return 0;

}