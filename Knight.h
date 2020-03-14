#pragma once
#include "Piece.h"
class Knight : virtual public Piece
{
public:
	Knight(char, int, bool);
	bool canMove(char currX, int currY, char targetX, int targetY);
	string name();
};

