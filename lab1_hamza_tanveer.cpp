/*    
*     *** Implementing a dynamicArray ***
      ***  Hamza Tanveer ****
      ***   LAB 1 ***
    
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class DynamicArray {
    public:
        
  
        DynamicArray();                                             // Default constuctor to allocate array of size 10
        DynamicArray(int size);                                     // parameterized constructor , takes size to allocate Array size
        DynamicArray(const DynamicArray& obj);                      // Copy Constructor , which performs deep copy
        DynamicArray& operator = (const DynamicArray& obj);         // Copy assignment operator which also supports self-assignment
        ~DynamicArray();                                            // Destructor to recycle allocated memory
        void insertionSort();
        void fill();                                                // member function that fills array with random numbers
        void print();                                               // member function that prints all elements from the array


    private:
        int arraySize;
        int* pointerToDynArray;
};



int main() {

    srand((unsigned)time(NULL));

    

    std::cout << "creating object 1 .....\n";
    DynamicArray object1;
   
    std::cout << "filling object 1 .....\n";
    
    object1.fill();

    std::cout << "printing object 1 .....\n";
    object1.print();


    std::cout << "creating object 2 with size 20 as parameter\n";
    DynamicArray object2(20);

    std::cout << "filling object 2\n";

    object2.fill();

    std::cout << "printing object 2\n";
    object2.print();


    std::cout << "Creating default object 3 and then assigned object 2.\n";
    DynamicArray object3(object2);
    object3.print();
 
 
    std::cout << "object 3 is assigned object 1\n";
    object3 = object1;
    object3.print();


    std::cout << "object 3 self assigned\n";
    object3 = object3;
    object3.print();

    std::cout << "Array from obbject 3 is sorted in ascending order using insertion sort\n";
    object3.insertionSort();
    object3.print();


    return 0;
};


// default constuctor to allocate array of size 10
DynamicArray::DynamicArray() {
    this->arraySize = 10; 
    this->pointerToDynArray = new int[arraySize]; 
    std::cout << "Default constructor succeccful, Allocated array of size 10\n" ;
}

// parameterized constructor , takes size to allocate Array size
DynamicArray::DynamicArray(int size)
{
    this->arraySize = size;
    this->pointerToDynArray = new int[size];
    std::cout << "parameterized constructor succeccful, Allocated array of size " << size << std::endl;
}

DynamicArray::DynamicArray(const DynamicArray& obj)

{
    std::cout << " copy constructor invoked\n";
    this->arraySize = obj.arraySize;
    this->pointerToDynArray = new int[obj.arraySize];

    for (int i = 0; i < this->arraySize; i++)
    {
        this->pointerToDynArray[i] = obj.pointerToDynArray[i];
    }

    std::cout << " copy constructor completed successfully\n";


}

DynamicArray& DynamicArray::operator=(const DynamicArray& obj)
{
    if (this != &obj)
    {
        std::cout << "copy assignment operator invoked" << std::endl;

        this->arraySize = obj.arraySize;
        this->pointerToDynArray = new int[arraySize];

        for (int i = 0; i < arraySize; i++)
            this->pointerToDynArray[i] = obj.pointerToDynArray[i];

        std::cout << "copy assignment operator completed successfully\n";

    }
    return *this;
}


//Destructor to recycle allocated memory
DynamicArray::~DynamicArray() 
{ 
    delete[] pointerToDynArray; 
    std::cout << "Destructor called successfully\n";
}

void DynamicArray::insertionSort()
{
    // starting at the second number
    for (int i=1; i < this->arraySize; ++i)
    { 
        // try to find a good spot on the left
        int j = i - 1;

            while (j >= 0 && this->pointerToDynArray[j] > this->pointerToDynArray[j + 1])
            {
                std::swap(this->pointerToDynArray[j], this->pointerToDynArray[j + 1]);
                --j;
            }
    }
}





// member function that fills array with random numbers
void DynamicArray::fill()
{
    //srand((unsigned)time(NULL));


    for (int i(0); i < this->arraySize; i++)
    {
        int randNum = rand() % 100;
        this->pointerToDynArray[i] = randNum;

    }

}

// member function that prints all elements from the array
void DynamicArray::print()
{
    std::cout << "|";
    for (int i(0); i < this->arraySize; i++)
    {
        std::cout << this->pointerToDynArray[i] << " |";
    }
    std::cout << std::endl << std::endl;

}

