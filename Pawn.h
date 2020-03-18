#pragma once
#include "Piece.h"
class Pawn : virtual public Piece
{
public:
	Pawn(bool, bool, int);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};

