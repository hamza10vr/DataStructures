#include <iostream>



// node class implementation
class DLNode
{
public:
    int data;
    DLNode* next;
    DLNode* previous;
    DLNode() = delete;
    DLNode(int num) : data{ num }, next{ nullptr }, previous{ nullptr } {}
};

typedef DLNode* DLNodePtr;   //typedef on DLnode* for ease of readibility

// Dlist class implementation
class DList
{
public:
    DList();                     //default constructor initialized head & tail = nullptr 
    void traverse();             // function that goes from head to tail 
    void reverse_transverse();   // function that goes from tail to head.
    void add_at_head(int num);   // adds an integer at the head of linked list
    void add_at_tail(int num);   // adds an integer at the tail
    DLNodePtr search(int target);   // searches a given target. Return a node address if found, and return nullptr otherwise.
    void remove(const DLNodePtr& curNode);   //searches and deletes (the first occurrence of) a given target



private:
    DLNode* head;
    DLNode* tail;
};




int main()
{

    //create a DList object named dlist
    DList dlist;

    // following code snippet to add numbers to dlist
    for (auto i : { 5, 4, 3, 2, 1 })
        dlist.add_at_head(i);

    std::cout << "\n\nAdded 5 integers at HEAD of linked list";
    dlist.traverse();


    // following code snippet to add numbers to dlist 
    for (auto i : { 11, 12, 13, 14, 15 })
        dlist.add_at_tail(i);

    std::cout << "\nAdded 5 integers at TAIL of linked list";
    dlist.traverse();
    std::cout << std::endl;

    // following code snippet to test search function
    auto pTemp = dlist.search(11);
    dlist.search(21);

    //call dlist's delete function to delete pTemp from the list. 
    dlist.remove(pTemp);

    std::cout << "\n~~Deleted #" << pTemp->data << " from the list and here is the new list";

    dlist.traverse();

    dlist.reverse_transverse();   // testing reverse transvers function



    return 0;
}

//Default constructor. Empty list initialized. head & Tail equal null pointers
DList::DList()
{
    head = nullptr;
    tail = nullptr;
    std::cout << "\ndefault constructor invoked. Empty list initialized.... ";
}

// function to go through the list in forward direction [head] -> [Tail]
void DList::traverse()
{
    std::cout << "\nTransversing Dlist [ ";
    DLNodePtr curNode = this->head; // Start at head

    while (curNode != nullptr) // keep moving through nodes until nullptr is reached. end of list
    {
        std::cout << curNode->data << " ";
        curNode = curNode->next;
    }
    std::cout << "]\n";
};


// function to go through the list in forward direction [head] -> [Tail]
void DList::reverse_transverse()
{
    std::cout << "Reverse transverse [ ";
    DLNodePtr curNode = this->tail; // Start at tail

    while (curNode != nullptr)   // keep moving through nodes until nullptr is reached. beginnig of list
    {
        std::cout << curNode->data << " ";
        curNode = curNode->previous;  // decrease the currNode pointer with every iteration until head is reached
    }
    std::cout << "]  REVERSE TRANSVERSE\n";
}


void DList::add_at_head(int num)
{

    DLNodePtr newNode = new DLNode(num);   // step 1: create a new node

    if (head == nullptr)   // step 2 : if not nodes in the list, assign new node to the head & Tail
    {
        head = newNode;
        tail = newNode;
    }
    else   //Step 3: if nodes in the list, 
    {
        newNode->next = this->head;   //newNode's points to current head
        head->previous = newNode;     //  current node's previous points to new node
        this->head = newNode;         // current head points to new node
    }
}


void DList::add_at_tail(int num)
{
    DLNodePtr newNode = new DLNode(num);   // step 1: create a new node

    if (head == nullptr)   // step 2 : if not nodes in the list, assign new node to the head & Tail
    {
        head = newNode;
        tail = newNode;
    }
    else         //Step 3: if nodes in the list, 
    {
        this->tail->next = newNode;
        newNode->previous = this->tail;
        this->tail = newNode;
    }
}



DLNodePtr DList::search(int target)
{
    std::cout << "Searching for number: " << target << "......... ";
    DLNodePtr temp = head;   // step 1: create a new node
    while (temp != nullptr)  // step 2: search for target as long as pointer is not nullptr
    {
        if (temp->data == target)
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

void DList::remove(const DLNodePtr& curNode)
{
    // if list empty, nothig needs to be removed
    if (curNode == nullptr)
        return;

    // creating 2 new pointers to her successinve and previous nodes
    DLNodePtr sucNode = curNode->next;
    DLNodePtr preNode = curNode->previous;

    if (sucNode != nullptr)   // successive node points to previous node
    {
        sucNode->previous = preNode;
    }

    if (preNode != nullptr)   // previous node points to successive node
    {
        preNode->next = sucNode;
    }

    if (curNode == this->head)  //Removed head
    {
        this->head = sucNode;
    }

    if (curNode == this->tail)  //Removed tail
    {
        this->tail = preNode;
    }

    return;
};










//#include <iostream>
//
//class DLNode {
//    // TODO: implement the node class 
//    int data;
//    DLNode* next;
//    DLNode* previous;
//    DLNode() = delete;
//    DLNode(int num) : data{ num }, next{ nullptr }, previous{ nullptr } {}
//};
//
//typedef Node* NodePtr;
//
//class DList {
//
//    // TODO: implement the list class 
//private:
//    Node* head;
//    Node* tail
//
//public:
//    DList() : this->head{nullptr}, this->tail{nullptr} {}
//
//
//};
//
//int main() {
//    // TODO: create a DList object named dlist
//
//    // TODO: uncomment following code snippet to add numbers to dlist
//  //   for (auto i : {5, 4, 3, 2, 1})
//  //     dlist.add_at_head(i);
//
//    // TODO: uncomment following code snippet to add numbers to dlist 
//  //   for (auto i: {11, 12, 13, 14, 15})
//  //     dlist.add_at_tail(i); 
//
//    // TODO: uncomment following code snippet to test search function
//  //   auto pTemp = dlist.search(11); 
//
//    // TODO: call dlist's delete function to delete pTemp from the list. 
//
//
//
//
//    return 0;
//}