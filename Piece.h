#pragma once
#include <string>

using namespace std;
class Piece
{
protected:
	char xCoordinate;
	int yCoordinate;
	bool isWhite;

public:
	Piece(char = 'a', int = 1, bool = 0);
	bool validCoordinates(char, int);
	virtual string name() = 0;
	virtual bool canMove(char, int, char, int) = 0;
	bool getIsWhite() {
		return isWhite;
	}
	char getX() {
		return xCoordinate;
	}
	int getY() {
		return yCoordinate;
	}
};

