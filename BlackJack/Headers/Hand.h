#pragma once
#include "Card.h"
#include <memory>
#include<vector>
#include<iostream>
//A Hand is a collection of Cards.
//It should know its current mimimal value(based on Aces), 

struct Hand
{

public:
	Hand();
	~Hand();
	//adds a card to the Hand
	void Add(std::unique_ptr<Card>pCard);
	//clear hand of all cards
	void Clear();
	//get hand total value, Aces can be 1 or 11
	int GetTotal() const;

	std::vector<std::unique_ptr<Card>> m_Cards;
	friend std::ostream& operator<<(std::ostream& os, const Hand& hand);


	
};

