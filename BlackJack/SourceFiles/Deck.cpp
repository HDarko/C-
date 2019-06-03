#include "Deck.h"
#include<algorithm>



Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{
	m_Cards.clear();
}

void Deck::Populate()
{
	Clear();

	for (Suit s : SUITS)
	{
		for (Rank r : RANKS)
		{

			Add(std::make_unique<Card>(Card(r, s)));
		}

	}
}

void Deck::Shuffle()
{
	std::random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(std::unique_ptr<Hand>& hand)
{
	if (!m_Cards.empty())
	{
		hand->Add(std::move(m_Cards.back()));
		m_Cards.pop_back();
	}
	else
	{
		std::cout << "Out of cards.  Unable to deal.";
	}
}
