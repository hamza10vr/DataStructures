// CS 400 Leet Code Q88: Develop a function that takes in two sorted (ascending order) vectors, 
// returns another vector that is formed by merging the given two. 
// Note that the result vector must be sorted in ascending order.
// name: Hamza Tanveer


#include <iostream>
#include <vector>
#include <algorithm>


// Develop a function that takes in two sorted(ascending order) vectors, 
//returns another vector that is formed by merging the given two.
//the result vector must be sorted in ascending order.
std::vector<int> mergeSortedArray(const std::vector<int>& v1, const std::vector<int>& v2);

//function for printing input and output in sorted fashion
void print(const std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& sortedV3);

int main()
{

   
    std::vector<int> v1{ 1,2,4,5,9 }; //declaring & initializing v1
    std::vector<int> w1{ 2,5,7,8 };     // declaring & initializing v1
    std::vector<int> sortedV1 = mergeSortedArray(v1, w1);
    print(v1, w1, sortedV1);

    // testing the code with many different vectors
    v1={ 5,7 };
    w1={ 100,200};
    sortedV1 = mergeSortedArray(v1, w1);
    print(v1, w1, sortedV1);

    v1 = { };
    w1 = {1,2,3 };
    sortedV1 = mergeSortedArray(v1, w1);
    print(v1, w1, sortedV1);


    v1 = { };
    w1 = { };
    sortedV1 = mergeSortedArray(v1, w1);
    print(v1, w1, sortedV1);

    v1 = {5,8,10 };
    w1 = { };
    sortedV1 = mergeSortedArray(v1, w1);
    print(v1, w1, sortedV1);

    return 0;
}


std::vector<int> mergeSortedArray(const std::vector<int>& v1, const std::vector<int>& v2)
{

    std::vector<int> v3{};

                                            // merging 2 vectors into 1 vector called Z
    for (int i = 0; i < v1.size(); ++i)
        v3.push_back(v1.at(i));

    for (int i = 0; i < v2.size(); ++i)
        v3.push_back(v2.at(i));

                                        // using sorting algorithm to sort  the newly merged vector
    std::sort(v3.begin(), v3.end());     // #include <algorithm>

    return std::vector<int>(v3);
}


void print(const std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& sortedV3)
{
    unsigned int i;
    std::cout << "input v[";
    for (  i = 0; i < v1.size(); ++i)   // loop for printing v1
        std::cout << v1.at(i) << ",";

    std::cout << "]. w[";
    for ( i = 0; i < v2.size(); ++i)    // loop for printing v2
        std::cout << v2.at(i) << ",";

    std::cout << "]: output: [";
    for ( i = 0; i < sortedV3.size(); ++i)  // loop for printing sorted V3
        std::cout << sortedV3.at(i) << ",";

    std::cout << "]" << std::endl;

}