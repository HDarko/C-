#pragma once
#include"Card.h"
#include"Dealer.h"
#include"Deck.h"
#include"GenericPlayer.h"
#include"Hand.h"
#include"Player.h"
#include<vector>
#include<string>
class Game
{
public:
	Game(const std::vector<std::string>& names);
	~Game();
	void play();
	void playRound(Player& player);
	void playRound(Dealer& dealer);
	void checkWinner();
private:
	Deck m_Deck;
	Dealer m_Dealer;
	std::vector<Player> m_Players;
};

