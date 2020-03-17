#include "stdafx.h"
#include "King.h"


King::King(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool King::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (abs(currX - targetX) + abs(currY - targetY) == 1 ||
			abs(currX - targetX) + abs(currY - targetY) == 2 && (abs(currX-targetX)==1 || abs(currY-targetY)==1));
}

string King::name() {
	return "King";
}
