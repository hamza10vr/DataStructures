#include<iostream>
#include<fstream>
#include<list>



void print (std::list<int>& list);         // function to print out the answer
void reverseStr (std::string& str);        // function to reverse the string
void addition (std::list<int>& list_1, std::string new_line);   // using 1 linked list calculating summation of numbers given in nums.txt 

int main()
{
    std::ifstream inFS;


    //trying to open file
    std::cout << "========== opening nums.txt ==========" << std::endl;

    inFS.open("nums.txt");      // opening file
    if (!inFS.is_open())        // for some reason file doesn't open through out an error and exit
    {
        std::cout << "Could not open nums.txt" << std::endl;
        return -1; // 1 indicates error
    }

    std::cout << "========== filed opened successfully ==========" << std::endl;

    std::list<int> list;

    std::string line;                 // string for reading 50-digit long numbers as string 
    inFS >> line;


    for (auto i = 0; i < line.length(); ++i)
    {
        list.push_front(line.at(i) - '0');
    }

    std::cout << "========== performing calculations ==========" << std::endl;

    int a = 1;
    while (inFS >> line)         // as long as nums.txt has line it will keep reading
    {
        addition(list, line);
    }



    std::cout << "===== closing file =====" << std::endl << std::endl;
    inFS.close(); // Done with file, so close it



    list.reverse();

    
    print(list);    // print out the sum


    return 0;
}






void print (std::list<int>& list)
{
    std::cout << "The sum is: ";
    for (auto number : list)
        std::cout << number;
    std::cout << std::endl;
    int sizee = list.size();
    std::cout << " size is " << sizee;
}

void reverseStr (std::string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
}

void addition (std::list<int>& list_1, std::string new_line)
{
    std::list<int>::iterator it = list_1.begin();
    int carry = 0;
    int digit = -1;
    unsigned int i = 0;
    reverseStr(new_line);



    for (it = list_1.begin(); it != list_1.end(); ++it)
    {

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



        if (*it >= 10)
        {
            carry = 1;

            *it = *it % 10;

        }
        else
        {
            carry = 0;

        }

        i++;


    }

    if (carry == 1)
    {
        list_1.push_back(carry);
    }



}
