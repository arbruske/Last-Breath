#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************************************
*                                Game::Game() 
* This constructor sets the two bool variables (oxygenCodeObtained and oxygenReleased)
* to false. It also points each of the Space pointers to the new 6 different Space
* rooms as well setting their adjoining room locations. It finally sets the player's
* starting location to the command room.
***************************************************************************************/

Game::Game()
{
	oxygenCodeObtained = false;
	oxygenReleased = false;

	commandRoom = new CommandRoom("Command Room");
	lounge = new Lounge("Lounge");
	quarterDeck = new QuarterDeck("Quarter Deck");
	sickBay = new SickBay("Sick Bay");
	oxygenRoom = new OxygenRoom("Oxygen Room");
	bathroom = new Bathroom("Bathroom");

	//Set adjoining room directions
	commandRoom->setNextRoom('R', lounge);
	lounge->setNextRoom('R', bathroom);
	lounge->setNextRoom('L', commandRoom);
	lounge->setNextRoom('U', oxygenRoom);
	lounge->setNextRoom('D', quarterDeck);
	quarterDeck->setNextRoom('U', lounge);
	quarterDeck->setNextRoom('R', sickBay);
	bathroom->setNextRoom('L', lounge);
	sickBay->setNextRoom('L', quarterDeck);
	oxygenRoom->setNextRoom('D', lounge);

	//set player's starting location to the command room
	tom.setPlayerLocation(commandRoom);
}

/********************************************************************************
*                         void Game::playGame()
* This function plays the game. WWithin a do while loop itt first outputs the 
* player's current room's setting information then outputs that rooms menu.
* It then uses a series of if then statements to determine what room the player
* is currently in and therefore enacts the correct actions that happened from
* the player's choice in the room's menu. The player's amount of breaths are
* then subtracted by 1 and if the player's breaths reaches a certain point a
* message will be outputted to the screen essentially warning and reminding the 
* player that their breaths are declining. This while loop iterates until the
* player has successfully released the oxygen, thus winning the game, runs out of
* breath therefore losing the game, or until the player decides to quit the game.
* When the do while loop has finished iterating, the win/lose details will
* be outputted to the screen then the pointers will be deleted to de-allocate
* memory.
********************************************************************************/

void Game::playGame()
{
	string roomName;
	bool userQuit = false;

	do {
		int userChoice;

		tom.getPlayerLocation()->settingInfo();

		cout << endl;

		userChoice = tom.getPlayerLocation()->roomMenu();

		if (tom.getPlayerLocation()->getRoomName() == "Command Room")
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getRight());
			}
			else if (userChoice == 2)
			{
				searchCommandRoom();
			}
			else
			{
				userQuit = true;
			}
		}
		else if (tom.getPlayerLocation()->getRoomName() == "Lounge")
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getRight());
			}
			else if (userChoice == 2)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getLeft());
			}
			else if (userChoice == 3)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getUp());
			}
			else if (userChoice == 4)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getDown());
			}
			else if (userChoice == 5)
			{
				searchLounge();
			}
			else
			{
				userQuit = true;
			}
		}
		else if (tom.getPlayerLocation()->getRoomName() == "Quarter Deck")
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getRight());
			}
			else if (userChoice == 2)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getUp());
			}
			else if (userChoice == 3)
			{
				searchQuarterDeck();
			}
			else
			{
				userQuit = true;
			}
		}
		else if (tom.getPlayerLocation()->getRoomName() == "Sick Bay")
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getLeft());
			}
			else if (userChoice == 2)
			{
				searchSickBay();
			}
			else
			{
				userQuit = true;
			}
		}
		else if (tom.getPlayerLocation()->getRoomName() == "Bathroom")
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getLeft());
			}
			else if (userChoice == 2)
			{
				searchBathroom();
			}
			else
			{
				userQuit = true;
			}
		}
		else
		{
			if (userChoice == 1)
			{
				tom.setPlayerLocation(tom.getPlayerLocation()->getDown());
			}
			else if (userChoice == 2)
			{
				searchOxygenRoom();
			}
			else
			{
				userQuit = true;
			}
		}

		if (!oxygenReleased)
		{
			tom.setBreaths(tom.getBreaths() - 1);
		}

		cout << endl;

		if (tom.getBreaths() == 15 && userQuit == false)
		{
			cout << "Android: beep boop bob..Major Tom you only have 15 breaths remaining. Hurry sir!\n" << endl;

			cout << "Major Tom: I know Android! I'm trying!\n" << endl;
		}
		else if (tom.getBreaths() == 10 && userQuit == false)
		{
			cout << "Android: BEEP bop BEEP..Major Tom you only have 10 breaths remaining. You must really hurry!!!\n" << endl;

			cout << "Major Tom: Keep calm Android! I got this.\n" << endl;
		}
		else if (tom.getBreaths() == 5 && userQuit == false)
		{
			cout << "Android: BEEP BEEP BEEP..Major Tom you only have 5 breaths remaining!! Hurry sir! The lives of hundreds depend on you!\n" << endl;

			cout << "Major Tom: It is getting harder to breathe...but I must persist!\n" << endl;
		}
		else if (tom.getBreaths() == 0 && userQuit == false)
		{
			cout << "Android: Noooooooooooo Major Tom!\n" << endl;
		}
		else if (!oxygenReleased && userQuit == false)
		{
			cout << "Android: You have " << tom.getBreaths() << " breaths remaining.\n" << endl;
		}

	} while (tom.isHeDead() == false && oxygenReleased == false && userQuit == false);

	if (oxygenReleased)
	{
		cout << "*********************************************\n";
		cout << "                  You Won!                   \n";
		cout << "---------------------------------------------\n";
		cout << "Because Major Tom has lived, vital supplies  \n";
		cout << "aboard U.S.S. Hopeful Heritage are able to   \n";
		cout << "to be transported to mankind's first Mars    \n";
		cout << "colony Black Star, saving hundreds of lives. \n";
		cout << "*********************************************\n";
	}
	else if (!oxygenReleased && userQuit == false)
	{
		cout << "*********************************************\n";
		cout << "                  You Lose                   \n";
		cout << "---------------------------------------------\n";
		cout << "Because of Major Tom's death, U.S.S. Hopeful \n";
		cout << "Heritage will be unable to transport vital   \n";
		cout << "supplies to the Mars colony Black Star.      \n";
		cout << "Consequently, hundreds of lives will perish  \n";
		cout << "and mankind's efforts to explore space will  \n";
		cout << "be setback by decades.                       \n";
		cout << "*********************************************\n";
	}
	
	tom.setPlayerLocation(NULL);
	delete tom.getPlayerLocation();
	delete commandRoom;
	delete lounge;
	delete quarterDeck;
	delete sickBay;
	delete oxygenRoom;
	delete bathroom;
}

void Game::searchCommandRoom()
{
	if (tom.getPlayerLocation()->getWasRoomSearched() == 0 && !tom.searchSpaceBag("Titanium Key"))
	{
		cout << "After checking the room, you find a titanium chest that is locked.\n" << endl;

		cout << "Major Tom: Hmm where did that key go? I better head to other rooms to find it.\n" << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You return to the shiny titanium chest, which needs the Titanium Key to open." << endl;
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 0 && tom.searchSpaceBag("Titanium Key"))
	{
		cout << "You find the Titanium chest and you have the key to open it!\n" << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (oxygenCodeObtained)
	{
		cout << "You have the passcode! Why are you wasting time searching this room? Go to the Oxygen Room!\n" << endl;
	}

	if (tom.searchSpaceBag("Titanium Key") && !oxygenCodeObtained)
	{
		cout << "You take the Titanium Key and open the chest. Inside you find the password that will turn the oxygen back on!" << endl;

		if (tom.getSpaceBagSize() == maxInventorySize)
		{
			string stringUserInput;

			cout << "Your space bag is full. Remove an item to make space? Y/N. I highly recommend Y if you like to breath and all." << endl;

			cin >> stringUserInput;

			while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
			{
				std::cout << "Sorry that is not a valid response. Please enter 'Y' to remove an item or 'N' to not remove an item." << std::endl;

				std::cin >> stringUserInput;
			}

			if (stringUserInput == "Y" || stringUserInput == "y")
			{
				tom.removeItem();

				cout << "You have removed an item from your space bag and quickly grab the password!" << endl;

				tom.insertItem("Password");

				oxygenCodeObtained = true;
				tom.getPlayerLocation()->setWasItemObtained();

				cout << "You have received the password.\n" << endl;

				cout << "Major Tom: Wow the password is my name! How could I forget that! I must be losing my rockers, too!" << endl;
			}
		}
		else
		{
			tom.insertItem("Password");

			oxygenCodeObtained = true;
			tom.getPlayerLocation()->setWasItemObtained();

			cout << "You have received the password.\n" << endl;

			cout << "Major Tom: Wow the password is my name! How could I forget that! I must be losing my rockers, too!\n" << endl;
		}
	}

}

void Game::searchLounge()
{
	string stringUserInput;

	if (tom.getPlayerLocation()->getWasRoomSearched() == 0)
	{
		cout << "After checking the room, you find a note in one of the desks." << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You have searched this area very well already and do not find anything new." << endl;
	}
	else if (oxygenCodeObtained)
	{
		cout << "You have the passcode! Why are you wasting time searching this room? Go to the Oxygen Room!\n" << endl;
	}

	if (tom.getPlayerLocation()->getWasItemObtained() == 0)
	{
		cout << "Do you want to take the note and inspect it? Y/N\n" << endl;

		cin >> stringUserInput;

		while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
		{
			cout << "Sorry that is not a valid response. Please enter 'Y' to obtain the note or 'N' to not take the note.\n" << std::endl;

			cin >> stringUserInput;
		}

		if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() != maxInventorySize)
		{
			tom.insertItem("Lounge Note");

			cout << "            Lounge Note:\n";
			cout << "---------------------------------------\n";
			cout << "So the other day I'm pretty sure I saw \n";
			cout << "David take the Titanium Key to his     \n";
			cout << "locker in the quarter deck. Sneaky...  \n";
			cout << "---------------------------------------\n" << endl;

			cout << "Major Tom: Damnit David! I better head to the quarter deck then...\n" << endl;

			tom.getPlayerLocation()->setWasItemObtained();

		}
		else if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() == maxInventorySize)
		{
			cout << "Your space bag is full. Remove an item to make space? Y/N." << endl;

			cin >> stringUserInput;

			while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
			{
				std::cout << "Sorry that is not a valid response. Please enter 'Y' to remove an item or 'N' to not remove an item." << std::endl;

				std::cin >> stringUserInput;
			}

			if (stringUserInput == "Y" || stringUserInput == "y")
			{
				tom.removeItem();

				cout << "You have removed an item from your space bag and pick up the note!\n" << endl;

				tom.insertItem("Lounge Note");

				cout << "            Lounge Note:\n";
				cout << "---------------------------------------\n";
				cout << "So the other day I'm pretty sure I saw \n";
				cout << "David take the Titanium Key to his     \n";
				cout << "locker in the quarter deck. Sneaky...  \n";
				cout << "---------------------------------------\n" << endl;

				cout << "Major Tom: Damnit David! I better head to the quarter deck then...\n" << endl;

				tom.getPlayerLocation()->setWasItemObtained();
			}
		}
	}
}

void Game::searchQuarterDeck()
{
	string stringUserInput;

	if (tom.getPlayerLocation()->getWasRoomSearched() == 0)
	{
		cout << "After checking the deck, you find a note in David's locker." << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You have searched this area very well already and do not find anything new." << endl;
	}
	else if (oxygenCodeObtained)
	{
		cout << "You have the passcode! Why are you wasting time searching this room? Go to the Oxygen Room!\n" << endl;
	}

	if (tom.getPlayerLocation()->getWasItemObtained() == 0)
	{
		cout << "Do you want to take the note and inspect it? Y/N\n" << endl;

		cin >> stringUserInput;

		while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
		{
			cout << "Sorry that is not a valid response. Please enter 'Y' to obtain the note or 'N' to not take the note.\n" << std::endl;

			cin >> stringUserInput;
		}

		if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() != maxInventorySize)
		{
			tom.insertItem("David's Note");

			cout << "               David's Note:\n";
			cout << "-----------------------------------------\n";
			cout << "Dear Diary,                              \n";
			cout << "Today is the day I found the Titanium    \n";
			cout << "Key! I'm going to hide it in the bathroom\n";
			cout << "in that old cabinent that I'm sure none  \n";
			cout << "of the fools use!                        \n";
			cout << "They'll never find it, my precious!      \n";
			cout << "-----------------------------------------\n" << endl;

			cout << "Major Tom: This man has lost his mind! Well I better go to the bathroom...\n" << endl;

			tom.getPlayerLocation()->setWasItemObtained();

		}
		else if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() == maxInventorySize)
		{
			cout << "Your space bag is full. Remove an item to make space? Y/N." << endl;

			cin >> stringUserInput;

			while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
			{
				std::cout << "Sorry that is not a valid response. Please enter 'Y' to remove an item or 'N' to not remove an item." << std::endl;

				std::cin >> stringUserInput;
			}

			if (stringUserInput == "Y" || stringUserInput == "y")
			{
				tom.removeItem();

				cout << "You have removed an item from your space bag and pick up the note!\n" << endl;

				tom.insertItem("David's Note");

				cout << "               David's Note:\n";
				cout << "-----------------------------------------\n";
				cout << "Dear Diary,                              \n";
				cout << "Today is the day I found the Titanium    \n";
				cout << "Key! I'm going to hide it in the bathroom\n";
				cout << "in that old cabinent that I'm sure none  \n";
				cout << "of the fools use!                        \n";
				cout << "They'll never find it, my precious!      \n";
				cout << "-----------------------------------------\n" << endl;

				cout << "Major Tom: This man has lost his mind! Well I better go to the bathroom...\n" << endl;

				tom.getPlayerLocation()->setWasItemObtained();
			}
		}
	}
}

void Game::searchBathroom()
{
	string stringUserInput;

	if (tom.getPlayerLocation()->getWasRoomSearched() == 0)
	{
		cout << "After searching the bathroom, you find a note an old cabinent no one really used much." << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You have searched this area very well already and do not find anything new." << endl;
	}
	else if (oxygenCodeObtained)
	{
		cout << "You have the passcode! Why are you wasting time searching this room? Go to the Oxygen Room!\n" << endl;
	}

	if (tom.getPlayerLocation()->getWasItemObtained() == 0)
	{
		cout << "Do you want to take the note and inspect it? Y/N\n" << endl;

		cin >> stringUserInput;

		while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
		{
			cout << "Sorry that is not a valid response. Please enter 'Y' to obtain the note or 'N' to not take the note.\n" << std::endl;

			cin >> stringUserInput;
		}

		if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() != maxInventorySize)
		{
			tom.insertItem("Dr. Bowie's Note");

			cout << "             Dr. Bowie's Note:\n";
			cout << "-----------------------------------------\n";
			cout << "Haha! I found this key here. I'm going to\n";
			cout << "put it in my desk then give it to Major  \n";
			cout << "Tom tomorrow. Why not just give it to him\n";
			cout << "now? Why even leave this note here and   \n";
			cout << "risk David finding the key again? I don't\n";
			cout << "know. Perhaps I'm losing my mind from    \n";
			cout << "being in space for so long.              \n";
			cout << "-----------------------------------------\n" << endl;

			cout << "Major Tom: You fool! Why didn't you just give it to me right away? Everyone went crazy.\n";
			cout << "           Well I better head to the sick bay...\n" << endl;

			tom.getPlayerLocation()->setWasItemObtained();

		}
		else if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() == maxInventorySize)
		{
			cout << "Your space bag is full. Remove an item to make space? Y/N." << endl;

			cin >> stringUserInput;

			while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
			{
				std::cout << "Sorry that is not a valid response. Please enter 'Y' to remove an item or 'N' to not remove an item." << std::endl;

				std::cin >> stringUserInput;
			}

			if (stringUserInput == "Y" || stringUserInput == "y")
			{
				tom.removeItem();

				cout << "You have removed an item from your space bag and pick up the note!\n" << endl;

				tom.insertItem("Dr. Bowie's Note");

				cout << "             Dr. Bowie's Note:\n";
				cout << "-----------------------------------------\n";
				cout << "Haha! I found this key here. I'm going to\n";
				cout << "put it in my desk then give it to Major  \n";
				cout << "Tom tomorrow. Why not just give it to him\n";
				cout << "now? Why even leave this note here and   \n";
				cout << "risk David finding the key again? I don't\n";
				cout << "know. Perhaps I'm losing my mind from    \n";
				cout << "being in space for so long.              \n";
				cout << "-----------------------------------------\n" << endl;

				cout << "Major Tom: You fool! Why didn't you just give it to me right away? Everyone was going crazy.\n";
				cout << "           Well I better hurry and head to the sick bay...\n" << endl;

				tom.getPlayerLocation()->setWasItemObtained();
			}
		}
	}
}

void Game::searchSickBay()
{
	string stringUserInput;

	if (tom.getPlayerLocation()->getWasRoomSearched() == 0)
	{
		cout << "After searching the sick bay, you find the Titanium Key in Dr. Bowie's desk." << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You have searched this area very well already and do not find anything new." << endl;
	}
	else if (oxygenCodeObtained)
	{
		cout << "You have the passcode! Why are you wasting time searching this room? Go to the Oxygen Room!\n" << endl;
	}

	if (tom.getPlayerLocation()->getWasItemObtained() == 0)
	{
		cout << "Do you want to take the key? Y/N\n" << endl;

		cin >> stringUserInput;

		while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
		{
			cout << "Sorry that is not a valid response. Please enter 'Y' to obtain the note or 'N' to not take the note.\n" << std::endl;

			cin >> stringUserInput;
		}

		if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() != maxInventorySize)
		{
			tom.insertItem("Titanium Key");

			cout << "You have received the Titanium Key!\n" << endl;

			tom.getPlayerLocation()->setWasItemObtained();

		}
		else if ((stringUserInput == "Y" || stringUserInput == "y") && tom.getSpaceBagSize() == maxInventorySize)
		{
			cout << "Your space bag is full. Remove an item to make space? Y/N." << endl;

			cin >> stringUserInput;

			while (stringUserInput != "y" && stringUserInput != "Y" && stringUserInput != "N" && stringUserInput != "n")
			{
				std::cout << "Sorry that is not a valid response. Please enter 'Y' to remove an item or 'N' to not remove an item." << std::endl;

				std::cin >> stringUserInput;
			}

			if (stringUserInput == "Y" || stringUserInput == "y")
			{
				tom.removeItem();

				cout << "You have removed an item from your space bag and quickly pick up the Titanium Key!\n" << endl;

				tom.insertItem("Titanium Key");

				tom.getPlayerLocation()->setWasItemObtained();
			}
		}
	}
}

void Game::searchOxygenRoom()
{
	string stringUserInput;

	if (tom.getPlayerLocation()->getWasRoomSearched() == 0)
	{
		cout << "After searching the oxygen room, you find the terminal that prompts for the password to release oxygen.\n" << endl;
		tom.getPlayerLocation()->setWasRoomSearched();
	}
	else if (tom.getPlayerLocation()->getWasRoomSearched() == 1 && !oxygenCodeObtained)
	{
		cout << "You have searched this area very well already and do not find anything new. The terminal still awaits the passcode..." << endl;
	}

	if (oxygenCodeObtained)
	{
		cout << "You enter the password into the terminal and oxygen gets released into the spaceship. Let's go to Mars now.\n" << endl;

		oxygenReleased = true;
	}
}