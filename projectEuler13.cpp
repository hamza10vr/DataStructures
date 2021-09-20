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


void print(list<int> &list)         // function to print out the answer
{
    std::cout << "The sum is: ";
    for (auto number : list)
        std::cout << number;
    std::cout << endl;
    int sizee = list.size();
    std::cout << " size is " << sizee;
}

void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void addition(std::list<int>& list_1, std::string new_line)
{
    std::list<int>::iterator it = list_1.begin();
    int carry = 0;
    int digit = -1;
    int temp;
    reverseStr(new_line);

    std::cout << "\reading original : ";
    for (auto i : list_1)
        std::cout << i ;

    std::cout << "\nreading new line: ";
    for (auto i : new_line)
        std::cout << i;


    unsigned int i = 0;
    //for (auto i =0 ; i < new_line.size(); i++)
    //{
    for (it = list_1.begin(); it != list_1.end(); ++it)
    {
        std::cout << std::endl << i << ". " << *it;
        // std::cout << ' ' << *it;
        if (i < new_line.length()) 
        {
            digit = new_line.at(i) - '0';
            *it = digit + *it + carry;
        }
        else 
        {
            digit = 0;
            *it = *it + carry;
        }

        //std::cout << std::endl;
        //std::cout << "\nnew digit = " << digit << std::endl;
        std::cout <<  " + "  << digit ;




        if (*it >= 10)                 // 14
        {
            carry = 1;                  // +1
            //temp = temp % 10;           // 4
            *it = *it % 10;                 //*it = 4
            std::cout << "  1st if ";
        }
        else    // if the sum of two digits is less than 10, take 0 as the carry
        {
            carry = 0;
            //*it = *it;
            std::cout << "  2rd if ";
        }
        //if (digit == 0)
        //{
        //    std::cout << "  before 3nd if " << *it <<"  3rd if ";
        //    //*it = *it + carry;
        //    carry = 0;
        //    std::cout << "  3rd if ";
        //}


        //if (*it < 10)
        //{
        //    *it += carry;
        //    
        //}

        std::cout << " = " << *it << " with carry = " << carry;

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
        std::cout << "read numer for the " << a << " |  time ";
    }



    std::cout << "\n===== closing file =====" << std::endl << std::endl;
    inFS.close(); // Done with file, so close it

  /*  std::cout << "\nForward  list = ";
    for (auto i : list)
        std::cout << i;*/


    list.reverse();

    //std::cout << "\nReversed list = ";
    //for (auto i : list)
    //    std::cout << i;


    
    print(list);    // print out the sum


    return 0;
}