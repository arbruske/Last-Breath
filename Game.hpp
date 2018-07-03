#ifndef GAME_HPP
#define GAME_HPP

/***************************************************************************
*                             Game Class
* This class represents the game and allows the game to be played. It
* contains 9 data members:
* (1) Space *commandRoom (pointer to Space)
* (2) Space *lounge (pointer to Space)
* (3) Space *quarterDeck (pointer to Space)
* (4) Space *sickBay (pointer to Space)
* (5) Space *oxygenRoom (pointer to Space)
* (6) Space *bathroom (pointer to Space)
* (7) Player tom (Player object)
* (8) bool oxygenCodeObtained (tracks if oxygen code was obtained or not)
* (9) bool oxygenReleased (tracks if oxygen was released or not)
* The class contains a constructor as well as 7 functions, which allows the
* game to be played.
****************************************************************************/

#include "Player.hpp"
#include "Bathroom.hpp"
#include "CommandRoom.hpp"
#include "Lounge.hpp"
#include "QuarterDeck.hpp"
#include "SickBay.hpp"
#include "OxygenRoom.hpp"
#include "Space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Game
{
	private:
		Space *commandRoom;
		Space *lounge;
		Space *quarterDeck;
		Space *sickBay;
		Space *oxygenRoom;
		Space *bathroom;

		Player tom;

		bool oxygenCodeObtained;
		bool oxygenReleased;


	public:
		//used to give Player's inventory (or spaceBag) a max size limit
		const int maxInventorySize = 3;

		Game();
		void playGame();
		void searchCommandRoom();
		void searchLounge();		
		void searchQuarterDeck();		
		void searchBathroom();
		void searchSickBay();
		void searchOxygenRoom();
};
#endif
