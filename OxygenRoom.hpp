/********************************************************************
*                          OxygenRoom Class
* This is a derived class from Space and it represents the oxygen room
* on the spaceship. It contains a constructor, which gives assigns
* the name to the room, and two functions: (1) settingInfo() which
* outputs information about the environment of the room and (2)
* roomMenu (which is the menu for the room which allows the player
* to choose from various options)
********************************************************************/

#ifndef OXYGENROOM_HPP
#define OXYGENROOM_HPP

#include "Space.hpp"

class OxygenRoom : public Space
{
	public:
		OxygenRoom(std::string roomN) : Space(roomN) {};
		//~OxygenRoom() {};
		void settingInfo();
		int roomMenu();
};
#endif
