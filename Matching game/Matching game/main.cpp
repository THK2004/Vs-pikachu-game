#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "gamemode.h"
#include "login.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	LoginScreen::loginScreen();

	//Board board(TOP, LEFT, HEIGHT, WIDTH);
	//board.drawL(board.pBoard[2][2], board.pBoard[3][2], board.pBoard[3][1]);
	//cin.get();
	//board.shuffle(HEIGHT, WIDTH, board.pBoard);
	//board.drawBoard(HEIGHT, WIDTH, board.pBoard);
	//cin.get();
	//board.drawL(board.pBoard[0][0], board.pBoard[2][0], board.pBoard[2][1]);
	//cin.get();
	//board.eraseL(board.pBoard[0][0], board.pBoard[2][0], board.pBoard[2][1]);
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
			if (mode == 2)
				Menu::helpScreen();
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