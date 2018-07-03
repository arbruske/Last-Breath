/**********************************************************************
*                          CommandRoom Class
* This is a derived class from Space and it represents the command
* room on the spaceship. It contains a constructor, which gives assigns
* the name to the room, and two functions: (1) settingInfo() which
* outputs information about the environment of the room and (2)
* roomMenu (which is the menu for the room which allows the player
* to choose from various options)
**********************************************************************/

#ifndef COMMANDROOM_HPP
#define COMMANDROOM_HPP

#include "Space.hpp"

class CommandRoom : public Space
{
	public:
		CommandRoom(std::string roomN) : Space(roomN) {};
		//~CommandRoom() {};
		void settingInfo();
		int roomMenu();
};
#endif
