// Scott Enzinna

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "Dealer.h"
#include "Players.h"
#include "User.h"

class Blackjack : public Dealer
{
public:
	Blackjack(int, int);
	void shuffle();
	int dealCard(int);
	double gameStatus(int);
	int playGame(int);
	int UserMove(int);
	int DealerMove(int, int);
	void PrintDealer(int[], int);
	void PrintUser(int[], int);
	void PrintPlayer(int[], int);
	int PrintResults(int, int);
	~Blackjack();
	int currentCard;

private:
	int bank;
};
#endif