#pragma once
#include <iostream>
//Declaration of the Card class


enum class Suit
	//Hearts, Clubs, Spades, Diamonds in that order
{
	HEARTS,
	CLUBS,
	SPADES,
	DIAMONDS

};

enum class Rank
{
	//Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten
	//| Jack | Queen | King | Ace
	//We treat ACE as 1 value in class for easier implementation
	ACE=1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,

};
class Card
{
	//The card should know its value and rank, wheter it is flipped down or not,
	//and should be able to output its value
public:
	Rank getRank() const { return m_rank; };
	Suit getSuit() const { return m_suit; };
	bool isFacingDown() const { return m_isDown; };
	//if the Card is FaceDown then the value should be 0 else return the value
	int getValue() const;
	Card(Rank r = Rank::TWO, Suit s = Suit::CLUBS, bool down = false);
	void flipCard();
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
	
private:
	Rank m_rank;
	Suit m_suit;
	bool m_isDown;
	
};
