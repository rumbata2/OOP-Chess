#pragma once
#include "Box.h"
#include <vector>
#include <iostream>
using namespace std;
class Board
{
private:
	vector<vector<Box>> boxes;

public:
	Board();
	void getBoxesInfo() {
		for (int i = 0; i < boxes.size(); i++) {
			for (int j = 0; j < boxes[i].size(); j++) {
				cout << boxes[i][j].getXCoordinate() << " " << boxes[i][j].getYCoordinate() << "\n";
			}
		}
	}
};

