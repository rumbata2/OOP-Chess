#include "stdafx.h"
#include "Rook.h"


Rook::Rook(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove) {}

bool Rook::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (currX - targetX == 0 || currY - targetY == 0);
}

string Rook::name() {
	return "Rook";
}


