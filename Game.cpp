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

	//DrawBeginningPosition();
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




void Game::DrawBeginningPosition() {
	SetPixelMode(olc::Pixel::ALPHA);
	for (int i = 0; i <= 560; i += 80) {
		DrawSprite(i, 480, sprites[0]); //white pawns
		DrawSprite(i, 80, sprites[6]); //black pawns
	}
	for (int i = 1, x = 0; i <= 5; i++, x += 80) {
		DrawSprite(x, 560, sprites[i]); //white
		DrawSprite(x, 0, sprites[i + 6]); //black
	}
	DrawSprite(400, 560, sprites[3]); DrawSprite(400, 0, sprites[9]);
	DrawSprite(480, 560, sprites[2]); DrawSprite(480, 0, sprites[8]);
	DrawSprite(560, 560, sprites[1]); DrawSprite(560, 0, sprites[7]);
	SetPixelMode(olc::Pixel::NORMAL);
};

void Game::drawPiece(char x, int y, olc::Sprite* spr) {
	DrawSprite(convertToMatrixCoordinates(x, y).second * 80, convertToMatrixCoordinates(x, y).first * 80, spr);
}

void Game::drawBoard(Board* board) {
	SetPixelMode(olc::Pixel::ALPHA);

	for (int y = 1; y <= 8; y++) {
		for (char x = 'a'; x <= 'h'; x++) {
			if (board->getPiece(x, y)) {
				//cout << convertToMatrixCoordinates(x, y).first << " " << convertToMatrixCoordinates(x, y).second << "\n";
				//DrawSprite(convertToMatrixCoordinates(x, y).first * 80, convertToMatrixCoordinates(x, y).second * 80, sprites[0]);
				drawPiece(x, y, sprites[0]);
			}
		}
	}

	SetPixelMode(olc::Pixel::NORMAL);
}