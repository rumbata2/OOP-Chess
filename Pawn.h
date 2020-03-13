#pragma once
#include "Piece.h"
class Pawn : virtual public Piece
{
private:

public:
	Pawn(char, int, bool);
	bool canMove(char currX, int currY, char targetX, int targetY);
	string name();
};

