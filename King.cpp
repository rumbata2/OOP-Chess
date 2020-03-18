#include "stdafx.h"
#include "King.h"


King::King(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove) {}

bool King::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (abs(currX - targetX) + abs(currY - targetY) == 1 ||
			abs(currX - targetX) + abs(currY - targetY) == 2 && (abs(currX-targetX)==1 || abs(currY-targetY)==1));
}

string King::name() {
	return "King";
}
