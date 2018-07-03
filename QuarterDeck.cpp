#include "QuarterDeck.hpp"

#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void QuarterDeck::settingInfo()
{
	std::cout << "The U.S.S. Hopeful Heritage Quarter Deck. This is where all the crew members slept," << std::endl;
	std::cout << "however, there is no one in here. The room contains a few empty beds and a desk." << std::endl;
}
int QuarterDeck::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "              Quarter Deck\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Turn Right to go to the Sick Bay         \n";
	std::cout << "2) Float up to go to the Lounge             \n";
	std::cout << "3) Search your surroundings                 \n";
	std::cout << "4) Quit                                     \n";
	std::cout << "--------------------------------------------\n" << std::endl;

	cin >> userStringInput;

	while (userStringInput != "1" && userStringInput != "2" && userStringInput != "3" && userStringInput != "4")
	{
		cout << "Sorry that is not a valid choice. Please enter 1, 2, 3, or 4!" << endl;

		cin >> userStringInput;
	}

	userIntInput = stoi(userStringInput);

	return userIntInput;
}