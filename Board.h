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
	void beginningPosition();
	void getBoxesInfo();
};

