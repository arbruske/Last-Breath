/**********************************************************************
*                          Player Class
* This class represents Major Tom (or the character the user plays 
* the game with. The class contains 3 private member variables:
* (1) playerLocation (a pointer to Space, which tracks the location
* of the player and what room they are currently in),
* (2) breaths (amount of breaths the player has until they run out of
* breaths and die - or the game ends)
* (3) spaceBag (a list container which contains the items that the
* player collects throughout the game)
* The class contains various setters and getters for the data
* members as well as a bool function that determines if the player
* has run out of breaths and thus has died - isHeDead(). Other
* functions include searchSpaceBag() (which searches the player's
* space bag for an item), inserItem() (inserts an item to the player's
* space bag, and removeItem() (which removes an item from the player's
* space bag.
***********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"

#include <list>

class Player
{
	private:
		Space *playerLocation;
		int breaths;
		std::list<std::string> spaceBag;

	public:
		Player();
		void setBreaths(int);
		int getBreaths();
		bool isHeDead();
		void setPlayerLocation(Space*);
		Space *getPlayerLocation();
		int getSpaceBagSize();
		bool searchSpaceBag(std::string);
		void insertItem(std::string);
		void removeItem();
};
#endif
