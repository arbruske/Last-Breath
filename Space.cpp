#include "Space.hpp"

Space::Space(std::string name)
{
	roomName = name;
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;

	itemObtained = false;
	wasRoomSearched = false;
}

std::string Space::getRoomName()
{
	return roomName;
}

Space* Space::getUp()
{
	return up;
}
Space* Space::getDown()
{
	return down;
}
Space* Space::getRight()
{
	return right;
}
Space* Space::getLeft()
{
	return left;
}
void Space::setNextRoom(char d, Space* r)
{
	if (d == 'U')
	{
		this->up = r;
	}
	else if (d == 'D')
	{
		this->down = r;
	}
	else if (d == 'R')
	{
		this->right = r;
	}
	else if (d == 'L')
	{
		this->left = r;
	}
}

void Space::setWasRoomSearched()
{
	wasRoomSearched = true;
}

int Space::getWasRoomSearched()
{
	return wasRoomSearched;
}

void Space::setWasItemObtained()
{
	itemObtained = true;
}

int Space::getWasItemObtained()
{
	return itemObtained;
}