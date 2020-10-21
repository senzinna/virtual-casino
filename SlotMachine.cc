// Scott Enzinna
// Project

#include <iostream>
#include <time.h>
#include "SlotMachine.h"
using namespace std;
slots::slots(int row[SIZE])
{
	int *ptr;
	int a;
	for (a = 0; a < SIZE; a++)
	{
		ptr = &row[a];
		row1[a] = *ptr;
		row2[a] = *ptr;
		row3[a] = *ptr;
	}
};

void slots::swap(int row[])
{
	int temp = row[0];
	row[0] = row[1];
	row[1] = row[2];
	row[2] = row[3];
	row[3] = row[4];
	row[4] = row[5];
	row[5] = row[6];
	row[6] = row[7];
	row[7] = row[8];
	row[8] = row[9];
	row[9] = temp;
}

int slots::spin(int row[])
{
	int turns1 = (rand() % 100) + 50;
	int turns2 = (rand() % 100) + 50;
	int turns3 = (rand() % 100) + 50;

	vector<int> row1(3);
	vector<int> row2(3);
	vector<int> row3(3);

	int temp;
	do
	{
		if (turns1 > 0)
		{
			swap(row);
			row1[0] = row[0];
			row1[1] = row[1];
			row1[2] = row[2];
		}

		if (turns2 > 0)
		{
			swap(row);
			row2[0] = row[0];
			row2[1] = row[1];
			row2[2] = row[2];
		}

		if (turns3 > 0)
		{
			swap(row);
			row3[0] = row[0];
			row3[1] = row[1];
			row3[2] = row[2];
		}

		for (int j = 0; j < 3; j++)
		{
			cout << "[ " << row1[j] << " ]\t";
			cout << "[ " << row2[j] << " ]\t";
			cout << "[ " << row3[j] << " ]\n";
		}

		turns1--;
		turns2--;
		turns3--;

		if (turns1 > 0 || turns2 > 0 || turns3 > 0)
			system("clear");
	} while (turns1 > 0 || turns2 > 0 || turns3 > 0);

	int win = 0;
	int same = 0;
	int max = 0;
	for (int l = 0; l < 3; l++)
	{
		for (int y = 0; y < 3; y++)
		{
			int match = 0;

			if (row1[l] == row2[y])
				match++;
			if (row1[l] == row3[y])
				match++;
			if (row2[l] == row3[y])
				same++;
			if (match > max)
				max = match;
			if (same > max)
				max = same;
		}
	}

	if (max == 1)
		win = 2;
	if (max >= 2)
		win = 5;
	if (row1[1] == row2[1] || row1[1] == row3[1] || row2[1] == row3[1])
		win = 30;
	if (row1[1] == row2[1] && row1[1] == row3[1])
		win = 300;
	return win;
}

int slots::play(int balance)
{
	int bet;
	int win;
	system("clear");
	cout << "How much would you like to bet?\n$1, \n$2, \n$5, \n$10\n:";
	cin >> bet;

	while (bet != 1 && bet != 2 && bet != 5 && bet != 10 && bet < balance)
	{
		cout << "Please enter a number listed above: ";
		cin >> bet;
		cout << endl;
	}

	balance -= bet;

	cout << endl;
	int pull[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	win = spin(pull);

	cout << "You won $" << win * bet << endl;

	return balance += (bet * win);
}
