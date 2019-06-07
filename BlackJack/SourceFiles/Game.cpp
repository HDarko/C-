#include "Game.h"
#include<ctime>



Game::Game(const std::vector<std::string>& names)
{
	//create a vector of players from names
	std::vector<std::string>::iterator pName;
	for (auto pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(Player{ *pName });

	}
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}


Game::~Game()
{
	m_Players.clear();
}

void Game::play()
{
	//Deal initial 2 cards to everyone
	std::vector<Player>::iterator pPlayer;

	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			std::cout << (*pPlayer).getName()<< " gets 2 cards\n";
			for (int i = 0; i < 2; ++i)
			{
				m_Deck.Deal((*pPlayer).m_Hand);
			}
			//auto hand = (*pPlayer)->m_Hand;
			
		}
		std::cout << "\nDealer gets 2 cards\n";
		m_Deck.Deal((m_Dealer).m_Hand);
		m_Deck.Deal((m_Dealer).m_Hand);
	}

	
	//Hide dealer's first card
	m_Dealer.FlipFirstCard();
	//display everyones hand
	std::cout << "\nRound start:\nDealer has:\n";
	std::cout << *((m_Dealer).m_Hand);
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		std::cout <<"\n"<<pPlayer->getName() << " has:\n"<<
			*((*pPlayer).m_Hand) <<"\n";

	}
	//Everyone should play their round
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		playRound(*pPlayer);

	}
	//Reveal Dealer's first card and play Dealer round
	m_Dealer.FlipFirstCard();
	std::cout << "\nThe Dealer has:\n";
	std::cout << *(m_Dealer.m_Hand);
	playRound(m_Dealer);

	checkWinner();



}

void Game::playRound(Player& player)
{
	while (player.isHitting())
	{
		m_Deck.Deal(player.m_Hand);
		std::cout <<"\nCurrent Hand:\n "<< *(player.m_Hand);
		std::cout << "\nWith a current value of " << player.m_Hand->GetTotal()<<"\n";
		if (player.isBusted())
		{
			player.Burst();
			break;
		}
	}
}

void Game::playRound(Dealer& dealer)
{
	while (dealer.isHitting())
	{
		m_Deck.Deal(dealer.m_Hand);
		std::cout <<"\n"<< *(dealer.m_Hand);
	}
}

void Game::checkWinner()
{
	int hScore{ 0 };
	std::string winner = "";
	for (auto pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		if (!(pPlayer->isBusted()))
		{
			if (pPlayer->m_Hand->GetTotal() > hScore)
			{
				hScore = pPlayer->m_Hand->GetTotal();
				winner = pPlayer->getName();
			}
		}

		if (m_Dealer.m_Hand->GetTotal() > hScore)
		{
			hScore = m_Dealer.m_Hand->GetTotal();
			winner = "Dealer";
		}
	}

	std::cout << "\nThe winner is " << winner << "\nFinal score: " << hScore<<"\n";

}
