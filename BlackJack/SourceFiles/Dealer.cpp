#include "Dealer.h"



Dealer::Dealer(std::string name)
	:GenericPlayer{name}
{
}




bool Dealer::isHitting()
{
	return (m_Hand->GetTotal() <= 17);
}

void Dealer::FlipFirstCard()
{
	if (!(m_Hand->m_Cards.empty()))
	{
		m_Hand->m_Cards[0]->flipCard();
	}

	else
	{
		std::cout << "No cards to flip!\n";
	}
}

