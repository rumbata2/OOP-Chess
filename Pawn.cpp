#include "stdafx.h"
#include "Pawn.h"

Pawn::Pawn(char xCoordinate, int yCoordinate, bool isWhite) : Piece(xCoordinate, yCoordinate, isWhite) {}

bool Pawn::canMove(char currX, int currY, char targetX, int targetY) {
	if (this->validCoordinates(targetX, targetY)) {
		if (this->isWhite && targetY == currY + 1)
			return true;
		else if (!this->isWhite && targetY == currY - 1)
			return true;

		return false;
	}
	else return false;
}

string Pawn::name() {
	return "Pawn";
}