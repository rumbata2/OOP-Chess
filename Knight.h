#pragma once
#include "Piece.h"
class Knight : virtual public Piece
{
public:
	Knight(bool, bool, int);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};

