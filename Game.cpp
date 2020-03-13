#include "stdafx.h"
#define OLC_PGE_APPLICATION
#include "Game.h"


bool Game::OnUserCreate() {
	sprites[0] = new olc::Sprite("Sprites/WhitePawn.png");
	sprites[1] = new olc::Sprite("Sprites/WhiteRook.png");
	sprites[2] = new olc::Sprite("Sprites/WhiteKnight.png");
	sprites[3] = new olc::Sprite("Sprites/WhiteBishop.png");
	sprites[4] = new olc::Sprite("Sprites/WhiteQueen.png");
	sprites[5] = new olc::Sprite("Sprites/WhiteKing.png");
	sprites[6] = new olc::Sprite("Sprites/BlackPawn.png");
	sprites[7] = new olc::Sprite("Sprites/BlackRook.png");
	sprites[8] = new olc::Sprite("Sprites/BlackKnight.png");
	sprites[9] = new olc::Sprite("Sprites/BlackBishop.png");
	sprites[10] = new olc::Sprite("Sprites/BlackQueen.png");
	sprites[11] = new olc::Sprite("Sprites/BlackKing.png");
	
	drawSquares();
	Board* b = new Board();


	b->initializeBoard();
	drawBoard(b);
	return true;
};

bool Game::OnUserUpdate(float elapsedTime) {
	if (GetMouse(0).bPressed) {
		if (0 <= GetMouseX() && GetMouseY() < ScreenWidth() &&
			0 <= GetMouseY() && GetMouseY() < ScreenHeight()) {
			int32_t xBegin = GetMouseX() - (GetMouseX() % 80);
			int32_t yBegin = GetMouseY() - (GetMouseY() % 80);
			DrawRect(xBegin, yBegin, PIECE_SIZE - 1, PIECE_SIZE - 1, olc::GREEN);
		}
	}
	
	return true;
}

void Game::drawSquares() {
	olc::Pixel brown(89, 60, 31);
	int32_t posX = 0, posY = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((i + j) % 2 == 0) {
				FillRect(posX, posY, PIECE_SIZE - 1, PIECE_SIZE - 1);
			}
			else {
				FillRect(posX, posY, PIECE_SIZE - 1, PIECE_SIZE - 1, brown);
			}
			posX += PIECE_SIZE;
		}
		posX = 0;
		posY += PIECE_SIZE;
	}
}

olc::Sprite* Game::getPieceSprite(Piece* piece) {
	if (piece->getIsWhite()) {
		if (piece->name() == "Pawn")
			return sprites[0];
		else if (piece->name() == "Rook")
			return sprites[1];
		else if (piece->name() == "Knight")
			return sprites[2];
		else if (piece->name() == "Bishop")
			return sprites[3];
		else if (piece->name() == "Queen")
			return sprites[4];
		else if (piece->name() == "King")
			return sprites[5];
	}
	else {
		if (piece->name() == "Pawn")
			return sprites[6];
		else if (piece->name() == "Rook")
			return sprites[7];
		else if (piece->name() == "Knight")
			return sprites[8];
		else if (piece->name() == "Bishop")
			return sprites[9];
		else if (piece->name() == "Queen")
			return sprites[10];
		else //if (piece->name() == "King")
			return sprites[11];
	}
}

void Game::drawPiece(char x, int y, olc::Sprite* spr) {
	DrawSprite(convertToMatrixCoordinates(x, y).second * 80, convertToMatrixCoordinates(x, y).first * 80, spr);
}

void Game::drawBoard(Board* board) {
	SetPixelMode(olc::Pixel::ALPHA);

	for (int y = 1; y <= 8; y++) {
		for (char x = 'a'; x <= 'h'; x++) {
			if (board->getPiece(x, y)) { 
				drawPiece(x, y, getPieceSprite(board->getPiece(x, y)));
			}
		}
	}

	SetPixelMode(olc::Pixel::NORMAL);
}