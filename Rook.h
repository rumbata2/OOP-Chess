#pragma once
#include "Piece.h"
class Rook : virtual public Piece
{
public:
	Rook(char, int, bool);
	bool movementPattern(char currX, int currY, char targetX, int targetY);
	string name();
};
