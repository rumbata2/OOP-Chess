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

	b = new Board();

	b->initializeBoard();
	drawBoard(b);
	return true;
};

bool Game::OnUserUpdate(float elapsedTime) {
	if (GetMouse(0).bPressed) {
		char pressedX = convertToChessCoordinates(GetMouseY() / PIECE_SIZE, GetMouseX() / PIECE_SIZE).first;
		int pressedY = convertToChessCoordinates(GetMouseY() / PIECE_SIZE, GetMouseX() / PIECE_SIZE).second;
		int32_t xTileCoord = GetMouseX() - (GetMouseX() % PIECE_SIZE);
		int32_t yTileCoord = GetMouseY() - (GetMouseY() % PIECE_SIZE);
		if (!selectedPiece) { //selecting a piece
			if (b->getPiece(pressedX, pressedY)) {
				if (b->getPiece(pressedX, pressedY)->getIsWhite() == whitesTurn) {
					drawBoard(b);
					DrawRect(xTileCoord, yTileCoord, PIECE_SIZE - 1, PIECE_SIZE - 1, olc::GREEN);
					selectedPiece = b->getPiece(pressedX, pressedY);

					lastPressedX = pressedX;
					lastPressedY = pressedY;
				}
				
			}
		}
		
		else {
			if (b->getPiece(pressedX, pressedY)) {
				if (selectedPiece->getIsWhite() && !b->getPiece(pressedX, pressedY)->getIsWhite()  || //white takes black
					!selectedPiece->getIsWhite() && b->getPiece(pressedX, pressedY)->getIsWhite()) { //black takes white
					if (b->validMove(lastPressedX, lastPressedY, pressedX, pressedY)) {
						b->setPiece(lastPressedX, lastPressedY, nullptr);
						b->setPiece(pressedX, pressedY, selectedPiece);

						drawBoard(b);

						if (!selectedPiece->getHasMoved()) {
							selectedPiece->enableHasMoved();
						}
						for (char c = 'a'; c <= 'h'; c++)
							for (int a = 1; a <= 8; a++)
								if (b->getPiece(c, a))
									if(b->getPiece(c, a)->getHasMoved())
										b->getPiece(c, a)->incrementPlySinceFirstMove();

						selectedPiece = nullptr;
						whitesTurn = !whitesTurn;
					}			
				}
				else { //selecting a different piece of the same color
					selectedPiece = b->getPiece(pressedX, pressedY);
					drawBoard(b);
					DrawRect(xTileCoord, yTileCoord, PIECE_SIZE - 1, PIECE_SIZE - 1, olc::GREEN);

					lastPressedX = pressedX;
					lastPressedY = pressedY;
				}		
			}
			else { // moving
				if (b->validMove(lastPressedX, lastPressedY, pressedX, pressedY)) {
					if (b->kingSideCastle(lastPressedX, lastPressedY, pressedX, pressedY)) {
						b->setPiece(lastPressedX, lastPressedY, nullptr);
						b->setPiece(pressedX, pressedY, selectedPiece);
						b->setPiece(pressedX - 1, pressedY, b->getPiece('h', pressedY));
						b->setPiece('h', pressedY, nullptr);				
					}
					else if (b->queenSideCastle(lastPressedX, lastPressedY, pressedX, pressedY)) {
						b->setPiece(lastPressedX, lastPressedY, nullptr);
						b->setPiece(pressedX, pressedY, selectedPiece);
						b->setPiece(pressedX + 1, pressedY, b->getPiece('a', pressedY));
						b->setPiece('a', pressedY, nullptr);
					}
					else if (b->enPassant(lastPressedX, lastPressedY, pressedX, pressedY)) {
						b->setPiece(lastPressedX, lastPressedY, nullptr);
						b->setPiece(pressedX, pressedY, selectedPiece);
						b->setPiece(pressedX, pressedY + pow(-1, selectedPiece->getIsWhite()), nullptr);
					}
					else {
						b->setPiece(lastPressedX, lastPressedY, nullptr);
						b->setPiece(pressedX, pressedY, selectedPiece);
					}	



					drawBoard(b);
					whitesTurn = !whitesTurn;
					if (!selectedPiece->getHasMoved()) 
						selectedPiece->enableHasMoved();
					for (char c = 'a'; c <= 'h'; c++)
						for (int a = 1; a <= 8; a++)
							if (b->getPiece(c, a))
								if(b->getPiece(c,a)->getHasMoved())
									b->getPiece(c, a)->incrementPlySinceFirstMove();

					selectedPiece = nullptr;
				}
			}	
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
				FillRect(posX, posY, PIECE_SIZE, PIECE_SIZE);
			}
			else {
				FillRect(posX, posY, PIECE_SIZE, PIECE_SIZE, brown);
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

	drawSquares();

	//draw piece sprites
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