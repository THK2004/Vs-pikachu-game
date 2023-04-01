#include "board.h"

Board::Board(int _top, int _left, int _height, int _width) {
	top = _top;
	left = _left;
	height = _height;
	width = _width;

	pBoard = new Cell * [height];
	for (int i = 0; i < height; i++) {
		pBoard[i] = new Cell[width];
		for (int j = 0; j < width; j++) {
			pBoard[i][j].x_console = j + float(top) / 10; 
			pBoard[i][j].y_console = i + float(left) / 4;
			pBoard[i][j].x = i;
			pBoard[i][j].y = j;
		}
	}

	int loop = (width * height) / 2;
	while (loop) {
		int index, time = 2;
		char c = 'A' + rand() % 26;
		while (time) {
			index = rand() % (width * height);
			if (pBoard[index / width][index % width].pokemon == '0') {
				pBoard[index / width][index % width].pokemon = c;
				time--;
			}
		}
		loop--;
	}

	drawBoard(height, width, pBoard);
	//Menu::printDoubleRectangle(top - 2, left - 1, width * 10 + 3, height * 4 + 2);
}

void Board::clearBoard(Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		delete[] pBoard[i];
		pBoard[i] = NULL;
	}
	delete[] pBoard;
	pBoard = NULL;
}

char box[5][12] = {
			{" --------- "},
			{"|         |"},
			{"|         |"},
			{"|         |"},
			{" --------- "}
};

void Board::drawBoard(int height, int width, Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pBoard[i][j].drawCell(WHITE);
		}
	}
	Menu::printDoubleRectangle(top - 2, left - 1, width * 10 + 3, height * 4 + 2);
}

void Cell::drawCell(int color) {
	if (pokemon == '0')
		return;

	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x_console * 10), int(y_console * 4) + i);
		cout << box[i];
	}

	//if (isCursorHere) {
	Console::setColor(color, BLACK);

	for (int i = 1; i < 4; i++) {
		Console::gotoXY(int(x_console * 10) + 1, int(y_console * 4) + i);
		cout << "         ";
	}

	Console::gotoXY(int(x_console * 10) + 5, int(y_console * 4) + 2);
	cout << pokemon;

	Console::setColor(WHITE, BLACK);
	//}
	/*
	else{
		Console::gotoXY(int(x_console * 10) + 5, int(y_console * 4) + 2);
		cout << pokemon;
		Console::setColor(WHITE, BLACK);
	}
	*/
}

void Cell::deleteCell() {
	Console::setColor(WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x_console * 10), int(y_console * 4) + i);
		cout << "           ";
	}
}

void Board::deleteBoard(int hieght, int width, Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pBoard[i][j].deleteCell();
		}
	}
}


void Board::drawI(Cell cell_1, Cell cell_2) {
	Console::setColor(WHITE, BLACK);
	int x1 = int(cell_1.x_console * 10) + 5;
	int x2 = int(cell_2.x_console * 10) + 5;
	int y1 = int(cell_1.y_console * 4) + 2;
	int y2 = int(cell_2.y_console * 4) + 2;

	if (x1 == x2) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= y2 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}

		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}

	// 2 Block cùng hàng ngang
	if (y1 == y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= x2 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
}

void Board::drawL(Cell cell_1, Cell cell_2, Cell cell_between) {
	Console::setColor(WHITE, BLACK);
	int x1 = int(cell_1.x_console * 10) + 5;
	int x2 = int(cell_2.x_console * 10) + 5;
	int y1 = int(cell_1.y_console * 4) + 2;
	int y2 = int(cell_2.y_console * 4) + 2;
	int xC = int(cell_between.x_console * 10) + 5;
	int yC = int(cell_between.y_console * 4) + 2;

	if (xC < x2 && yC > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y2 + 2; i <= yC - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	// Dạng 2: Down-right  
	if (xC < x2 && yC < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = y1 - 2; i >= yC + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	// Dạng 3: Down-left 
	if (yC < y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}

	// Dạng 4: Up-left 
	if (yC > y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC - 1; i >= y2 + 2; i--) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}
}

void Board::drawZ(Cell cell_1, Cell cell_2, Cell cell_c1, Cell cell_c2) {
	Console::setColor(WHITE, BLACK);
	int x1 = int(cell_1.x_console * 10) + 5;
	int x2 = int(cell_2.x_console * 10) + 5;
	int y1 = int(cell_1.y_console * 4) + 2;
	int y2 = int(cell_2.y_console * 4) + 2;
	int xC1 = int(cell_c1.x_console * 10) + 5;
	int yC1 = int(cell_c1.y_console * 4) + 2;
	int xC2 = int(cell_c2.x_console * 10) + 5;
	int yC2 = int(cell_c2.y_console * 4) + 2;
	// Vẽ Z cũng có 4 dạng 

	// Dạng 1: Right-Down-Right
	if (xC1 > x1 && yC1 > y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	// Dạng 2: Right-Up-Right
	if (xC1 > x1 && yC1 < y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	// Dạng 3: Up-right-up
	if (xC1 < x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}

	// Dạng 4: Down-right-down
	if (xC1 > x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
}

void Board::drawU(Cell cell_1, Cell cell_2, Cell cell_c1, Cell cell_c2) {
	Console::setColor(WHITE, BLACK);
	int x1 = int(cell_1.x_console * 10) + 5;
	int x2 = int(cell_2.x_console * 10) + 5;
	int y1 = int(cell_1.y_console * 4) + 2;
	int y2 = int(cell_2.y_console * 4) + 2;
	int xC1 = int(cell_c1.x_console * 10) + 5;
	int yC1 = int(cell_c1.y_console * 4) + 2;
	int xC2 = int(cell_c2.x_console * 10) + 5;
	int yC2 = int(cell_c2.y_console * 4) + 2;

	if (xC1 < x1 && yC1 < y2) {
		for (int i = xC1; i <= x1 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	if (xC1 > x1 && yC1 < y2) {
		for (int i = xC1; i >= x1 + 2; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}

	if (yC1 < y1 && xC1 < x2) {
		for (int i = yC1 + 1; i <= y1 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}

	if (xC1 < x2 && yC1 > y1) {
		for (int i = yC1 - 1; i >= y1 + 2; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}
}
