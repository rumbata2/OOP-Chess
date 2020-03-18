#pragma once
#include "Piece.h"
class King : virtual public Piece
{
public:
	King(bool, bool, int);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};
