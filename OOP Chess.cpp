// OOP Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Board.h"

const int32_t PIECE_SIZE = 80;

class ChessGame : public olc::PixelGameEngine {
public:
	ChessGame() {
		sAppName = "xixi";
	}

	olc::Sprite* sprites[12];

	bool OnUserCreate() override {
		olc::Pixel brown(89, 60, 31);
		int32_t posX = 0, posY = 0;
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


		for (int i = 1; i <= 8; i ++) {
			for (int j = 1; j <= 8; j++) {
				if ((i + j) % 2 == 0) {
					FillRect(posX, posY, PIECE_SIZE-1, PIECE_SIZE-1);
				}
				else {
					FillRect(posX, posY, PIECE_SIZE-1, PIECE_SIZE-1, brown);
				}
				posX += PIECE_SIZE;
			}
			posX = 0;
			posY += PIECE_SIZE;
		}

		DrawBeginningPosition();
		return true;
	}

	bool OnUserUpdate(float elapsedtime) override {
		return true;
	}

	void DrawBeginningPosition() {
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
};

int main()
{
	//ChessGame asd;

	/*if (asd.Construct(640, 640, 1, 1)) {
		asd.Start();
	}*/

	Board b;
	b.getBoxesInfo();

    return 0;
}

