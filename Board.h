#pragma once
#include "Box.h"
#include "Pawn.h"
#include "Rook.h"
#include <vector>
#include <iostream>
using namespace std;


class Board
{
private:
	vector<vector<Box>> boxes;

	Pawn* whitePawns[8];
	Pawn* blackPawns[8];
	Rook* whiteRooks[2];
	Rook* blackRooks[2];
	


public:
	Board();
	~Board();
	void initializeBoard();
	void getBoxesInfo();
	Piece* getPiece(char x, int y);
};

pair<char, int> convertToChessCoordinates(int i, int j);
pair<int, int> convertToMatrixCoordinates(char x, int y);