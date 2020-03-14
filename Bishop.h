#pragma once
#include "Piece.h"
class Bishop : virtual public Piece
{
public:
	Bishop(char, int, bool);
	bool canMove(char currX, int currY, char targetX, int targetY);
	string name();
};

