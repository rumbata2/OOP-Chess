#include "stdafx.h"
#include "Knight.h"


Knight::Knight(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Knight::movementPattern(char currX, int currY, char targetX, int targetY) {
	return (abs(abs(currX - targetX) - abs(currY - targetY)) == 1 && abs(currX - targetX) + abs(currY - targetY) == 3);
}

string Knight::name() {
	return "Knight";
}