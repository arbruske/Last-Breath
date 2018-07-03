#include "CommandRoom.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void CommandRoom::settingInfo()
{
	std::cout << "The U.S.S. Hopeful Heritage Command Room. Many crew members used to work in this room," << std::endl;
	std::cout << "however, there is no one in here. Elaborate technology and computers fill the room." << std::endl;
}
int CommandRoom::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "              Command Room\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Turn Right to go to the Lounge           \n";
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