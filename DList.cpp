#include <iostream>

int count = 0;

class DLNode 
{
    // TODO: implement the node class 
public:
    int data;
    DLNode* next;
    DLNode* previous;
    DLNode() = delete;
    DLNode(int num) : data{ num }, next{ nullptr }, previous{ nullptr } {}
};

typedef DLNode* DLNodePtr;

class DList 
{

    // TODO: implement the list class 


public:
    DList() : head{ nullptr }, tail{ nullptr } {std::cout << "default constructor called\n"; }

    void traverse();
    void reverse_transverse();
    void add_at_head(int num);
    void add_at_tail(int num);
    DLNodePtr search(int target);
    void remove(const DLNodePtr& curNode);



private:
    DLNode* head;
    DLNode* tail;
};




int main() 
{
    DLNodePtr head{ nullptr };
    DLNodePtr tail{ nullptr };
    

    DLNodePtr Node1 = new DLNode(5);

    // TODO: create a DList object named dlist
        DList dlist;

    // TODO: uncomment following code snippet to add numbers to dlist
     for (auto i : { 5, 4, 3, 2, 1 })
         dlist.add_at_head(i);


    // TODO: uncomment following code snippet to add numbers to dlist 
     for (auto i: {11, 12, 13, 14, 15})
       dlist.add_at_tail(i); 

    // TODO: uncomment following code snippet to test search function
     auto pTemp = dlist.search(12); 
     std::cout << pTemp << " returning address of searched node\n";
     std::cout << pTemp->data << " ------------\n";

    // TODO: call dlist's delete function to delete pTemp from the list. 


     dlist.traverse();
     dlist.reverse_transverse();



     dlist.search(15);
     dlist.search(21);

     dlist.remove(pTemp);
     dlist.traverse();

     auto aTemp = dlist.search(1);
     dlist.remove(aTemp);
     dlist.traverse();

     auto bTemp = dlist.search(15);
     dlist.remove(bTemp);
     dlist.traverse();

     auto cTemp = dlist.search(20);
     dlist.remove(cTemp);
     dlist.traverse();
  
     //std::cout << std::boolalpha << dlist.search(15) << std::endl;
     //std::cout << std::boolalpha << dlist.search(7) << std::endl;
     //std::cout << std::boolalpha << dlist.search(4) <<std::endl;

    return 0;
}

void DList::traverse()
{
    std::cout << "Transversing Dlist [ ";
        DLNodePtr curNode = this->head; // Start at head

    while (curNode != nullptr)
    {
        std::cout << curNode->data << " ";
        curNode = curNode->next;
    }
    std::cout << "]\n"; 
};

void DList::add_at_head(int num)
{
    std::cout << num << std::endl;
    DLNodePtr newNode = new DLNode(num);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        std::cout << "first node" << num << std::endl;
    }
    else
    {
        newNode->next = this->head;
        head->previous = newNode;
        this->head = newNode;
        std::cout << num << std::endl;

        std::cout << count + 1 << " numbers been added = " << num << std::endl;
        count++;
    }
}

void DList::add_at_tail(int num)
{
    std::cout << num << std::endl;
    DLNodePtr newNode = new DLNode(num);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        std::cout << "first node" << num << std::endl;
    }
    else
    {
        this->tail->next = newNode;
        newNode->previous = this->tail;
        this->tail = newNode;

        std::cout << count + 1 << " numbers been added = " << num << std::endl;
        count++;
    }
}

void DList::reverse_transverse()
{
    std::cout << "Reversing Dlist [ ";
    DLNodePtr curNode = this->tail; // Start at tail

    while (curNode != nullptr)
    {
        std::cout << curNode->data << " ";
        curNode = curNode->previous;
    }
    std::cout << "]\n";
}

DLNodePtr DList::search(int target)
{
    DLNodePtr temp = head;
    while (temp != nullptr)  /// same as while (temp)
    {
        if (temp->data == target)
        {
            std::cout << "number " << target << " is  in dList\n";
            return temp;
        }
        temp = temp->next;
    }
    std::cout << "number " << target << " is not in dList\n";
    return nullptr;
}

void DList::remove(const DLNodePtr& curNode)
{
    if (curNode == nullptr)
        return;
    DLNodePtr sucNode = curNode->next;
    DLNodePtr preNode = curNode->previous;

    if (sucNode != nullptr)
    {
        sucNode->previous = preNode;
    }

    if (preNode != nullptr)
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
