﻿#pragma once

#include <iostream>
#include "console.h"
#include "menu.h"

struct Cell {
	int x = 0;
	int y = 0;
	float x_console = 0.0;										//Vị trí x trên console
	float y_console = 0.0;										//Vị trí y trên console
	char pokemon = '0';									//pokemon = '0' có nghĩa là ô trống.
	bool isSelected = 0;								//0 = ko chọn, 1 = chọn
	void drawCell(int);									//Vẽ ô tại điểm (x, y) 
	void deleteCell();
};

struct Board {
	int top = 0;										//Hoành độ ô bắt đầu của board
	int left = 0;										//Tung độ ô bắt đầu của board
	int height = 0;										//Số hàng
	int width = 0;										//Số cột
	Cell** pBoard = NULL;

	Board(int, int, int, int);							//Init a board

	void drawBoard(int, int, Cell**);					//Vẽ board trên console
	void deleteBoard(int, int, Cell**);					//Xóa board
	void clearBoard(Cell**);							//clear memory
};