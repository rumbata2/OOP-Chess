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