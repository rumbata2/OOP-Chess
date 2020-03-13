#pragma once
#include "Piece.h"
class Box
{
private:
	char xCoordinate;
	int yCoordinate;
	Piece* piece;

public:
	Box(char xCoordinate, int yCoordinate);
	Box(int xCoordinate, int yCoordinate, Piece* piece);

	char getXCoordinate() {
		return xCoordinate;
	}
	int getYCoordinate() {
		return yCoordinate;
	}
	void setPiece(Piece* piece) {
		this->piece = piece;
	}
	Piece* getBoxPiece() {
		return piece;
	}
};

