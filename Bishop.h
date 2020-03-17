#pragma once
#include "Piece.h"
class Bishop : virtual public Piece
{
public:
	Bishop(char, int, bool);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};

