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

	// case 4 : temp is not empty and temp-> is target
	prev->next = temp->next;
	delete temp;
	temp = nullptr;



}


void quiz2(NodePtr& head1, NodePtr& target, NodePtr& head2)
{
	std::cout << "entering quiz 2 fucntion\n";


	auto found_target =  search(head1, target);
	
	if (!found_target) 
	{
		std::cout << "target not found. ";
		NodePtr tail = findTail(head1);

		if (!tail) 
		{
			head1 = head2;
			head2 = nullptr;
			return;
		}

		NodePtr cur = head2;
		tail->next = head2;
		//delete head2;
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


int main()
{

	using std::cout;
	using std::endl;

	//NodePtr head{ NULL };
	NodePtr head1 {nullptr};
	NodePtr head2{ nullptr };

	for (auto i : { 40,30,20,10 })
		add_at_head(head1, i);

	for (auto i : { 13,12,11 })
		add_at_head(head2, i);

	traverse(head1);
	traverse(head2);

	NodePtr taill = findTail(head1);
	quiz2(head1, head2, head2);

	traverse(head1);


	
	
	//auto target_not_found = search(head1, 50);
	//quiz2(head1, target_not_found, head2);

	std::cout << "\nprinting head1 : ";
	traverse(head1);

	std::cout << "\nprinting head 2 which shouldn't exist : ";
	traverse(head2);



	std::cout << "\n testing if target found ******* \n : ";

	NodePtr head3{ nullptr };
	NodePtr head4{ nullptr };

	for (auto i : { 70,60,50,40,30,20,10 })
		add_at_head(head3, i);

	for (auto i : { 13,12,11 })
		add_at_head(head4, i);

	traverse(head3);
	traverse(head4);



	//auto target_address = search(head3, 20);
	//quiz2(head3, target_address, head4);

	std::cout << "\nprinting head3 : ";
	traverse(head3);

	std::cout << "\nprinting head 4 which shouldn't exist : ";
	traverse(head4);






	//find the target
	// assign temp pointer to target
	// delete nodes in list 1 until null ptr
			// temp 1 hold next point and temp 2 holds current pointer 
	// merge linked list 2 to 1






	
	

	//head = new Node{ 10 };

	//// how can i refer to the next
	//// assign the newly created node's addreess to the next fille dinside the head/first node
	//head->next = new Node{ 20 };
	////(*head).next = new Node{ 20 };

	//head->next->next = new Node{ 30 };

	//head->next->next->next = new Node{ 40 };

	//head->next->next->next->next = new Node{ 750 };

	//del(head, 23);

	//for (auto i : { 50,30,20,10 })
	//	add_at_head(head, i);

	//for (auto i : { 101, 202, 303, 404 })
	//	add_at_tail(head, i);

	//traverse(head);

	//cout << endl << std::boolalpha << llsearch(head, 202) << endl;
	//cout << std::boolalpha << llsearch(head, 22) << endl;

	//std::cout << std::endl;
	//del(head, 10);
	//traverse(head);

	//std::cout << std::endl;
	//del(head, 5050);
	//traverse(head);

	//std::cout << std::endl;
	//del(head, 101);
	//traverse(head);

	//std::cout << std::endl;
	//del(head, 404);
	//traverse(head);

	return 0;


}