#include "Player.hpp"

#include <list>

using std::cout;
using std::endl;
using std::cin;
using std::string;

Player::Player()
{
	breaths = 21;
}
void Player::setBreaths(int br)
{
	breaths = br;
}
int Player::getBreaths()
{
	return breaths;
}
bool Player::isHeDead()
{
	if (breaths == 0)
	{
		return true;
	}

	return false;
}
void Player::setPlayerLocation(Space *room)
{
	playerLocation = room;
}
Space* Player::getPlayerLocation()
{
	return playerLocation;
}

int Player::getSpaceBagSize()
{
	return spaceBag.size();
}

bool Player::searchSpaceBag(std::string item)
{
	for (std::list<std::string>::iterator it = spaceBag.begin(); it != spaceBag.end(); it++)
	{
		if (*it == item)
			return true;
	}

	return false;
}

void Player::insertItem(std::string item)
{
	spaceBag.push_back(item);
}

void Player::removeItem()
{
	int countItems = 1;
	std::string userStringInput;

	cout << endl;
	cout << "Which item do you want to remove?\n";
	cout << "---------------------------------\n";
	for (std::list<string>::iterator it = spaceBag.begin(); it != spaceBag.end(); it++)
	{
		cout << countItems << ") " << *it << endl;
		countItems++;
	}

	cin >> userStringInput;


	while (userStringInput != "1" && userStringInput != "2" && userStringInput != "3")
	{
		cout << "Sorry that is not a valid response. Please enter 1, 2, or 3." << endl;

		cin >> userStringInput;
	}

	int userIntInput = stoi(userStringInput);

	int itemToFind = userIntInput - 1;
	int itemCounter = 0;
	string itemToRemove;

	for (std::list<string>::iterator i = spaceBag.begin(); i != spaceBag.end(); i++)
	{
		if (itemCounter == itemToFind)
			itemToRemove = *i;

		itemCounter++;
	}

	spaceBag.remove(itemToRemove);

	cout << endl;
}