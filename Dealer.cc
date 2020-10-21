// Scott Enzinna

#include "Dealer.h"

using namespace std;

Dealer::Dealer()
{
}

int Dealer::getTotal(int Hand[])
{
	int sum = 0;
	bool Ace = false;

	for (int a = 0; a < sizeof(Hand); a++)
	{
		if (Hand[a] != 0)
		{
			switch (Hand[a])
			{
			case 2:
				sum += 2;
				break;
			case 3:
				sum += 3;
				break;
			case 4:
				sum += 4;
				break;
			case 5:
				sum += 5;
				break;
			case 6:
				sum += 6;
				break;
			case 7:
				sum += 7;
				break;
			case 8:
				sum += 8;
				break;
			case 9:
				sum += 9;
				break;
			case 10:
			case 11:
			case 12:
			case 13:
				sum += 10;
				break;
			case 14:
				sum += 11;
				Ace = true;
				break;
			default:
				break;
			}
		}
	}
	if (sum > 21 && Ace == true)
	{
		sum = sum - 10;
	}

	return sum;
}

char Dealer::getFaceValue(int card)
{
	switch (card)
	{
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 10:
		return '0';
		break;
	case 11:
		return 'J';
		break;
	case 12:
		return 'Q';
		break;
	case 13:
		return 'K';
		break;
	case 14:
		return 'A';
		break;
	default:
		break;
	}
}
Dealer::~Dealer()
{
}
