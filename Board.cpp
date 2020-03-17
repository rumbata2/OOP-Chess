#include "stdafx.h"
#include "Board.h"


Board::Board() {
	
	int y = 0;
	std::vector<Box> row;
	for (int i = 0; i < 8; i++) {
		boxes.push_back(row);
	}
	for (int i = 8; i >= 1; i--) {
		for (char c = 'a'; c <= 'h'; c++) {
			Box temp(c, i);
			boxes[y].push_back(temp);
		}
		y++;
	}
}

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		delete whitePawns[i];
		delete blackPawns[i];
	}
	for (int i = 0; i < 2; i++) {
		delete whiteRooks[i];
		delete blackRooks[i];
		delete whiteKnights[i];
		delete blackKnights[i];
		delete whiteBishops[i];
		delete blackBishops[i];
	}
	delete whiteKing;
	delete whiteQueen;
	delete blackKing;
	delete blackQueen;
}


void Board::initializeBoard() {
	for (int i = 0; i < 8; i++) {
		whitePawns[i] = new Pawn('a' + i, 2, 1);
		boxes[6][i].setPiece(whitePawns[i]);
		blackPawns[i] = new Pawn('a' + i, 7, 0);
		boxes[1][i].setPiece(blackPawns[i]);
	}
	whiteRooks[0] = new Rook('a', 1, 1);
	whiteRooks[1] = new Rook('h', 1, 1);
	boxes[7][0].setPiece(whiteRooks[0]);
	boxes[7][7].setPiece(whiteRooks[1]);

	whiteKnights[0] = new Knight('b', 1, 1);
	whiteKnights[1] = new Knight('g', 1, 1);
	boxes[7][1].setPiece(whiteKnights[0]);
	boxes[7][6].setPiece(whiteKnights[1]);

	whiteBishops[0] = new Bishop('c', 1, 1);
	whiteBishops[1] = new Bishop('f', 1, 1);
	boxes[7][2].setPiece(whiteBishops[0]);
	boxes[7][5].setPiece(whiteBishops[1]);

	whiteQueen = new Queen('d', 1, 1);
	boxes[7][3].setPiece(whiteQueen);

	whiteKing = new King('e', 1, 1);
	boxes[7][4].setPiece(whiteKing);

	
	
	blackRooks[0] = new Rook('a', 8, 0);
	blackRooks[1] = new Rook('h', 8, 0);
	boxes[0][0].setPiece(blackRooks[0]);
	boxes[0][7].setPiece(blackRooks[1]);

	blackKnights[0] = new Knight('b', 8, 0);
	blackKnights[1] = new Knight('g', 8, 0);
	boxes[0][1].setPiece(blackKnights[0]);
	boxes[0][6].setPiece(blackKnights[1]);

	blackBishops[0] = new Bishop('c', 8, 0);
	blackBishops[1] = new Bishop('f', 8, 0);
	boxes[0][2].setPiece(blackBishops[0]);
	boxes[0][5].setPiece(blackBishops[1]);

	blackQueen = new Queen('d', 8, 0);
	boxes[0][3].setPiece(blackQueen);

	blackKing = new King('e', 8, 0);
	boxes[0][4].setPiece(blackKing);
}



void Board::getBoxesInfo() {
	for (int i = 0; i < boxes.size(); i++) {
		for (int j = 0; j < boxes[i].size(); j++) {
			cout << boxes[i][j].getXCoordinate() << " " << boxes[i][j].getYCoordinate() << "\n";
		}
	}
}

Piece* Board::getPiece(char x, int y) {
	return boxes[convertToMatrixCoordinates(x, y).first][convertToMatrixCoordinates(x, y).second].getBoxPiece();
}

void Board::setPiece(char x, int y, Piece* piece) {
	boxes[convertToMatrixCoordinates(x, y).first][convertToMatrixCoordinates(x, y).second].setPiece(piece);
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
		if (this->getPiece(currX - 1, currY + 1) && targetX == currX-1 && targetY == currY + 1 ||
			this->getPiece(currX + 1, currY + 1) && targetX == currX + 1 && targetY == currY + 1) {
			return true;
		}
	}
	else {
		if (this->getPiece(currX - 1, currY - 1) && targetX == currX - 1 && targetY == currY - 1 || 
			this->getPiece(currX + 1, currY - 1) && targetX == currX + 1 && targetY == currY - 1) {
			return true;
		}
	}
	return false;
}

bool Board::validMove(char currX, int currY, char targetX, int targetY) {
	Piece* pieceToMove = this->getPiece(currX, currY);

	if (pieceToMove->name() != "Pawn") {
		return pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY);
	}
	else {
		return ((pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY))
				|| pawnTakeRule(pieceToMove, currX, currY, targetX, targetY));
	}
}