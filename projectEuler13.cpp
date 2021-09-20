#include<iostream>
#include<fstream>
#include<list>
using namespace std;

// function to add two numbers
list<int> sumOfTwoList(list<int> list1, list<int> list2)
{
    list<int> result;
    int carry = 0;
    int temp;

    while (!list1.empty() || !list2.empty()) {
        // if list1 is empty, add the carry to the list2
        if (list1.empty())
        {
            temp = list2.front() + carry;
            list2.pop_front();
        }
        // if list2 is empty, add the carry to the list1
        else if (list2.empty())
        {
            temp = list1.front() + carry;
            list1.pop_front();
        }
        // if both list1 and list2 are not empty, add them
        else
        {
            temp = list1.front() + list2.front() + carry;
            list1.pop_front();
            list2.pop_front();
        }
        // if the sum of two digits is greater than 10, take 1 as the carry
        if (temp >= 10)
        {
            carry = 1;
            temp = temp % 10;
        }
        // if the sum of two digits is less than 10, take 0 as the carry
        else
        {
            carry = 0;
        }
        // add the sum of digit to the result list
        result.push_back(temp);
    }
    // if the carry is not 0, add it to the result list
    if (carry == 1) {
        result.push_back(carry);
    }
    
    return result;
}

// function to print out the answer
void printAnswer(list<int> list)
{
    for (auto digit : list)
        std::cout << digit;
    std::cout << endl;
}

void addition(std::list<int> &list_1, std::string new_line)
{
    std::list<int>::iterator it = list_1.begin();
    int carry = 0;
    int new_number, temp;

    std::cout << "\reading original list inside function ";
    for (auto i : list_1)
        std::cout << i << " ";

    std::cout << "\nreading new line: ";
    for (auto i : new_line)
        std::cout << i << " ";

    
    unsigned int i = 0;
    //for (auto i =0 ; i < new_line.size(); i++)
    //{
    for (it = list_1.begin(); it != list_1.end(); ++it)
    {
       // std::cout << ' ' << *it;
        if (i < new_line.length()) {
            new_number = new_line.at(i) - '0';
            temp = (new_line.at(i) - '0') + *it + carry;
        }
        else {
            new_number = 0;
            temp = *it;
        }
            std::cout << "\nnew numbers = " << new_number << std::endl;
            std::cout << new_number << " + " << *it;
        

        

        if (temp >= 10)
        {
            carry = 1;
            temp = temp % 10;
            *it = temp;
        }
        
        else    // if the sum of two digits is less than 10, take 0 as the carry
        {
            carry = 0;
            //*it = new_line.at(i);
            *it = temp;
        }

        //if (*it < 10)
        //{
        //    *it += carry;
        //    
        //}

        std::cout << " = " << carry << *it << std::endl;

        i++;


    }
    
    if (carry == 1)
    {
        list_1.push_back(carry);
    }

    

}

int main() 
{
    std::ifstream inFS;


	//trying to open file
	std::cout << "opening nums.txt" << std::endl;

	inFS.open("nums.txt");      // opening file
	if (!inFS.is_open())        // for some reason file doesn't open through out an error and exit
    {
		std::cout << "Could not open nums.txt" << std::endl;
		return -1; // 1 indicates error
	}

    list<int> list;
    
    string line;                 // string for reading 50-digit long numbers as string 
    inFS >> line;


    for (auto i = 0; i < line.length(); ++i)
    {
        list.push_front(line.at(i) - '0');
    }

    //std::cout << "\reading original list ";
    //for (auto i : list)
    //    std::cout << i << " " ;

    //std::cout << std::endl;

    int a = 1;
    while (inFS >> line)         // as long as nums.txt has line it will keep reading
    {
        addition(list, line);
        a++;
        std::cout <<"read numer for the "<<  a << " |  time ";
    }



    std::cout << "\n===== closing file =====" << std::endl << std::endl;
    inFS.close(); // Done with file, so close it

    std::cout << "\nForward  list = ";
    for (auto i : list)
        std::cout << i ;

    
    list.reverse();

    std::cout << "\nReversed list = ";
    for (auto i : list)
        std::cout << i;


    //// print out the sum
    //std::cout << "The sum is: ";
    //printAnswer(intermidiateSum);
    return 0;
}