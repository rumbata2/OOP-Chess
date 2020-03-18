#pragma once
#include <string>

using namespace std;
class Piece
{
protected:
	bool isWhite;
	bool hasMoved;
	int plySinceFirstMove;

public:
	Piece(bool = 0, bool = 0, int = 0);
	virtual string name() = 0;
	virtual bool movementPattern(char, int, char, int) = 0;
	bool getIsWhite() {
		return isWhite;
	}
	void enableHasMoved() {
		this->hasMoved = true;
	}
	bool getHasMoved() {
		return hasMoved;
	}
	void incrementPlySinceFirstMove() {
		plySinceFirstMove++;
	}
	int getPlySinceFirstMove() {
		return plySinceFirstMove;
	}
};

