#include "stdafx.h"
#include "Queen.h"

Queen::Queen(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite),
																Bishop(xCoordinate, yCoordinate, isWhite),
																Rook(xCoordinate, yCoordinate, isWhite) {}

bool Queen::movementPattern(char currX, int currY, char targetX, int targetY) {
	return Bishop::movementPattern(currX, currY, targetX, targetY) || Rook::movementPattern(currX, currY, targetX, targetY);
}

string Queen::name() {
	return "Queen";
}


