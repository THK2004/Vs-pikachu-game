#pragma once

#include "console.h"
#include "board.h"
#include "gameplay.h"

#define HEIGHT 3
#define WIDTH 4

struct Normal {
	static void createNormalBoard();
	void playNormal();
	void deleteNormalBoard();
};