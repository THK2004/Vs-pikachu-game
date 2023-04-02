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

	int status = 0;
	int mode = 0;
	int exit = 0;

	
	//Board board(TOP, LEFT, HEIGHT, WIDTH);
	//board.drawL(board.pBoard[0][2], board.pBoard[2][0], board.pBoard[2][2
	//board.drawZ(board.pBoard[0][2], board.pBoard[2][0], board.pBoard[1][0], board.pBoard[1][2]);
	//board.drawU(board.pBoard[1][2], board.pBoard[2][1], board.pBoard[0][1], board.pBoard[0][2]);
	//cin.get();

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