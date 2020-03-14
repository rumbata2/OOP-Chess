#include "stdafx.h"
#include "King.h"


King::King(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool King::canMove(char currX, int currY, char targetX, int targetY) {
	return true;
}

string King::name() {
	return "King";
}
