// Scott Enzinna

#ifndef DECK_H
#define DECK_H
#include <iostream>
using namespace std;

class Deck
{
public:
	int totalFaces;
	Deck();
	int getFace() const
	{
		return cardFace;
	}
	int face[52];

private:
	int cardFace;
};
#endif