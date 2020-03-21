#pragma once
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include <vector>
#include <iostream>
using namespace std;


class Board
{
private:
	vector<vector<Piece*>> squares;

public:
	Board();
	void initializeBoard();

	Piece* getPiece(char x, int y);
	void setPiece(char x, int y, Piece* piece);
	pair<char, int> findKing(bool white);

	bool kingSideCastle(char currX, int currY, char targetX, int targetY);
	bool queenSideCastle(char currX, int currY, char targetX, int targetY);
	bool pawnTakeRule(Piece* piece, char currX, int currY, char targetX, int targetY);
	bool enPassant(char currX, int currY, char targetX, int targetY);
	bool blockedPath(Piece* pieceToMove, char currX, int currY, char targetX, int targetY);
	int isAttacked(char X, int Y, bool isWhite);
	bool checkAfterPly(char currX, int currY, char targetX, int targetY);
	bool Mate(bool white);


	bool validMove(char currX, int currY, char targetX, int targetY);
	bool hasValidMoves(char currX, int currY);
};

pair<char, int> convertToChessCoordinates(int i, int j);
pair<int, int> convertToMatrixCoordinates(char x, int y);