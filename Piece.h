#pragma once
class Piece
{
protected:
	char xCoordinate;
	int yCoordinate;
	bool isWhite;
	virtual bool canMove(char, int, char, int) = 0;

public:
	Piece(char = 'a', int = 0, bool = 0);
	bool validCoordinates(char, int);
};

