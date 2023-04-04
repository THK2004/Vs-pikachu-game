#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "gamemode.h"
#include "login.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	Console::hideScrollbar();
	LoginScreen::loginScreen();

	//TOP 26, LEFT 10, HEIGHT 4, WIDTH 5
	//Board board(TOP, LEFT, HEIGHT, WIDTH);
	//board.drawZ(board.pBoard[2][4], board.pBoard[2][2], board.pBoard[1][2], board.pBoard[1][0]);
	//cin.get();
	//board.eraseL(board.pBoard[2][1], board.pBoard[2][0], board.pBoard[0][0]);
	//cin.get();
	
	/*
	GamePlay gameplay;
	pair<int, int> check(-2, -2);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			board.pBoard[i][j].pokemon = '0';
		}
	}

	board.pBoard[0][3].pokemon = 'A';
	board.pBoard[1][1].pokemon = 'A';

	board.pBoard[0][1].pokemon = 'B';
	board.drawBoard(HEIGHT, WIDTH, board.pBoard);

	check = gameplay.check2Cells(board.pBoard, HEIGHT, WIDTH, board.pBoard[0][3], board.pBoard[1][1]);
	Console::gotoXY(0, 0);
	cout << check.first << " " << check.second;*/

	//board.drawI(board.pBoard[0][1], board.pBoard[0][0]);
	//board.drawL(board.pBoard[0][2], board.pBoard[2][0], board.pBoard[2][2]);
	//board.drawZ(board.pBoard[0][2], board.pBoard[2][0], board.pBoard[1][0], board.pBoard[1][2]);
	//board.drawU(board.pBoard[1][2], board.pBoard[2][1], board.pBoard[0][1], board.pBoard[0][2]);
	//cin.get();

	int status = 0;
	int mode = 0;
	int exit = 0;

	status = Menu::mainMenu();
	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
			if (mode == 0)
				GameMode::createNormalGame();
			if (mode == 1)
				GameMode::createHardGame_2DPointerArray();
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