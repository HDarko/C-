#include "Card.h"
#include <iostream>
#include<string>


void Card::flipCard()
{
	m_isDown = !m_isDown;
};

Card::Card(Rank r, Suit s, bool isDown)
	:m_rank{ r }, m_suit{ s }, m_isDown{ isDown }
{

};
//Overload the << operator so that we can output a card.

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	 std::string RANKS [14] = { "0","Ace of","2 of","3 of","4 of","5 of","6 of",
	"7 of","8 of","9 of","10 of","Jack of","Queen of","King of" };
	 std::string SUITS [4] = { " Hearts"," Clubs"," Spades"," Diamonds" };
	if (card.m_isDown)
	{
		os << "Unknown Card";
	}
	else
	{
		os << RANKS[static_cast<int>(card.m_rank)] << SUITS[static_cast<int>(card.m_suit)];
	}

	return os;
};

int Card::getValue() const
{
	//If card is faceDown then the value is 0
	if (m_isDown)
	{
		return 0;
	}

	else
	{
	  int x= (static_cast<int>(getRank()));
	  if (x > 10)
	  {
		  return 10;
	  }
	  else
	  {
		  return x;
	  }
	}
};

