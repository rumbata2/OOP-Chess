#include "stdafx.h"
#include "Bishop.h"


Bishop::Bishop(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove) {}

bool Bishop::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (abs(currX - targetX) == abs(currY - targetY));
}

string Bishop::name() {
	return "Bishop";
}