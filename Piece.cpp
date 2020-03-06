#include "stdafx.h"
#include "Piece.h"

Piece::Piece(char xCoordinate, int yCoordinate, bool isWhite) {
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->isWhite = isWhite;
}

bool Piece::validCoordinates(char x, int y) {
	return ('a' <= x && x <= 'h' && 1 <= y && y <= 8);
}