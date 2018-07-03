#include "Bathroom.hpp"

#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Bathroom::settingInfo()
{
	std::cout << "Ahh the wonderful U.S.S. Hopeful Heritage's bathroom. The bathroom contains a high-tech anti-gravitational" << std::endl;
	std::cout << "toilet as well as a shower and a locker. Other than that the place is pretty empty." << std::endl;
}

int Bathroom::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "                Bathroom\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Turn Left to go to the Lounge            \n";
	std::cout << "2) Search your surroundings                 \n";
	std::cout << "3) Quit                                     \n";
	std::cout << "--------------------------------------------\n" << std::endl;

	cin >> userStringInput;

	while (userStringInput != "1" && userStringInput != "2" && userStringInput != "3")
	{
		cout << "Sorry that is not a valid choice. Please enter 1, 2, or 3!" << endl;

		cin >> userStringInput;
	}

	userIntInput = stoi(userStringInput);

	return userIntInput;
}