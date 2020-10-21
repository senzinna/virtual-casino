// Scott Enzinna

#include "Blackjack.h"
using namespace std;

// typed them in by hand again like last time

int Deck[52] = {
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
};

Blackjack::Blackjack(int balance, int currentCard)
{
}

void Blackjack::shuffle()
{
	for (int a = 0; a < 52; a++)
	{
		int hold;
		int random = (rand() % 52);

		hold = Deck[a];
		Deck[a] = Deck[random];
		Deck[random] = hold;
	}
}
int Blackjack::dealCard(int currentCard)
{
	currentCard++;
	int card;
	card = Deck[currentCard - 1];
	return card;
}

int Blackjack::playGame(int balance)
{
	int bet;
	double win = 0;
	int players;

	cout << "Now playing Blackjack\nHow much would you like to bet \nBetween $5 and $100: ";
	cin >> bet;

	while (bet > 100 || bet < 5 || bet > balance)
	{
		cout << "Wrong, try again: ";
		cin >> bet;
	}

	balance -= bet;

	cout << "How many people, up to five: ";
	cin >> players;

	while (players > 5 || players < 0)
	{
		cout << "Try again: ";
		cin >> players;
	}

	win = gameStatus(players);

	balance += (win * bet);
	system("PAUSE");
	system("clear");

	return balance;
}

double Blackjack::gameStatus(int players)
{

	int DStand = 0;
	int currentCard = 0;
	int split = 1;
	int DealerHand = 0;
	int stillIn = 0;
	bool surrender = false;
	int sum = 0;
	int dsum = 0;
	double half = .5;
	int win = 0;

	User *Me = new User[4];
	Dealer Deal;
	Players *strangers = new Players[players];

	shuffle();

	if (players == 0)
	{
		stillIn = 1;
	}

	Deal.Hand[DealerHand] = dealCard(currentCard);
	currentCard++;
	DealerHand++;
	Me[0].Hand[Me[0].UserHand] = dealCard(currentCard);
	currentCard++;
	Me[0].UserHand++;
	Deal.Hand[DealerHand] = dealCard(currentCard);
	currentCard++;
	DealerHand++;
	Me[0].Hand[Me[0].UserHand] = dealCard(currentCard);
	currentCard++;
	Me[0].UserHand++;

	for (int i = 0; i < players; i++)
	{
		strangers[i].Hand[strangers[i].cards] = dealCard(currentCard);
		strangers[i].cards++;
		currentCard++;
	}

	for (int i = 0; i < players; i++)
	{
		strangers[i].Hand[strangers[i].cards] = dealCard(currentCard);
		strangers[i].cards++;
		currentCard++;
	}

	system("clear");

	PrintDealer(Deal.Hand, DealerHand);
	PrintUser(Me[0].Hand, Me[0].UserHand);

	sum = getTotal(Me[0].Hand);
	dsum = getTotal(Deal.Hand);

	cout << "Your total is: " << sum << endl;

	if (sum == 21 && dsum != 21)
	{
		cout << "BLACKJACK!" << endl;
		return 3;
	}

	for (int j = 0; j < players; j++)
	{
		cout << "Player " << j + 1 << "'s hand is: ";
		PrintPlayer(strangers[j].Hand, strangers[j].cards);
		cout << "Player " << j + 1 << "'s total is: " << getTotal(strangers[j].Hand) << endl;
	}

	system("PAUSE");
	system("clear");

	if (Me[0].Hand[0] == Me[0].Hand[1])
		split++;

	for (int i = 0; i < split; i++)
	{

		if (Me[i].Hand[0] == Me[i].Hand[1])
		{
			char answer;
			int temp;
			cout << "Would you like to split? (Y/N)";
			cin >> answer;

			answer = toupper(answer);

			if (answer == 'Y')
			{
				temp = Me[i].Hand[0];
				Me[i].Hand[1] = dealCard(currentCard);
				currentCard++;

				Me[i + 1].Hand[0] = temp;
				Me[i + 1].UserHand++;
				Me[i + 1].Hand[1] = dealCard(currentCard);
			}
			else
				split--;
		}
	}

	while (DStand == 0 || Me[0].UStand == 0 || stillIn == 0)
	{
		if (DStand == 0 && getTotal(Deal.Hand) < 22)
		{
			Deal.Hand[DealerHand] = DealerMove(dsum, currentCard);

			if (getTotal(Deal.Hand) > 21)
			{
				cout << "Dealer's total is: " << getTotal(Deal.Hand) << endl;
				cout << "Dealer busts, you win!" << endl;
				return 2;
			}

			if (getTotal(Deal.Hand) < 22)
			{
				Deal.Hand[DealerHand] = DealerMove(dsum, currentCard);
				DealerHand++;
				currentCard++;
				dsum = getTotal(Deal.Hand);
			}

			if (Deal.Hand[DealerHand - 1] == 0 && getTotal(Deal.Hand) < 22)
			{
				DStand = 1;
				DealerHand--;
			}

			if (getTotal(Deal.Hand) > 21)
			{
				cout << "Dealer's total is: " << getTotal(Deal.Hand) << endl;
				cout << "Dealer busts, you win!" << endl;
				return 2;
			}

			PrintDealer(Deal.Hand, DealerHand);
		}
		else
		{
			cout << "Dealer chose to stand" << endl;
			DStand = 1;
		}

		for (int i = 0; i < split; i++)
		{
			if (Me[i].UStand == 0 && getTotal(Me[i].Hand) < 22)
			{
				cout << "Would you like to Hit, Stand or Surrender?" << endl;

				PrintUser(Me[i].Hand, Me[i].UserHand);

				if (getTotal(Me[i].Hand) < 22)
				{
					Me[i].Hand[Me[i].UserHand] = UserMove(currentCard);
					currentCard++;
					Me[i].UserHand++;
				}

				if (Me[i].Hand[Me[i].UserHand - 1] == 0)
				{
					Me[i].UStand = 1;
					Me[i].UserHand--;
				}

				if (Me[i].Hand[Me[i].UserHand - 1] == -1)
				{
					cout << "You chose to surrender" << endl;
					Me[i].UserHand--;
					Me[i].UStand = -1;
					surrender = true;
				}

				if (getTotal(Me[i].Hand) > 21)
				{
					PrintUser(Me[i].Hand, Me[i].UserHand);
					cout << "Your total is: " << getTotal(Me[i].Hand) << endl;
					cout << "You busted, you lose" << endl;
				}
				else
				{
					PrintUser(Me[i].Hand, Me[i].UserHand);
					cout << "Your total is: " << getTotal(Me[i].Hand) << endl;
				}
			}
			else
			{
				cout << "You chose to stand" << endl;
				Me[i].UStand = 1;
			}
		}

		for (int i = 0; i < players; i++)
		{
			if (strangers[i].PStand == 0)
			{
				cout << "Would player " << i + 1 << " like to Hit, Stand or Surrender?" << endl;

				PrintUser(strangers[i].Hand, strangers[i].cards);
				strangers[i].Hand[strangers[i].cards] = UserMove(currentCard);
				currentCard++;
				strangers[i].cards++;

				if (strangers[i].Hand[strangers[i].cards - 1] == 0)
				{
					strangers[i].PStand = 1;
					strangers[i].cards--;
				}

				if (strangers[i].Hand[strangers[i].cards - 1] == -1)
				{
					cout << "Player " << i + 1 << " chose to surrender" << endl;
					strangers[i].cards--;
					strangers[i].PStand = 1;
				}

				if (getTotal(strangers[i].Hand) > 21)
				{
					PrintUser(strangers[i].Hand, strangers[i].cards);
					cout << "Player " << i + 1 << " total is: " << getTotal(strangers[i].Hand) << endl;
					cout << "Player " << i + 1 << " busted, Player" << i + 1 << " loses" << endl;
					strangers[i].PStand = 1;
				}
				else
				{
					PrintUser(strangers[i].Hand, strangers[i].cards);
					cout << "Player " << i + 1 << " total is: " << getTotal(strangers[i].Hand) << endl;
				}
			}
			else
				cout << "Player " << i + 1 << " chose to stand" << endl;
		} // end for

		for (int j = players - 1; j >= 0; j--)
		{
			if (strangers[j].PStand == 1)
				stillIn = 1;
			else
				break;
		}

		system("PAUSE");
		system("clear");
	}

	system("clear");
	cout << "Dealer's total is: " << getTotal(Deal.Hand) << endl;
	cout << "Dealer's hand: ";
	PrintUser(Deal.Hand, DealerHand);

	cout << "\nYour total is: " << getTotal(Me[0].Hand) << endl;
	cout << "Your Hand: ";
	PrintUser(Me[0].Hand, Me[0].UserHand);
	cout << endl
		 << endl;

	for (int i = 0; i < players; i++)
	{
		cout << "Player " << i + 1 << "'s total is: " << getTotal(strangers[i].Hand) << endl;
		PrintUser(strangers[i].Hand, strangers[i].cards);

		if (getTotal(strangers[i].Hand) > getTotal(Deal.Hand) && getTotal(strangers[i].Hand) < 22)
			cout << "Player " << i + 1 << " wins!";

		if (getTotal(strangers[i].Hand) < getTotal(Deal.Hand))
			cout << "Player " << i + 1 << " loses";

		if (getTotal(strangers[i].Hand) == getTotal(Deal.Hand))
			cout << "Push!";

		cout << endl
			 << endl;
	}

	sum = getTotal(Me[0].Hand);
	dsum = getTotal(Deal.Hand);

	if (surrender)
	{
		cout << "User chose to surrender " << endl;
		return .5;
	}

	for (int i = 0; i < split; i++)
	{
		if (getTotal(Me[i].Hand) == dsum && sum < 22)
		{
			cout << "Push!" << endl;
			Me[i].win = 2;
		}

		if (sum > dsum && sum < 22)
		{
			cout << "You win!" << endl;
			Me[i].win = 1;
		}
		if (sum < dsum && sum > 22)
		{
			cout << "Sorry you lost" << endl;
		}
	}

	for (int j = 0; j < split; j++)
	{
		if (Me[j].win == 1)
			win += 2;
		if (Me[j].win == 2)
			win += 1;
	}

	return win;
}

int Blackjack::DealerMove(int sum, int currentCard)
{

	if (sum > 17)
	{
		cout << "Dealer chooses to stand" << endl;
		return 0;
	}
	if (sum < 17)
	{
		cout << "Dealer chooses to hit" << endl;
		return dealCard(currentCard);
	}
}

void Blackjack::PrintDealer(int Hand[], int size)
{
	cout << "Dealer's Hand is: []";

	for (int i = 1; i < size; i++)
	{
		cout << "[" << getFaceValue(Hand[i]) << "]";
	}
	cout << endl;
}

int Blackjack::UserMove(int currentCard)
{
	int go;

	cout << "Enter 1 for Hit, \n2 for Stand, \n0 for Surrender): ";
	cin >> go;

	switch (go)
	{
	case 1:
		return dealCard(currentCard);
		break;
	case 2:
		return 0;
		break;
	case 0:
		return -1;
		break;
	default:
		cout << "Wrong choice, default is standing ";
		return 0;
	}
}

void Blackjack::PrintUser(int Hand[], int size)
{
	cout << "Your Hand : ";

	for (int i = 0; i < size; i++)
	{
		if (getFaceValue(Hand[i]) == '0')
			cout << "[10]";
		else
			cout << "[" << getFaceValue(Hand[i]) << "]";
	}
	cout << endl;
}

void Blackjack::PrintPlayer(int Hand[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (getFaceValue(Hand[i]) == '0')
			cout << "[10]";
		else
			cout << "[" << getFaceValue(Hand[i]) << "]";
	}
	cout << endl;
}

int PrintResults(int sum, int dsum)
{
	return 0;
}

Blackjack::~Blackjack()
{
}
