#pragma once
#include "Piece.h"
class Box
{
private:
	char xCoordinate;
	int yCoordinate;
	//bool isWhite;
	Piece* piece;

public:
	Box(char xCoordinate, int yCoordinate) {
		this->xCoordinate = xCoordinate;
		this->yCoordinate = yCoordinate;
		//this->isWhite = (xCoordinate + yCoordinate) % 2;
	}

	Box(int xCoordinate, int yCoordinate, Piece* piece) {
		this->xCoordinate = xCoordinate;
		this->yCoordinate = yCoordinate;
		//this->isWhite = (xCoordinate + yCoordinate) % 2;
		this->piece = piece;
	}

	char getXCoordinate() {
		return xCoordinate;
	}
	int getYCoordinate() {
		return yCoordinate;
	}
	void setPiece(Piece* piece) {
		this->piece = piece;
	}
};

