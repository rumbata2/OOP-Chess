#pragma once
#include "Box.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
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
	Knight* whiteKnights[2];
	Knight* blackKnights[2];
	Bishop* whiteBishops[2];
	Bishop* blackBishops[2];
	King* whiteKing;
	King* blackKing;


public:
	Board();
	~Board();
	void initializeBoard();
	void getBoxesInfo();
	Piece* getPiece(char x, int y);
	void setPiece(char x, int y, Piece* piece);

	bool pawnTakeRule(Piece* piece, char currX, int currY, char targetX, int targetY);
	bool blockedPath(Piece* pieceToMove, char currX, int currY, char targetX, int targetY);
	bool validMove(char currX, int currY, char targetX, int targetY);

};

pair<char, int> convertToChessCoordinates(int i, int j);
pair<int, int> convertToMatrixCoordinates(char x, int y);