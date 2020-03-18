#include "stdafx.h"
#include "Piece.h"

Piece::Piece(bool isWhite, bool hasMoved, int plySinceFirstMove) {
	this->isWhite = isWhite;
	this->hasMoved = hasMoved;
	this->plySinceFirstMove = plySinceFirstMove;
}

