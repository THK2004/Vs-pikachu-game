#pragma once

#include <iostream>
#include "console.h"

struct cell {
	int x;
	int y;
	char pokemon;							//pokemon = '0' có nghĩa là ô trống.
	void drawBok();
};

struct board {
	int height;
	int width;

	cell** pBoard;

	void initBoard();
	static void makeBoard();
	static void deleteBoard();

	
};