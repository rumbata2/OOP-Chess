// OOP Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	Game game;

	if (game.Construct(640, 640, 1, 1)) {
		game.Start();
	}
	
    return 0;
}

