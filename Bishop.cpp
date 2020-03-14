#include "stdafx.h"
#include "Bishop.h"


Bishop::Bishop(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Bishop::canMove(char currX, int currY, char targetX, int targetY) {
	return true;
}

string Bishop::name() {
	return "Bishop";
}