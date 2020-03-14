#include "stdafx.h"
#include "Knight.h"


Knight::Knight(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Knight::canMove(char currX, int currY, char targetX, int targetY) {
	return true;
}

string Knight::name() {
	return "Knight";
}