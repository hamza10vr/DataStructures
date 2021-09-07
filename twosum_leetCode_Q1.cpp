// CS 400 Leet Code Q1: Design a function that takes a vector of ints and a target int, returns a std::pair object containing indices of two numbers from the vector that adds up to the target.
// name: Hamza Tanveer


#include <iostream>
#include <vector>
#include <utility>  // for std::pair

//takes a vector of ints and a target int, returns a std::pair object containing 
//indices of two numbers from the vector that adds up to the target.
std::pair<int, int> twoSum(const std::vector<int>& vi, const int target);

//takes vector of int, std::pair object, and target and prints the inputs and output
void print(const std::vector<int>& vi, std::pair<int, int> pair, int target);

int main() {

    // creating multiple vectors of type int
    std::vector<int> input1{ 3,4,7,8 };
    std::vector<int> input2{ 3,5,7 };
    std::vector<int> input3{ 3,2,4,4 };
    std::vector<int> input4{ 2,7,11,15 };
    std::vector<int> input5{ 3,2,4 };
    std::vector<int> input6{ 2,7,11,15 };

    // storing  the answer of twoSum() function in std::pair object 
    std::pair<int, int> pair1 = twoSum(input1, 10);
    std::pair<int, int> pair2 = twoSum(input2, 10);
    std::pair<int, int> pair3 = twoSum(input3, 8);
    std::pair<int, int> pair4 = twoSum(input4, 9);
    std::pair<int, int> pair5 = twoSum(input5, 6);
    std::pair<int, int> pair6 = twoSum(input6, 6);

    //function for printing out the results
    print(input2, pair1, 10);
    print(input2, pair2, 10);
    print(input3, pair3, 8);
    print(input4, pair4, 9);
    print(input5, pair5, 6);
    print(input6, pair6, 6);


    return 0;
}


std::pair<int, int> twoSum(const std::vector<int>& vi, const int target)
{
    // TODO: implement your function here 

    int first(-1), second(-1); // setting the indices to -1 in the event no two numers are found

    // 1st loop to compare the 1st number with the rest
    for (int i = 0; i < vi.size(); ++i)
    {
        //second loop starting from the second # to the end 
        for (int j = i + 1; j < vi.size(); ++j)
        {

            // if the target is found by adding 2 vectors then storing the indices in first & second 
            // and breaking out of the loop to return the values
            if (vi.at(i) + vi.at(j) == target)
            {
                first = i;
                second = j;
                break;

            }
        }

    }


    return std::pair<int, int>(first, second);

}

void print(const std::vector<int>& vi, std::pair<int, int> pair, int target)
{
    if (pair.first && pair.second < 0) // if indices are -1 then prints "No two numbers found"
    {
        std::cout << "input v[";
        for (int i = 0; i < vi.size(); ++i)
            std::cout << vi.at(i) << ",";
        std::cout << "], " << target << "; NO two numbers from the vector that adds up to the target of "
            << target << std::endl << std::endl;
    }

    else
    {
        std::cout << "input v[";
        for (int i = 0; i < vi.size(); ++i)
            std::cout << vi.at(i) << ",";
        std::cout << "], " << target << "; output[" << pair.first << "," << pair.second << "] as v["
            << pair.first << "] + v[" << pair.second << "] = " << target << std::endl << std::endl;
    }
}


