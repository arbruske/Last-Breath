#include "Lounge.hpp"

#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Lounge::settingInfo()
{

	std::cout << "The U.S.S. Hopeful Heritage Lounge Room. Once a lively place where the crew members " << std::endl;
	std::cout << "would socialize, it now lay waste with dead crewmen." << std::endl;

}
int Lounge::roomMenu()
{
	string userStringInput;
	int userIntInput;

	std::cout << "                 Lounge\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "1) Turn Right to go to the Bathroom         \n";
	std::cout << "2) Turn Left to go to the Command Room      \n";
	std::cout << "3) Float upstairs to go to the Oxygen Room  \n";
	std::cout << "4) Float downstairs to go to the Quarterdeck\n";
	std::cout << "5) Search your surroundings                 \n";
	std::cout << "6) Quit                                     \n";
	std::cout << "--------------------------------------------\n" << endl;

	cin >> userStringInput;

	while (userStringInput != "1" && userStringInput != "2" && userStringInput != "3" && userStringInput != "4" && userStringInput != "5" && userStringInput != "6")
	{
		cout << "Sorry that is not a valid choice. Please enter 1, 2, 3, 4, 5, or 6!" << endl;

		cin >> userStringInput;
	}

	userIntInput = stoi(userStringInput);

	return userIntInput;
}