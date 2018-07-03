/*********************************************************************
*						   Space Class
* This is an abstract class which contains 4 pointers to Space to keep
* track of the directions within the derived Spaces (or rooms). It also
* contains a data member called roomName which allows the naming of a
* room. It contains two bool variables called itemObtained and 
* wasRoomSearched, which keep track of whether the room was searched 
* or the item was obtained from the room. The class contains various
* functions.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Space
{
	protected:
		Space *up;
		Space *down;
		Space *right;
		Space *left;

		std::string roomName;

		bool itemObtained;
		bool wasRoomSearched;

	public:
		Space(std::string);
		virtual void settingInfo() = 0;
		virtual int roomMenu() = 0;
		std::string getRoomName();
		Space *getUp();
		Space *getDown();
		Space *getRight();
		Space *getLeft();
		void setNextRoom(char, Space*);
		void setWasRoomSearched();
		int getWasRoomSearched();
		void setWasItemObtained();
		int getWasItemObtained();
};
#endif
