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
	}
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

	blackRooks[0] = new Rook('a', 8, 0);
	blackRooks[1] = new Rook('h', 8, 0);
	boxes[0][0].setPiece(blackRooks[0]);
	boxes[0][7].setPiece(blackRooks[1]);
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