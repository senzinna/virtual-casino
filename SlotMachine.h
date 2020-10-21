// Scott Enzinna
// Project

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <cstring>
#include <vector>

const int SIZE = 10;
class slots
{
public:
	slots(int row[]);
	void swap(int row[]);
	int spin(int row[]);
	int play(int balance);

private:
	int row1[SIZE];
	int row2[SIZE];
	int row3[SIZE];
};
#endif
