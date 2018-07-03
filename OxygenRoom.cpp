#include "OxygenRoom.hpp"

#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void OxygenRoom::settingInfo()
{
	std::cout << "The U.S.S Hopeful Heritage Oxygen Room. This room specifically controls the oxygen" << std::endl;
	std::cout << "levels for the spaceship." << std::endl;
}
int OxygenRoom::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "                Oxygen Room\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Float down to go to the Lounge           \n";
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