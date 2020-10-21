// Scott Enzinna

#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include "SlotMachine.h"
#include "Blackjack.h"

using namespace std;

template <class T>
void print(T age, T total)
{

	cout << "You are " << age << " to play, you should be " << total << " to play, Good Luck";
}

int main()
{
	int balance = 1000;
	int choice;
	int game[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	srand(time(NULL));
	slots machine(game);
	int currentCard = 0;
	Blackjack table(balance, currentCard);

	system("clear");

	cout << "Hello, this is Scott game…\n"
		 << endl;

	int age;
	cout << "How old are you? ";
	cin >> age;

	print(age, 21);
	cout << endl;

	cout << "What would you to do\n\nEnter 1 for Slots, 2 for Blackjack or 0 to leave: " << endl;
	cin >> choice;

	do
	{
		switch (choice)
		{
		case 2:
			balance = table.playGame(balance);
			break;
		case 1:
			balance = machine.play(balance);
			break;
		case 0:
			cout << "\n\nGood Bye You have $" << balance << endl;
			system("clear");
			return 0;
		default:
			cout << "\nTry Again: ";
			cin >> choice;
			if (choice == 0)
			{
				cout << "\n\nGood Bye You have $" << balance << endl;
				system("clear");
				return 0;
			}
		}

		cout << "Right now you have $" << balance << endl;
		cout << "What do you want to do next?\nEnter 1 for Slots, 2 for Blackjack or 0 to leave: ";
		cin >> choice;
	}

	while (choice != 0 && balance > 0);
	cout << "\n\nGood Bye You have $" << balance << endl;
	system("clear");
	return 0;
}