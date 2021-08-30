#include <iostream>


void printQuadratic1();			// prints 40 prime numbers generated by formula n^2 + n + 41
void printQuadratic2();			// prints 80 prime numbers generated by formula n^2 -79 * n +1601

int main ()
{

	std::cout << "\n*** Printing 40 primes generated by formula n^2 + n +41 ***\n\n";
	printQuadratic1();

	std::cout << "\n*** Printing 80 primes generated by formula n^2 - 79n + 1601 ***\n\n";
	printQuadratic2();


}

void printQuadratic1()
{
	for (int i = 0; i < 40; ++i)
	{
		std::cout << i + 1 << ". prime number is = " << (i * i) + i + 41 << std::endl;
		//std::cout  << "|" << (i * i) + i + 41 << "|  ";
	}
}

void printQuadratic2()
{
	for (int i = 0; i < 80; ++i)
	{
		std::cout << i + 1 << ". prime number is = " << (i * i) - (79 * i) + (1601) << std::endl;
	}
}