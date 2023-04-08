#pragma once

#include "console.h"
#include "board.h"
#include "gameplay.h"
#include "linkedlistutility.h"
#include <cmath>
#include <ctime>

//For normal mode
#define TOP 28	//Vị trí của board trên console thụt vào 28 dấu spaces và 8 dấu xuống hàng
#define LEFT 8
#define HEIGHT 4
#define WIDTH 5

//For hard mode
#define H_TOP 28
#define H_LEFT 8
#define H_HEIGHT 4
#define H_WIDTH 5

struct GameMode {
	static void createNormalGame();
	static void createHardGame_2DPointerArray();
	static void createHardGame_LinkedList();
};

void moveSuggestion(int, int, Cell**);