#include "stdafx.h"
#include "Pawn.h"

Pawn::Pawn(bool isWhite, bool hasMoved, int plySinceFirstMove) : Piece(isWhite, hasMoved, plySinceFirstMove) {}

bool Pawn::movementPattern(char currX, int currY, char targetX, int targetY) {
	if (currX == targetX) {
		if (this->isWhite) {
			if (currY == 2)
				return (targetY == currY + 1) || (targetY == currY + 2);
			return (targetY == currY + 1);
		}
		else {
			if (currY == 7) 
				return (targetY == currY - 1) || (targetY == currY - 2);		
			return (targetY == currY - 1);			
		}
	}
	return false;
}

string Pawn::name() {
	return "Pawn";
}