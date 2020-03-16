#pragma once
#include "olcPixelGameEngine.h"
#include "Board.h"
#include <iostream>
#include <typeinfo>



const int32_t PIECE_SIZE = 80;

class Game : public olc::PixelGameEngine {
private:
	olc::Sprite* sprites[12];
	Board* b = nullptr;
	int ctr = 0;
	Piece* selectedPiece = nullptr;
	char lastPressedX;
	int lastPressedY;
	bool whitesTurn = 1;


public:
	Game() {
		sAppName = "chess";
	}

	bool OnUserCreate() override;
	bool OnUserUpdate(float elapsedtime);


	olc::Sprite* getPieceSprite(Piece* piece);
	void drawSquares();
	void drawPiece(char x, int y, olc::Sprite* spr);
	void drawBoard(Board* board);
};

