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

void playBlackJack()
{
	//Shuffle Deck
	//Hand out the cards to each
	//play a round 
	//next round
	//next round
}

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
