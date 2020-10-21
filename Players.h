// Scott Enzinna

#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include "Dealer.h"

class Players : public Dealer
{
public:
	Players();
	int Hand[10];
	int cards;
	int PStand;
	~Players();

private:
	int total;
	int balance;
};
#endif