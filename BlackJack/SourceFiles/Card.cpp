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
	 std::string RANKS [14] = { "0","A","2","3","4","5","6",
	"7","8","9","10","J","Q","K" };
	 std::string SUITS [4] = { "H","C","S","D" };
	if (card.m_isDown)
	{
		os << "XX";
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

