#pragma once
class Piece
{
private:
	char xCoordinate;
	int yCoordinate;
	bool isWhite;

public:
	Piece(char = 'a', int = 0, bool = 0);
	bool validCoordinates(char, int);
};

