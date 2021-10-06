// Quiz 2
// Hamza Tanveer
// Oct 5, 2021


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




void addHead(NodePtr& head, int num)
{
	NodePtr newNode = new Node(num);

	NodePtr oldhead = head;
	head = newNode;

	head->next = oldhead;
}

//search a number in the linked list
// O (n)



//a search function that searches a given target. Return a node address if found, and return nullptr otherwise
NodePtr search(const NodePtr& head, NodePtr& target)
{
	std::cout << "\nSearching for number: " << target << "......... ";
	NodePtr temp = head;		 // step 1: create a new node
	while (temp != nullptr)		// step 2: search for target as long as pointer is not nullptr
	{
		if (temp == target) // 10, 20, 30, 40  // 0001, 29, 12,02  //29
		{
			std::cout << "number " << target << " found !!! & node address: " << temp << "\n";
			return temp;
		}
		temp = temp->next;
	}

	temp = nullptr; // if target not found, returns null pointer
	std::cout << "Sorry, number not found & nodes address: " << temp << "\n";

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
	std::cout << "entering quiz 2 fucntion\n";


	auto found_target =  search(head1, target);
	
	if (!found_target) 
	{
		std::cout << "target not found. ";
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
		std::cout << "\n entering else block\n";
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

	for (auto i : { 50, 40,30,20,10 })
		add_at_head(head1, i);
	//findTail(head1)->next = nullptr;
	for (auto i : { 13,12,11 })
		add_at_head(head2, i);
	//findTail(head2)->next = nullptr;


}

void testNotFound() {
	std::cout << "Testing Not found: " << std::endl;
	NodePtr head1{ nullptr };
	NodePtr head2{ nullptr };
	createTestData(head1, head2);

	quiz2(head1, head2, head2);	// test case when when address not found // this is case because h2 is not part of h1 
	traverse(head1);
	delList(head1);

}

void testSomeIndex( int test_index) {

	std::cout << "Testing using index: " << test_index << std::endl;
	NodePtr head1{ nullptr };
	NodePtr head2{ nullptr };
	createTestData(head1, head2);
	NodePtr test_case = head1;

	while (test_case && test_index > 0) {
		test_case = test_case->next;
		test_index--;
	}

	quiz2(head1, test_case, head2);	// test case when when address not found // this is case because h2 is not part of h1 


	traverse(head1);
	delList(head1);
}

int main()
{

	using std::cout;
	using std::endl;

	NodePtr head1{ nullptr };
	NodePtr head2{ nullptr };


	testNotFound(); // 
	for (int i = 0; i < 5; i++) {
		testSomeIndex(i);
	}
	

	return 0;

}