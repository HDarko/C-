#pragma once
#include "GenericPlayer.h"
class Dealer :
	public GenericPlayer
{
public:
	Dealer( std::string name="Dealer");

	bool isHitting() override;

	void FlipFirstCard();

};

