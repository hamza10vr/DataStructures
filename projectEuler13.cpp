   
/*  Project Eculer Question 13
    Hamza Tanveer
    9/21/2021
    HW 3
*/




#include<iostream>
#include<fstream>
#include<list>



void print (std::list<int>& list);                                // function to print out the answer
void reverseStr (std::string& str);                              // function to reverse the string
void addition (std::list<int>& list_1, std::string new_line);   // using 1 linked list calculating summation of numbers given in nums.txt 

int main()
{
    std::ifstream inFS;
    std::list<int> list;


    inFS.open("nums.txt");      
    if (!inFS.is_open())        
    {
        std::cout << "Could not open nums.txt" << std::endl;
        return -1;                                   // 1 indicates error
    }
    std::cout << "========== filed opened successfully ==========" << std::endl;

    
    std::string line;                            // reading the first number from file as  string and storing in linked list as single digits
    inFS >> line;
    unsigned int i;
    for ( i = 0; i < line.length(); ++i)      // loop to store 50 digit string into the linked list
    {
        list.push_front(line.at(i) - '0');  // converts each character in string to <int> and pushes it to the list
    }

    std::cout << "========== performing calculations   ==========\n" << std::endl;


    
    while (inFS >> line)            // as long as nums.txt has line it will keep reading and feeding it to addition function
    {
        addition(list, line);
    }

   

    list.reverse();     // reverse the list built in function of STL list


    print(list);    // print out the sum

    std::cout << "\n========== closing file    ====================" << std::endl << std::endl;
    inFS.close(); // Done with file, so close it






    return 0;
}





void print (std::list<int>& list)       //prints out the sum 
{
                                                               
    std::cout << "The sum is: ";
    for (auto number : list)
    {
        std::cout << number;      // prints the total sum using range based for-loop
    }
    std::cout << std::endl;

                                                                        
    
    int n = 0;                                                  
    std::cout << "10 digits =  ";
    std::list<int>::iterator it; 
    for (it = list.begin(); it != list.end() && n<10; ++it)
    {
        std::cout << *it;           // prints the fist 10 digits, using iterator
        n++;
    }

    
   
    std::cout << "\nLinked list has: " << list.size() << " nodes\n";     // prints the size of the list
}



void reverseStr (std::string& str)      // reverses the string before feeding it to the list for addition.
{
    int n = str.length();

    
    for (int i = 0; i < n / 2; i++)
    {
        std::swap(str[i], str[n - i - 1]);      // Swap character starting from two corners
    }
}


 // add function uses reference to list
// this allows same list to be modified with new digits instead of creating new list every time
void addition (std::list<int>& list_1, std::string new_line)
{
   
    int carry = 0;                   // carry initialy set to 0
    int digit;                      // hold the <int> after being convrted from 'char'
    unsigned int i = 0;            // iterating through the each "char" in 50 "char" long string
    reverseStr(new_line);         // reverses the line read by input file stream
    std::list<int>::iterator it; // declaration of iterator as it


    
    for (it = list_1.begin(); it != list_1.end(); ++it)     // iterates through each node of list and adding the new number read from file
    {

        if (i < new_line.length())          
        {
            digit = new_line.at(i) - '0';   // converts "char" to <int> and store in "digit"
            *it = *it + digit  + carry;    // update list node value  with = curent digit from list + new digit from file + carry
        }
        else                             // no new digits from input file but still digit in list
        {
            *it =  *it + carry;        // add current numer from list + carry 
        }


                                   
                                

        if (*it >= 10)          // if the new number after addition is greater than 10 
        {                      // ex 14 - store= 4 , carry =1
            carry = 1;        // carry  = 1

            *it = *it % 10; // digit stored = 4

        }
        else                    // if number less than 10 
        {                      // ex 7 - keep it stored in list
            carry = 0;        // make carry = 0
                                
        }

        i++;             // increase the interator for reading the next "char" in string


    }

    
    if (carry == 1)                   //once the addition is done but carry still there, then 
    {
        list_1.push_back(carry);    // add the carry at the end of the list
    }



}
