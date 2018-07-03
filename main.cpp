/*************************************************************************************
** Program: Final Project - Last Breath
** Author: Aleksander Bruske
** Date: 6/09/2017
** Description: This program allows a user to play a game where they must search
** various rooms and collect items in order to find the final object, which will
** unable them to win the game. They must find the object (oxygenCode) and bring it
** to the oxygen room and release the oxygen before they run out of "breaths". The
** program contains 9 classes: Space class (This class represents a "space" or room
** on the spaceship. It contains data members and functions that define the room. It
** is a parent class to 6 classes: (1) Bathroom (represents a bathroom and contains
** it's own unique menu and setting information, (2) CommandRoom (represents the
** command room on the ship and also contains its own unique menu and setting info),
** (3) Lounge (represents the lounge on the ship and also contains its own menu and
** setting info), (4) OxygenRoom (represents the oxygen control room on the ship where
** the player must bring the code to win the game, also containing its own unique menu
** and setting info), (5) QuarterDeck (represents the quarters where the crewmen sleep
** and also contains its own menu and setting info), (6) SickBay (represents the sick
** bay on the ship and also contains its own menu and setting info). The program also
** contains a Player class, which contains a has-a relationship with Space since it
** contains a pointer to a Space called playerLocation, which tracks the player's 
** location. The class represents the character that the player controls and he contains
** a number of breaths (until he dies) and a space bag to carry items in. The program
** also contains a Game class which reprsents the game to be played and contains 6
** pointers to Spaces (for the 6 rooms) and a Player object "tom". It contains various
** functions which allow the user to play the game.
*************************************************************************************/

#include <iostream>
#include <iomanip>
#include "Game.hpp"

using std::cout;
using std::cin;

int main()
{
	string stringUserInput;
	int intUserInput;

	do {
		
		cout << "***************************************************************\n";
		cout << "                         LAST BREATH\n";
		cout << "                          MAIN MENU\n" << endl;

		cout << "PRESS 1 TO PLAY\n";
		cout << "PRESS 2 TO EXIT\n";
		cout << "**************************************************************\n";

		cin >> stringUserInput;
		cin.ignore();

		while (stringUserInput != "1" && stringUserInput != "2")
		{
			cout << "Sorry, that is not a valid number. Please enter a valid number (1 - play, 2 - exit)!" << endl;

			cin >> stringUserInput;
			cin.ignore();
		}

		intUserInput = stoi(stringUserInput);

		if (intUserInput == 1)
		{
			Game myGame;

			cout << "Ground Control: This is Ground control to Major Tom! It seems that your\n";
			cout << "spaceship's oxygen control has malfunctioned. Unfortunately, it seems that\n";
			cout << "all your crew have perished but for some reason you are still alive.\n" << endl;

			cout << "Android: Beep bob beep - I love you Major Tom...\n" << endl;

			cout << "Ground Control: My god, Major Tom! It seems that your android has saved\n"; 
			cout << "your life by giving you an oxygen mask. However, it will not last forever.\n";
			cout << "You must turn the oxygen back on! Quickly!\n" << endl;

			cout << "Major Tom: This is Major Tom to Ground Control. I will turn on the oxygen\n";
			cout << " but if I don't.. tell my wife I love her very much, she knows...\n" << endl;

			cout << "Ground Control: Ground Control to Major Tom! Your circuit's dead.\n"; 
			cout << "There's something wrong. Can you hear me Major Tom?\n" << endl; 

			cout << endl;
			cout << endl;

			myGame.playGame();

		}
		if (intUserInput == 2)
		{
			intUserInput = 1992;
		}

	} while (intUserInput != 1992);

	return 0;
}
