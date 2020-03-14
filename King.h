#pragma once
#include "Piece.h"
class King : virtual public Piece
{
public:
	King(char, int, bool);
	bool canMove(char currX, int currY, char targetX, int targetY);
	string name();
};
