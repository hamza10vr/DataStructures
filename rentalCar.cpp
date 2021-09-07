// CS 400 HW 2: application of std::vector to handle car objects 
// name: Hamza Tanveer
// Date: Sep 7, 2021


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


class rentalCar
{
public:
	rentalCar();									// default constructor
	rentalCar(int id, std::string make, std::string model) { this->id = id; this->make; make; this->model = model; }	// parameterized constructor

	/************ Setters    *****************************/
	void setid(int id) { this->id = id; }
	void setMake(std::string make) { this-> make = make; }
	void setModel(std::string model) { this->model = model; }

	/************ Getters    **************************/
	int getid() { return this->id; }
	std::string getMake() const { return this->make; }
	std::string getModel() const { return this->model; }

	//**********  Helper functions  ****//
	void searchId(vector<rentalCar>& cars);		// searches id against car database and prints results to screen
	void searchMake(vector<rentalCar>& cars);	// searches Make against car database and prints results to screen
	void searchModle(vector<rentalCar>& cars);	// searches MODLE against car database and prints results to screen



	void apptoCarsData(fstream& out);

	void listAllCars(std::vector <rentalCar>& cars);

	void ReadandStore(std::vector<rentalCar>& classobj);


private:
	int id;
	std::string make;
	std::string model;

	std::vector<rentalCar> _vector;
};

//int binarySearch_r(const std::vector<rentalCar>& vi, int target, int low, int high);


int main()
{
	std::vector<rentalCar> cars(5);

	cars.at(0).ReadandStore(cars);
	

	int selection(0);
	do
	{
		std::cout << "\nwelcome to Hamza Car Rental\nPlease select from the following ( 1 - 7 ) option:"
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
			cars.at(0).searchId(cars);
			break;

		case 2:
			cars.at(0).searchMake(cars);
			break;

		case 3:
			cars.at(0).searchModle(cars);
			break;

		case 4:
			cout << "That's 32 human years." << endl;
			break;

		case 5:
			cout << "That's 37 human years." << endl;
			break;

		case 6:
			cars.at(0).listAllCars(cars);
			break;

		case 7:
			cout << "\n\n******** See you soon ********\n" << endl;
	
			break;
		default:
		{
			cout << "\n******** not a valid option ********" << endl;
			cout << "******** Please choose a number from 1 to 7  ********\n" << endl;
		}
			break;
		}

	} while (selection != 7);
	




	return 0;
}

rentalCar::rentalCar()
{
	this->id = 0;
	this->make = "no make"; 
	this->model = "no model"; 
	
}

void rentalCar::listAllCars(std::vector<rentalCar>& cars)
{
	std::cout << "\n\n" << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
	std::cout << setfill('-') << setw(26) << "" << std::endl;
	std::cout << setfill(' ');

	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		std::cout << setw(6) << left << cars.at(i).getid() << "|" << setw(10) << left << cars.at(i).getMake() << "|" << setw(10) << left << cars.at(i).getModel() << std::endl;
	}
	std::cout << std::endl;
}
// searches id against car database and prints results to screen
void rentalCar::searchId(vector<rentalCar>& cars)
{
	{
		int searchID;

		std::cout << "you can choose from the following ' MODEL ' :\n";
		for (int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different ID available
			std::cout << setw(5) << left << cars.at(i).getid() << " | ";
		std::cout << "\nSearch by ID (first letter is capital for all makes): ";
		std::cin >> searchID;

		int count = 0;
		for (int i = 0; i < cars.size(); ++i)		// lopp to iterate through the database searching for id
		{
			if (cars.at(i).getid() == searchID)		//if id found, increases cout and prints out the results
			{
				count++;
				std::cout << "\n\nyou search has resulted in ' " << count << " ' car from our data base" << std::endl;
				std::cout << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
				std::cout << setfill('-') << setw(26) << "" << std::endl;
				std::cout << setfill(' ');
				std::cout << setw(6) << left << cars.at(i).getid() << "|" << setw(10) << left << cars.at(i).getMake() << "|" << setw(10) << left << cars.at(i).getModel() << std::endl ;
				break;
			}			
		}
		if (count == 0)		// if count not increased it means id not found and prints respective message to the screen
		{
			std::cout << "\nyou search has resulted in ' " << count << " ' car from our data base" << std::endl;
			std::cout << "Please try again" << std::endl;
			std::cout << "****************************************************** \n\n" << std::endl;
			
		}

	}
}
// searches id against car database and prints results to screen
void rentalCar::searchMake(vector<rentalCar>& cars)
{
	{
		string searchMake;

		std::cout << "you can choose from the following ' Make ' :\n";
		for (int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different makes available
			std::cout << setw(5) << left << cars.at(i).getMake() << " | ";
		std::cout << "\nSearch by Make (first letter is capital for all makes): ";
		std::cin >> searchMake;

		std::cout << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
		std::cout << setfill('-') << setw(26) << "" << std::endl;
		std::cout << setfill(' ');
		int count = 0;
		for (int i = 0; i < cars.size(); ++i)			// lopp to iterate through the database searching for "MAKE"
		{
			if (cars.at(i).getMake() == searchMake)		//if " MAKE " found, increases cout and prints out the results
			{
				count++;
				std::cout << setw(6) << left << cars.at(i).getid() << "|" << setw(10) << left << cars.at(i).getMake() << "|" << setw(10) << left << cars.at(i).getModel() << std::endl ;
				
			}
		}
		if (count <= 0)			// if count not increased it means "MAKE " not found and prints respective message to the screen
		{
			std::cout << "\nyou search has resulted in ' " << count << " ' car from our data base" << std::endl;
			std::cout << "Please try again" << std::endl;
			std::cout << "****************************************************** \n\n" << std::endl;
		}
		
	}
}

void rentalCar::searchModle(vector<rentalCar>& cars)
{
	{
		string searchModel;

		std::cout << "you can choose from the following ' MODEL ' :\n";
		for (int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different MODEL available
			std::cout << setw(5) << left << cars.at(i).getModel() << " | ";
		std::cout << "\nSearch by MODEL (first letter is capital for all makes): ";
		std::cin >> searchModel;

		std::cout << setw(6) << left << "ID" << "|" << setw(10) << left << "  Make" << "|" << setw(10) << left << "  Model" << std::endl;
		std::cout << setfill('-') << setw(26) << "" << std::endl;
		std::cout << setfill(' ');
		int count = 0;
		for (int i = 0; i < cars.size(); ++i)			// lopp to iterate through the database searching for "MODEL"
		{
			if (cars.at(i).getModel() == searchModel)		//if " MODEL " found, increases cout and prints out the results
			{
				count++;
				std::cout << setw(6) << left << cars.at(i).getid() << "|" << setw(10) << left << cars.at(i).getMake() << "|" << setw(10) << left << cars.at(i).getModel() << std::endl;

			}
		}
		if (count <= 0)			// if count not increased it means "MODLE " not found and prints respective message to the screen
		{
			std::cout << "\nyou search has resulted in ' " << count << " ' car from our data base" << std::endl;
			std::cout << "Please try again" << std::endl;
			std::cout << "****************************************************** \n\n" << std::endl;
		}

	}
}

void rentalCar::apptoCarsData(fstream& out)
{
	std::cout << id << std::endl;
	std::cout << make << std::endl;
	std::cout << model << std::endl;
}

void rentalCar::ReadandStore(std::vector<rentalCar>& classobj)
{
	ifstream inFS;
	

	//trying to open file
	std::cout << "opening file cars.data" << std::endl;

	inFS.open("cars.data");
	if (!inFS.is_open()) {
		std::cout << "Could not open file cars.data" << std::endl;
		; // 1 indicates error
	}

	// Can now use inFS stream like cin stream
	// cars.dat should contain detils about 5 cars
	std::cout << "Reading data from file.................." << std::endl;

	int ids;
	std::string makes;
	std::string models;

	// for loop to get the data from cars.data file and store it in vector cars
	for (unsigned int i = 0; i < classobj.size(); ++i)
	{
		inFS >> ids;
		inFS >> makes;
		inFS >> models;
		classobj.at(i).setid(ids);
		classobj.at(i).setMake(makes);
		classobj.at(i).setModel(models);
	}

	std::cout << "Data read and stored in vector for cars! Now closing file cars.data" << std::endl << std::endl;
	inFS.close(); // Done with file, so close it
}

//int binarySearch_r(const std::vector<rentalCar>& vi, int target, int low, int high)
//{
//	if (low <= high)
//	{
//		int mid = low + (high - low) / 2;
//		if (vi.at(mid).getid() == target)
//		{
//			return mid;
//		}
//		else if (vi.at(mid) < target)
//		{
//			return binarySearch_r(vi, target, mid + 1, high);
//		}
//		else
//		{
//			return binarySearch_r(vi, target, low, mid - 1);
//		}
//	}
//	
//	return -1;
//}
