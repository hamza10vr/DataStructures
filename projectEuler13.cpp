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

    
    list<int> intermidiateSum;  // linked list to hold the numbers sum
    
    string line;                 // string for reading 50-digit long numbers as string 
    while (inFS >> line)         // as long as nums.txt has line it will keep reading
    {
        // convert each char of string to int and push to linked list
        list<int> currentNum;
/*        for (int i = num.length() - 1; i >= 0; i--)
        {
            currentNum.push_back(num[i] - '0');
        }   */     
        
        std::cout << line << std::endl;

        for (auto i = 0; i < line.length(); ++i) 
        {
            currentNum.push_front(line.at(i) - '0');
        }


       // for (auto i : num.length())

        for (auto i : currentNum)
            std::cout << i << " " << std::endl;
        // add the current number to the sum
        //intermidiateSum = sumOfTwoList(intermidiateSum, currentNum);
    }

    std::cout << "\nclosing file xxxxxx" << std::endl << std::endl;
    inFS.close(); // Done with file, so close it


    // reverse the linked list
    intermidiateSum.reverse();

    // print out the sum
    std::cout << "The sum is: ";
    printAnswer(intermidiateSum);
    return 0;
}