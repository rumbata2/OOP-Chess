#pragma once
#include "Bishop.h"
#include "Rook.h"
class Queen : public Bishop, Rook
{
public:
	Queen(char, int, bool);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	virtual string name();
};

