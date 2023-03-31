#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "normal.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	Console::hideScrollbar();

	int status = 0;
	int mode = 0;
	int exit = 0;

	/*
	Board board(26, 10, 3, 3);

	GamePlay gameplay;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board.pBoard[i][j].pokemon = '0';

	board.pBoard[0][0].pokemon = 'A';
	board.pBoard[2][1].pokemon = 'A';
	board.pBoard[1][1].pokemon = 'B';
	board.pBoard[2][0].pokemon = 'B';
	board.pBoard[2][2].pokemon = 'B';
	board.drawBoard(3, 3, board.pBoard);

	pair <int, int> check(-2, -2);
	check = gameplay.check2Cells(board.pBoard, 3, 3, board.pBoard[0][0], board.pBoard[2][1]);
	Console::gotoXY(30, 0);
	cout << check.first << " " << check.second;

	board.clearBoard(board.pBoard);
	cin.get();
	*/


	status = Menu::mainMenu();
	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
			if (mode == 0)
				Normal::createNormalBoard();
			if (mode == 3)
				status = Menu::mainMenu();
		}

		if (status == 2) {
			Menu::leaderBoard();
			status = Menu::mainMenu();
		}

		if (status == 3) {
			exit = Menu::exitScreen();
			if (exit == 0)
				status = Menu::mainMenu();
		}
	}

	cin.get();
}