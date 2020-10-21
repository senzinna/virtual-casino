// Scott Enzinna

#ifndef DEALER_H
#define DEALER_H

#include <iostream>

class Dealer
{
public:
	Dealer();
	virtual int getTotal(int[]);
	virtual char getFaceValue(int);
	int Hand[10];
	~Dealer();

private:
	int total;
};
#endif