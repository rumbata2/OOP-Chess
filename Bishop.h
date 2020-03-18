#pragma once
#include "Piece.h"
class Bishop : virtual public Piece
{
public:
	Bishop(bool, bool, int);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};

