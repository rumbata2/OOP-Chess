#pragma once
#include "olcPixelGameEngine.h"
#include "Board.h"
#include <iostream>
#include <typeinfo>



const int32_t PIECE_SIZE = 80;

class Game : public olc::PixelGameEngine {
public:
	Game() {
		sAppName = "chess";
	}
	olc::Sprite* sprites[12];

	bool OnUserCreate() override;
	bool OnUserUpdate(float elapsedtime);


	//void DrawBeginningPosition();
	olc::Sprite* getPieceSprite(Piece* piece);
	void drawSquares();
	void drawPiece(char x, int y, olc::Sprite* spr);
	void drawBoard(Board* board);
};

