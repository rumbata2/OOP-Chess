// OOP Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	Game asd;

	if (asd.Construct(640, 640, 1, 1)) {
		asd.Start();
	}

	/*Board b;
	b.getBoxesInfo();*/

    return 0;
}

