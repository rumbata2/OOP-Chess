#include "stdafx.h"
#include "Knight.h"


Knight::Knight(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove) {}

bool Knight::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (abs(abs(currX - targetX) - abs(currY - targetY)) == 1 && abs(currX - targetX) + abs(currY - targetY) == 3);
}

string Knight::name() {
	return "Knight";
}