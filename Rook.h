#pragma once
#include "Piece.h"
class Rook : virtual public Piece
{
public:
	Rook(char, int, bool);
	bool canMove(char currX, int currY, char targetX, int targetY);
	string name();
};
