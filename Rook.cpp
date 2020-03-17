#include "stdafx.h"
#include "Rook.h"


Rook::Rook(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Rook::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (currX - targetX == 0 || currY - targetY == 0);
}

string Rook::name() {
	return "Rook";
}


