#include "Hand.h"
#include "Card.h"
#include <memory>
#include<vector>


std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	std::vector<std::unique_ptr<Card>>::const_iterator pCard;
	if (!hand.m_Cards.empty())
	{
		for (pCard = hand.m_Cards.begin(); pCard != hand.m_Cards.end(); ++pCard)
		{
			os <<"\n"<< *(*pCard) << "\t";
		}
	}

}

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	//if the hand is empyt then 
	if (m_Cards.empty())
	{
		return 0;
	}
	//if first card is facing down then 
	//dont find total yet
	if (m_Cards[0]->isFacingDown())
	{
		return 0;
	}
	//add up the values treating any aces as one and counting them
	int numAces{ 0 };
	int sum{ 0 };
	std::vector<std::unique_ptr<Card>>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->getRank() == Rank::ACE)
		{
			numAces++;
		}
		sum += (*iter)->getValue();
	}

	if (numAces)
	{
		if (((numAces * 10) + sum) <= 21)
		{
			return ((numAces * 10) + sum);
		}
		else
		{
			return sum;
		}
	}
};

void Hand::Add(std::unique_ptr<Card>pCard)
{
	m_Cards.push_back(pCard);
}

