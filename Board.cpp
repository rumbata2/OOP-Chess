#include "stdafx.h"
#include "Board.h"


Board::Board() {
	std::vector<Piece*> row;
	for (int i = 0; i < 8; i++) {
		squares.push_back(row);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			squares[i].push_back(nullptr);
		}
	}
}

void Board::initializeBoard() {
	for (int i = 0; i < 8; i++) 
		squares[6][i] = new Pawn(1, 0, 0);		
	
	squares[7][0] = new Rook(1, 0, 0);
	squares[7][1] = new Knight(1, 0, 0);
	squares[7][2] = new Bishop(1, 0, 0);
	squares[7][3] = new Queen(1, 0, 0);
	squares[7][4] = new King(1, 0, 0);
	squares[7][5] = new Bishop(1, 0, 0);
	squares[7][6] = new Knight(1, 0, 0);
	squares[7][7] = new Rook(1, 0, 0);

	for (int i = 0; i < 8; i++) 
		squares[1][i] = new Pawn(0, 0, 0);
	
	squares[0][0] = new Rook(0, 0, 0);
	squares[0][1] = new Knight(0, 0, 0);
	squares[0][2] = new Bishop(0, 0, 0);
	squares[0][3] = new Queen(0, 0, 0);
	squares[0][4] = new King(0, 0, 0);
	squares[0][5] = new Bishop(0, 0, 0);
	squares[0][6] = new Knight(0, 0, 0);
	squares[0][7] = new Rook(0, 0, 0);
}


Piece* Board::getPiece(char x, int y) {
	return squares[convertToMatrixCoordinates(x, y).first][convertToMatrixCoordinates(x, y).second];
}

void Board::setPiece(char x, int y, Piece* piece) {
	squares[convertToMatrixCoordinates(x, y).first][convertToMatrixCoordinates(x, y).second] = piece;
}

pair<char, int> convertToChessCoordinates(int i, int j) {
	pair<char, int> result;
	result.first = 'a' + j;
	result.second = 8 - i;
	return result;
}

pair<int, int> convertToMatrixCoordinates(char x, int y) {
	pair<int, int> result;
	result.first = 8 - y;
	result.second = (int)(x - 'a');
	return result;
}

bool Board::blockedPath(Piece* pieceToMove, char currX, int currY, char targetX, int targetY) {
	bool result = 0;
	if (pieceToMove->name() == "Bishop" || pieceToMove->name() == "Queen") {
		int steps = abs(currX - targetX);
		if (currX < targetX && currY < targetY) {
			for (int i = 1; i < steps; i++) {
				if (this->getPiece(currX + i, currY + i))
					result = true;
			}
		}
		else if (currX < targetX && currY > targetY) {
			for (int i = 1; i < steps; i++) {
				if (this->getPiece(currX + i, currY - i))
					result = true;
			}
		}
		else if (currX > targetX && currY < targetY) {
			for (int i = 1; i < steps; i++) {
				if (this->getPiece(currX - i, currY + i))
					result = true;
			}
		}
		else if (currX > targetX && currY > targetY) {
			for (int i = 1; i < steps; i++) {
				if (this->getPiece(currX - i, currY - i))
					result = true;
			}
		}
	}

	if (pieceToMove->name() == "Rook" || pieceToMove->name() == "Queen") {
		int steps;
		if (currX == targetX) {
			int steps = abs(currY - targetY);
			if (currY < targetY) {
				for (int i = 1; i < steps; i++) {
					if (this->getPiece(currX, currY + i))
						result = true;
				}
			}
			else if (currY > targetY) {
				for (int i = 1; i < steps; i++) {
					if (this->getPiece(currX, currY - i))
						result = true;
				}
			}
		}
		else if (currY == targetY) {
			int steps = abs(currX - targetX);
			if (currX < targetX) {
				for (int i = 1; i < steps; i++) {
					if (this->getPiece(currX + i, currY))
						result = true;
				}
			}
			else if (currX > targetX) {
				for (int i = 1; i < steps; i++) {
					if (this->getPiece(currX - i, currY))
						result = true;
				}
			}
		}
	}

	if (pieceToMove->name() == "Pawn") {
		if (pieceToMove->getIsWhite() && getPiece(currX, currY + 1) ||
			!pieceToMove->getIsWhite() && getPiece(currX, currY - 1))
			result = true;
	}

	return result;
}

bool Board::pawnTakeRule(Piece* piece, char currX, int currY, char targetX, int targetY) {
	if (piece->getIsWhite()) {
		if (targetX == currX - 1 && targetY == currY + 1 && this->getPiece(currX - 1, currY + 1) ||
			targetX == currX + 1 && targetY == currY + 1 && this->getPiece(currX + 1, currY + 1)) {
			return true;
		}
	}
	else {
		if (targetX == currX - 1 && targetY == currY - 1 && this->getPiece(currX - 1, currY - 1) ||
			targetX == currX + 1 && targetY == currY - 1 && this->getPiece(currX + 1, currY - 1)) {
			return true;
		}
	}
	return false;
}

bool Board::enPassant(char currX, int currY, char targetX, int targetY) {
	Piece* piece = this->getPiece(currX, currY);
	if (piece->getIsWhite()) {
		if (targetX == currX - 1 && targetY == currY + 1 && targetY == 6 && this->getPiece(currX - 1, currY) &&
			this->getPiece(currX - 1, currY)->name() == "Pawn" && this->getPiece(currX - 1, currY)->getPlySinceFirstMove() == 1) {
			return true;			
		} 
		else if (targetX == currX + 1 && targetY == currY + 1 && targetY == 6 && this->getPiece(currX + 1, currY) &&
			this->getPiece(currX + 1, currY)->name() == "Pawn" && this->getPiece(currX + 1, currY)->getPlySinceFirstMove() == 1) {
			return true;
		}
	}
	else {
		if (targetX == currX - 1 && targetY == currY - 1 && targetY == 3 && this->getPiece(currX - 1, currY) &&
			this->getPiece(currX - 1, currY)->name() == "Pawn" && this->getPiece(currX - 1, currY)->getPlySinceFirstMove() == 1) {
			return true;
		}
		else if (targetX == currX + 1 && targetY == currY - 1 && targetY == 3 && this->getPiece(currX + 1, currY) &&
			this->getPiece(currX + 1, currY)->name() == "Pawn" && this->getPiece(currX + 1, currY)->getPlySinceFirstMove() == 1) {
			return true;
		}
	}
	return false;
}

bool Board::kingSideCastle(char currX, int currY, char targetX, int targetY) {
	Piece* pieceToMove = this->getPiece(currX, currY);
	int row = pieceToMove->getIsWhite() ? 1 : 8;
	return (pieceToMove->name() == "King" && !this->getPiece('f', row) && !this->getPiece('g', row) && this->getPiece('h', row)->name() == "Rook" &&
		currX == 'e' && currY == row && targetX == 'e' + 2 && targetY == row &&
		!pieceToMove->getHasMoved() && !this->getPiece('h', row)->getHasMoved());
		
}

bool Board::queenSideCastle(char currX, int currY, char targetX, int targetY) {
	Piece* pieceToMove = this->getPiece(currX, currY);
	int row = pieceToMove->getIsWhite() ? 1 : 8;
	return (pieceToMove->name() == "King" && this->getPiece('a', row)->name() == "Rook" && !this->getPiece('b', row) && !this->getPiece('c', row) && !this->getPiece('d', row) &&
		currX == 'e' && currY == row && targetX == 'e' - 2 && targetY == row); 
}

bool Board::validMove(char currX, int currY, char targetX, int targetY) {
	Piece* pieceToMove = this->getPiece(currX, currY);

	if (pieceToMove->name() == "King") {
		return pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY) ||
			kingSideCastle(currX, currY, targetX, targetY) || queenSideCastle(currX, currY, targetX, targetY);
	}
	else if (pieceToMove->name() != "Pawn") {
		return pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY);
	}
	else {
		return (pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY))
			|| pawnTakeRule(pieceToMove, currX, currY, targetX, targetY) || enPassant(currX, currY, targetX, targetY);
	}
}