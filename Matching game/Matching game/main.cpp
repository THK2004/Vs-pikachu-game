#include "console.h"
#include "menu.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	Console::hideScrollbar();

	int status = 0;
	int mode = 0;
	int exit = 0;
	status = Menu::mainMenu();

	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
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