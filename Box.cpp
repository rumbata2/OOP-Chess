#include "stdafx.h"
#include "Box.h"


Box::Box(char xCoordinate, int yCoordinate) {
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	piece = nullptr;
}

Box::Box(int xCoordinate, int yCoordinate, Piece* piece) {
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->piece = piece;
}