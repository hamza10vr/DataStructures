// CS 400 HW 2: application of std::vector to handle car objects 
// name: Hamza Tanveer
// Date: Sep 7, 2021


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>



class rentalCar
{
public:
	rentalCar();									// default constructor
	rentalCar(int id, std::string make, std::string model) { this->id = id; this->make= make; this->model = model; }	// parameterized constructor

	/************ Setters    *****************************/
	void setid(int id) { this->id = id; }
	void setMake(std::string make) { this-> make = make; }
	void setModel(std::string model) { this->model = model; }

	/************ Getters    **************************/
	int getid() const { return this->id; }
	std::string getMake() const { return this->make; }
	std::string getModel() const { return this->model; }

	//**********  Helper functions  ****//
	void searchId(std::vector<rentalCar>& cars) const;		// searches id against car database and prints results to screen
	void searchMake(std::vector<rentalCar>& cars) const;	// searches Make against car database and prints results to screen
	void searchModle(std::vector<rentalCar>& cars) const ;	// searches MODLE against car database and prints results to screen
	void addCar(std::vector<rentalCar>& cars);		// add a new car (new car id cannot be same as existing ones)
	void delCarbyID(std::vector<rentalCar>& cars);	// delete an existing car by id

	void ReadandStore(std::vector<rentalCar>& classobj); // reads the data from cars.dat file and stores it in vector
	void listAllCars(std::vector<rentalCar>& cars);		// iterated through the vector holding car database and prints to screen

	void appendingToFile(std::vector<rentalCar>& cars)const;	// appends the new cars added to the end of cars.data file



	//void apptoCarsData(fstream& out);





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
	std::cout << "============================================================================\n"
			<< "============================================================================"
			<< "\nwelcome to Hamza Car Rental\nPlease select from the following ( 1 - 7 ) option:"
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
			cars.at(0).addCar(cars);
			break;

		case 5:
			cars.at(0).delCarbyID(cars);
			break;

		case 6:
			cars.at(0).listAllCars(cars);
			break;

		case 7:
			std::cout << "\n\n******** See you soon ********\n" << std::endl;
	
			break;
		default:
		{
			std::cout << "\n******** not a valid option ********" << std::endl;
			std::cout << "******** Please choose a number from 1 to 7  ********\n" << std::endl;
		}
			break;
		}

	} while (selection != 7);
	


	cars.at(0).appendingToFile(cars);

	return 0;
}


void rentalCar::appendingToFile(std::vector<rentalCar>& cars) const
{
	std::ofstream outFS; // Output file stream

   // Open file
	outFS.open("cars.data");

	if (!outFS.is_open()) {
		std::cout << "Could not open file myoutfile.txt." << std::endl;
		
	}

	// Write to file using for looop
	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		outFS << cars.at(i).getid() << std::endl;
		outFS << cars.at(i).getMake() << std::endl;
		outFS << cars.at(i).getModel() << std::endl;
	}

	// Done with file, so close
	outFS.close();

}

rentalCar::rentalCar()
{
	this->id = 0;
	this->make = "no make"; 
	this->model = "no model"; 
	
}

void rentalCar::ReadandStore(std::vector<rentalCar>& classobj)
{
	std::ifstream inFS;


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

// prints the entire car database for the user
void rentalCar::listAllCars(std::vector<rentalCar>& cars)
{
	std::cout << "\n\n" << std::setw(6) << std::left << "ID" << "|" << std::setw(10) << std::left << "  Make" << "|" << std::setw(10) << std::left << "  Model" << std::endl;
	std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
	std::cout << std::setfill(' ');

	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		std::cout << std::setw(6) << std::left << cars.at(i).getid() << "|" << std::setw(10) << std::left << cars.at(i).getMake() << "|" << std::setw(10) << std::left << cars.at(i).getModel() << std::endl;
	}
	std::cout << std::endl;
}


// searches id against car database and prints results to screen
void rentalCar::searchId(std::vector<rentalCar>& cars) const
{
	{
		unsigned int searchID;

		std::cout << "you can choose from the following ' MODEL ' :\n";
		for (unsigned int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different ID available
			std::cout << std::setw(5) << std::left << cars.at(i).getid() << " | ";
		std::cout << "\nSearch by ID (first letter is capital for all makes): ";
		std::cin >> searchID;

		int count = 0;
		for (unsigned int i = 0; i < cars.size(); ++i)		// lopp to iterate through the database searching for id
		{
			if (cars.at(i).getid() == searchID)		//if id found, increases cout and prints out the results
			{
				count++;
				std::cout << "\nyou search has resulted in ' " << count << " ' car from our data base" << std::endl;
				std::cout << std::setw(6) << std::left << "ID" << "|" << std::setw(10) << std::left << "  Make" << "|" << std::setw(10) << std::left << "  Model" << std::endl;
				std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
				std::cout << std::setfill(' ');
				std::cout << std::setw(6) << std::left << cars.at(i).getid() << "|" << std::setw(10) << std::left << cars.at(i).getMake() << "|" << std::setw(10) << std::left << cars.at(i).getModel() << std::endl ;
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
void rentalCar::searchMake(std::vector<rentalCar>& cars) const
{
	{
		std::string searchMake;

		std::cout << "you can choose from the following ' Make ' :\n";
		for (unsigned int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different makes available
			std::cout << std::setw(5) << std::left << cars.at(i).getMake() << " | ";
		std::cout << "\nSearch by Make (all lowercase): ";
		std::cin >> searchMake;

		std::cout << std::setw(6) << std::left << "ID" << "|" << std::setw(10) << std::left << "  Make" << "|" << std::setw(10) << std::left << "  Model" << std::endl;
		std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
		std::cout << std::setfill(' ');
		int count = 0;
		for (unsigned int i = 0; i < cars.size(); ++i)			// lopp to iterate through the database searching for "MAKE"
		{
			if (cars.at(i).getMake() == searchMake)		//if " MAKE " found, increases cout and prints out the results
			{
				count++;
				std::cout << std::setw(6) << std::left << cars.at(i).getid() << "|" << std::setw(10) << std::left << cars.at(i).getMake() << "|" << std::setw(10) << std::left << cars.at(i).getModel() << std::endl ;
				
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

void rentalCar::searchModle(std::vector<rentalCar>& cars) const
{
	{
		std::string searchModel;

		std::cout << "you can choose from the following ' MODEL ' :\n";
		for (unsigned int i(0); i < cars.size(); ++i)									// iterated through the database to pull out all the  different MODEL available
			std::cout << std::setw(5) << std::left << cars.at(i).getModel() << " | ";
		std::cout << "\nSearch by MODEL (all lowercase): ";
		std::cin >> searchModel;

		std::cout << std::setw(6) << std::left << "ID" << "|" << std::setw(10) << std::left << "  Make" << "|" << std::setw(10) << std::left << "  Model" << std::endl;
		std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
		std::cout << std::setfill(' ');
		unsigned int count = 0;
		for (unsigned int i = 0; i < cars.size(); ++i)			// lopp to iterate through the database searching for "MODEL"
		{
			if (cars.at(i).getModel() == searchModel)		//if " MODEL " found, increases cout and prints out the results
			{
				count++;
				std::cout << std::setw(6) << std::left << cars.at(i).getid() << "|" << std::setw(10) << std::left << cars.at(i).getMake() << "|" << std::setw(10) << std::left << cars.at(i).getModel() << std::endl;

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

void rentalCar::addCar(std::vector<rentalCar>& cars)
{

	int newID;
	std::string newMake;
	std::string newModel;

	std::cout << "Enter your car ID: ";
	std::cin >> newID;
	bool match = false;
	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		if (cars.at(i).getid() == newID)
		{
			std::cout << "\n*******Car ID already in use, please use a different ID ********" << std::endl;
			match = true;
		}
	}
	if (match == false)
	{
		std::cout << "Enter your  car Make: ";
		std::cin >> newMake;
		std::cout << "Enter your  car Model: ";
		std::cin >> newModel;

		rentalCar newcar(newID, newMake, newModel);
		cars.push_back(newcar);
	}

	
}

void rentalCar::delCarbyID(std::vector<rentalCar>& cars)
{
	std::cout << "To delete a car from database, Please type the car's: ";
	int delID;
	std::cin >> delID;
	bool match = false;
	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		if (cars.at(i).getid() == delID)
		{
			cars.erase(cars.begin() + i);
			std::cout << "\n*******Car ID found and car entry deleted from database ********" << std::endl;
			match = true;
		}
	}
	if (match == false)
	{
		std::cout << "\n car ID not found in the system... Please try again with correct car ID: ";

	}
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
