#include "SickBay.hpp"

#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void SickBay::settingInfo()
{
	std::cout << "The U.S.S Hopeful Heritage Sick Bay. This is where our doctor usually lounged around." << std::endl;
	std::cout << "The place contains an exam table, a desk, and a closed medical cabinet attached to the wall." << std::endl;
}
int SickBay::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "                 Sick Bay\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Turn Left to go to the Quarter deck      \n";
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