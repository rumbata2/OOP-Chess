#pragma once
#include "Bishop.h"
#include "Rook.h"
class Queen : public Bishop, Rook
{
public:
	Queen(bool, bool, int);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	virtual string name();
};

