#include "stdafx.h"
#include "Queen.h"

Queen::Queen(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove),
																   Bishop(isWhite, hasMoved, plySinceFirstMove),
																   Rook(isWhite, hasMoved, plySinceFirstMove) {}

bool Queen::movementPattern(char currX, int currY, char targetX, int targetY) {
	return Bishop::movementPattern(currX, currY, targetX, targetY) || Rook::movementPattern(currX, currY, targetX, targetY);
}

string Queen::name() {
	return "Queen";
}


