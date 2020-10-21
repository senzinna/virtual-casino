// Scott Enzinna

#ifndef USER_H
#define USER_H
#include "Dealer.h"
#include "Players.h"

class User : public Dealer
{
public:
	User();
	int UserHand;
	int UStand;
	int win;
	~User();

private:
	int balance;
};
#endif