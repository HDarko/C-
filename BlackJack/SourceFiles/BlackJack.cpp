// BlackJack.cpp : 
/*

Simplified Implementation of BlackJack.
-Only one hand per player.The code can be extended
to allow for spliting hands.

*/

#include <iostream>
#include "Game.h"
#include"Card.h"
#include"Dealer.h"
#include"Deck.h"
#include"GenericPlayer.h"
#include"Hand.h"
#include"Player.h"


	//Simple Blackjack in steps
	//Shuffle Deck
	//Hand out the cards to each
	//play a round 
	//next round (Y/N)


int main()
{
    std::cout << "\t\tWelcome to BlackJack!\n"; 
	int numofPlayers{ 0 };
	std::cout << "\nHow many players for this round(1-7)\n";
	std::cin >> numofPlayers;

	std::vector<std::string> names;
	std::string name;
	for (int i = 0; i < numofPlayers; ++i)
	{
		std::cout << "Enter the name for Player " << i << "\n";
		std::cin >> name;
		names.push_back(name);
	}
	
	Game game{ names };
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		game.play();
		std::cout << "/nDo you want to play again(Y/N): ";
		std::cin >> again;
		
	}

	return 0;

}

