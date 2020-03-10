#include "stdafx.h"
#include "Board.h"
#include "Pawn.h"


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

void Board::beginningPosition() {
	for (int i = 0; i < 8; i++) {

	}
}

void Board::getBoxesInfo() {
	for (int i = 0; i < boxes.size(); i++) {
		for (int j = 0; j < boxes[i].size(); j++) {
			cout << boxes[i][j].getXCoordinate() << " " << boxes[i][j].getYCoordinate() << "\n";
		}
	}
}