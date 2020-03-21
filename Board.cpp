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

pair<char, int> Board::findKing(bool white) {
	for (char c = 'a'; c <= 'h'; c++) {
		for (int i = 1; i <= 8; i++) {
			if (this->getPiece(c, i) && this->getPiece(c, i)->name() == "King" && this->getPiece(c, i)->getIsWhite() == white)
				return make_pair(c, i);
		}
	}
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

int Board::isAttacked(char X, int Y, bool isWhite) {
	vector<pair<char, int>> attackers;
	for (char c = 'a'; c <= 'h'; c++) {
		for (int i = 1; i <= 8; i++) {
			if (this->getPiece(c, i) && (c != X || i != Y)) {
				Piece* attacker = this->getPiece(c, i);
				if (attacker->getIsWhite() == !isWhite) {
					if (attacker->name() == "Pawn") {
						if (pawnTakeRule(attacker, c, i, X, Y)) 
							attackers.push_back(make_pair(c, i));		
					}				
					else {
						if ((attacker->movementPattern(c, i, X, Y) && !blockedPath(attacker, c, i, X, Y))) 
							attackers.push_back(make_pair(c, i));
					}
				}
			}
		}
	}
	/*cout << "The square " << X << " " << Y << " is attacked by " << attackers.size() << " pieces in total:  ";
	for (int i = 0; i < attackers.size(); i++) {
		cout << attackers[i].first << " " << attackers[i].second << ", ";
	}
	cout << endl;*/
	return attackers.size();
}

bool Board::pawnTakeRule(Piece* piece, char currX, int currY, char targetX, int targetY) {
	if (piece->name() != "Pawn") return false;
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

bool Board::checkAfterPly(char currX, int currY, char targetX, int targetY) {
	Board copy(*this);
	Piece* pieceToMove = this->getPiece(currX, currY);
	bool white = pieceToMove->getIsWhite(); 
	copy.setPiece(targetX, targetY, pieceToMove);
	copy.setPiece(currX, currY, nullptr);
	return copy.isAttacked(copy.findKing(white).first, copy.findKing(white).second, white);
}

bool Board::Mate(bool white) {
	bool result = true;
	for (char c = 'a'; c <= 'h'; c++) {
		for (int i = 1; i <= 8; i++) {
			if (this->getPiece(c, i) && this->getPiece(c, i)->getIsWhite() == white) {
				if (hasValidMoves(c, i))
					result = false;
			}
		}
	}
	//cout << result << endl;
	return result;
}


bool Board::validMove(char currX, int currY, char targetX, int targetY) {
	Piece* pieceToMove = this->getPiece(currX, currY);
	if (this->getPiece(targetX, targetY) && this->getPiece(targetX, targetY)->getIsWhite() == pieceToMove->getIsWhite()) return false;

	bool move;
	if (pieceToMove->name() == "King") {
		move =  pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY) ||
			kingSideCastle(currX, currY, targetX, targetY) || queenSideCastle(currX, currY, targetX, targetY);
	}
	else if (pieceToMove->name() != "Pawn") {
		move =  pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY);
	}
	else {
		if (!this->getPiece(targetX, targetY)) {
			move = (pieceToMove->movementPattern(currX, currY, targetX, targetY) && !blockedPath(pieceToMove, currX, currY, targetX, targetY)) ||
					enPassant(currX, currY, targetX, targetY);
		}
		else {
			move = pawnTakeRule(pieceToMove, currX, currY, targetX, targetY);
		}
	}
	return move && !this->checkAfterPly(currX, currY, targetX, targetY);
}

bool Board::hasValidMoves(char currX, int currY) {
	bool result = false;
	for (char c = 'a'; c <= 'h'; c++) {
		for (int i = 1; i <= 8; i++) {
			if ((c != currX || i != currY) && validMove(currX, currY, c, i))
				result = true;
		}
	}
	return result;
}