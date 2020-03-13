#pragma once
#include "Box.h"
#include "Pawn.h"
#include <vector>
#include <iostream>
using namespace std;


class Board
{
private:
	vector<vector<Box>> boxes;

	Pawn* whitePawns[8];
	


public:
	Board();
	~Board();
	void initializeBoard();
	void getBoxesInfo();
	Piece* getPiece(char x, int y);
};

pair<char, int> convertToChessCoordinates(int i, int j);
pair<int, int> convertToMatrixCoordinates(char x, int y);