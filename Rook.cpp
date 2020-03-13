#include "stdafx.h"
#include "Rook.h"


Rook::Rook(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Rook::canMove(char currX, int currY, char targetX, int targetY) {
	return true;
}

string Rook::name() {
	return "Rook";
}


