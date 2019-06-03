#pragma once
#include "Hand.h"
#include <memory>
#include<vector>
#include <string>

class GenericPlayer
{
public:
	GenericPlayer( std::string name);
	//Does the player want to keep on hitting
	virtual bool isHitting() = 0;

	//return if the player has busted
	bool isBusted();

	//return that the player has busted
	void Burst();

	std::string getName();
	std::unique_ptr<Hand> m_Hand;
	

protected:
	
	//after the current hand is used and removed
	//the next hand is returned;


	
	std::string m_Name;


};

