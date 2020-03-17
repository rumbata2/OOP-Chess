#include "stdafx.h"
#include "Bishop.h"


Bishop::Bishop(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Bishop::movementPattern(char currX, int currY, char targetX, int targetY) {
	if (abs(currX - targetX) == abs(currY - targetY)) {
		return true;
	}
	return false;
}

string Bishop::name() {
	return "Bishop";
}