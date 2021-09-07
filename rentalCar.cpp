#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


class rentalCar
{
public:
	rentalCar() { this->id = 0; this->make = "no make"; this->model = "no model"; }										// default constructor
	rentalCar(int id, std::string make, std::string model) { this->id = id; this->make; make; this->model = model; }	// parameterized constructor

	/************ Setters    *****************************/
	void setid(int id) { this->id = id; }
	void setMake(std::string make) { this-> make = make; }
	void setModel(std::string model) { this->model = model; }

	/************ Getters    **************************/
	int getid() { return this->id; }
	std::string getMake() const { return this->make; }
	std::string getModel() const { return this->model; }

	void listAllCars(std::vector <rentalCar>& v1);


private:
	int id;
	std::string make;
	std::string model;
};

int binarySearch_r(const std::vector<rentalCar>& vi, int target, int low, int high);




int main()
{
	ifstream inFS;
	std::vector<rentalCar> cars(5);

	//trying to open file
	std::cout << "opening file cars.data" << std::endl;

	inFS.open("cars.data");
	if (!inFS.is_open()) {
		std::cout << "Could not open file cars.data" << std::endl;
		return 1; // 1 indicates error
	}

	// Can now use inFS stream like cin stream
	// cars.dat should contain detils about 5 cars
	std::cout << "Reading data from file." << std::endl;

	int ids;
	std::string makes;
	std::string models;

	// for loop to get the data from cars.data file and store it in vector cars
	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		inFS >> ids;
		inFS >> makes;
		inFS >> models;
		cars.at(i).setid(ids);
		cars.at(i).setMake(makes);
		cars.at(i).setModel(models);
	}

	std::cout << "\nData read and stored in vector for cars. Now closing file cars.data" << std::endl;
	inFS.close(); // Done with file, so close it

	int selection;
	do
	{
		std::cout << "welcome to Hamza Car Rental\nPlease select from the following ( 1 - 7 ) option:"
			<< "\n1. Search by id"
			<< "\n2. Search by make"
			<< "\n3. Search by model"
			<< "\n4. add a new car (new car id cannot be sam as existing ones)"
			<< "\n5. delete an existing car by id"
			<< "\n6. list all cars"
			<< "\n7. exit the Program"
			<< "\nEnter your selection #: ";
		std::cin >> selection;

		switch (selection) {

		case 1:
			cout << "That's 15 human years." << endl;
			break;

		case 2:
			cout << "That's 24 human years." << endl;
			break;

		case 3:
			cout << "That's 28 human years." << endl;
			break;

		case 4:
			cout << "That's 32 human years." << endl;
			break;

		case 5:
			cout << "That's 37 human years." << endl;
			break;

		case 6:
			
			std::cout << "\n\n" << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
			std::cout << setfill('-') << setw(26) << "" << std::endl;
			std::cout << setfill(' ');

			for (unsigned int i = 0; i < cars.size(); ++i)
			{
				std::cout << setw(6) << left << cars.at(i).getid() << "|" << setw(10) << left << cars.at(i).getMake() << "|" << setw(10) << left << cars.at(i).getModel() << std::endl;
			}
			std::cout << std::endl;
			break;

		case 7:
			cout << "\n\n******** See you soon ********\n" << endl;
	
			break;
		default:
			cout << "\n******** not a valid option ********" << endl;
			cout << "******** Please choose a number from 1 to 7  ********\n" << endl;
			break;
		}

	} while (selection != 7);
	













	return 0;
}

void rentalCar::listAllCars(std::vector<rentalCar>& v1)
{
	std::cout << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
	std::cout << setfill('-') << setw(26) << "" << std::endl;
	std::cout << setfill(' ');

	for (unsigned int i = 0; i < v1.size(); ++i)
	{
		std::cout << setw(6) << left << v1.at(i).getid() << "|" << setw(10) << left << v1.at(i).getMake() << "|" << setw(10) << left << v1.at(i).getModel() << std::endl;
	}
}

int binarySearch_r(const std::vector<rentalCar>& vi, int target, int low, int high)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (vi.at(mid).getid() == target)
		{
			return mid;
		}
		else if (vi.at(mid) < target)
		{
			return binarySearch_r(vi, target, mid + 1, high);
		}
		else
		{
			return binarySearch_r(vi, target, low, mid - 1);
		}
	}
	
	return -1;
}
