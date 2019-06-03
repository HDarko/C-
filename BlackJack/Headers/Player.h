#pragma once
#include "GenericPlayer.h"
class Player :
	public GenericPlayer
{
public:
	Player( std::string name="Player");
    
	 bool isHitting() override;

	 void Win() const;

	 void Lose() const;

	 void Push() const;


};

