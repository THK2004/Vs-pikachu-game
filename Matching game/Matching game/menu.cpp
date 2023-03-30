#include "menu.h"


int Menu::mainMenu() {
    Console::playSound(MENU_SOUND);
    Console::setColor(WHITE, BLACK);

    printLogo();

    printDoubleRectangle(59, 13, 15, 13);
    printRectangle(60, 14, 13, 2);
    printRectangle(60, 17, 13, 2);
    printRectangle(60, 20, 13, 2);
    printRectangle(60, 23, 13, 2);

    int choice[4] = { 0,0,0,0 };
    int key = 0;
    int curChoice = 0;


    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(62, 15);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NEW GAME ";
        }
        else {
            Console::gotoXY(62, 15);
            Console::setColor(WHITE, BLACK);
            cout << " NEW GAME ";
        }
        if (choice[1]) {
            Console::gotoXY(62, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " CONTINUE ";
        }
        else {
            Console::gotoXY(62, 18);
            Console::setColor(WHITE, BLACK);
            cout << " CONTINUE ";
        }

        if (choice[2]) {
            Console::gotoXY(61, 21);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " LEADERBOARD ";
        }
        else {
            Console::gotoXY(61, 21);
            Console::setColor(WHITE, BLACK);
            cout << " LEADERBOARD ";
        }

        if (choice[3]) {
            Console::gotoXY(64, 24);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " EXIT ";
        }
        else {
            Console::gotoXY(64, 24);
            Console::setColor(WHITE, BLACK);
            cout << " EXIT ";
        }

        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_UP:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice > 0) curChoice--;
                else curChoice = 3;
                break;
            case KEY_DOWN:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice < 3) curChoice++;
                else curChoice = 0;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

int Menu::modeSelectMenu() {
    Console::playSound(MENU_SOUND);
    Console::setColor(WHITE, BLACK);

    printLogo();

    printDoubleRectangle(59, 13, 15, 13);
    printRectangle(62, 14, 10, 2);
    printRectangle(62, 17, 10, 2);
    printRectangle(62, 20, 10, 2);
    printRectangle(62, 23, 10, 2);

    int choice[4] = { 0,0,0,0 };
    int key = 0;
    int curChoice = 0;


    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(64, 15);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NORMAL ";
        }
        else {
            Console::gotoXY(64, 15);
            Console::setColor(WHITE, BLACK);
            cout << " NORMAL ";
        }
        if (choice[1]) {
            Console::gotoXY(65, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " HARD ";
        }
        else {
            Console::gotoXY(65, 18);
            Console::setColor(WHITE, BLACK);
            cout << " HARD ";
        }

        if (choice[2]) {
            Console::gotoXY(65, 21);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " HELP ";
        }
        else {
            Console::gotoXY(65, 21);
            Console::setColor(WHITE, BLACK);
            cout << " HELP ";
        }

        if (choice[3]) {
            Console::gotoXY(65, 24);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " BACK ";
        }
        else {
            Console::gotoXY(65, 24);
            Console::setColor(WHITE, BLACK);
            cout << " BACK ";
        }

        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_UP:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice > 0) curChoice--;
                else curChoice = 3;
                break;
            case KEY_DOWN:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice < 3) curChoice++;
                else curChoice = 0;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

void Menu::printRectangle(int left, int top, int width, int height)
{
    Console::gotoXY(left, top);
    putchar(218);
    for (int i = 0; i < width; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < height; i++)
    {
        Console::gotoXY(left, top + i + 1);
        putchar(179);
        Console::gotoXY(left + width + 1, top + i + 1);
        putchar(179);
    }

    Console::gotoXY(left, top + i);
    putchar(192);
    for (i = 0; i < width; i++)
        putchar(196);
    putchar(217);
}

void Menu::printDoubleRectangle(int left, int top, int width, int height)
{
    Console::gotoXY(left, top);
    putchar(201);
    for (int i = 0; i < width; i++)
        putchar(205);
    putchar(187);

    int i = 0;
    for (; i < height; i++)
    {
        Console::gotoXY(left, top + i + 1);
        putchar(186);
        Console::gotoXY(left + width + 1, top + i + 1);
        putchar(186);
    }

    Console::gotoXY(left, top + i);
    putchar(200);
    for (i = 0; i < width; i++)
        putchar(205);
    putchar(188);
}

void Menu::printAnimation()
{
    srand(time(NULL));
    Console::playSound(WIN_SOUND);
    printLogo();
    printPikachu();
    char symbolpos[] = { 5,0,19,0,33,0,47,0,61,0,75,0,89,0,0,103,5,13,19,
                         13,33,13,47,13,61,13,75,13,89,13,13,103,13,18,26,18,40,18,
                         54,18,68,18,82,18,18,96,5,24,19,24,33,24,47,24,61,24,75,24,
                         89,24,24,103,12,30,26,30,40,30,54,30,68,30,82,30,96,30};
    int n = sizeof(symbolpos) / sizeof(symbolpos[0]) / 2;
    bool turn = 0;
    unsigned char symbol[] = {4,15};
    int loop = 10;
    while (loop--)
    {
        for (int i = 0; i < n; i += 2)
        {
            Console::setColor(WHITE, rand()%16);
            Console::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
            putchar(symbol[turn]);
        }
        for (int i = 1; i < n; i += 2)
        {
            Console::setColor(WHITE, rand()%16);
            Console::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
            putchar(symbol[!turn]);
        }
        Console::gotoXY(0, 0);
        turn = !turn;
        Sleep(400);
    }
    Console::setColor(WHITE, BLACK);
    system("cls");
}

void Menu::printLogo() {
    Console::gotoXY(35, 2);
    cout << " ______    __   __  ___      ___       ______  __    __   __    __";
    Console::gotoXY(35, 3);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    Console::gotoXY(35, 4);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    Console::gotoXY(35, 5);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    Console::gotoXY(35, 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    Console::gotoXY(35, 7);
    cout << "|__|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";
}

void Menu::printPikachu() {
    Console::gotoXY(105, 11);
    cout << "-%#=.                            .::     ";
    Console::gotoXY(105, 12);
    cout << " =@%---:                    .--=%@@-     ";
    Console::gotoXY(105, 13);
    cout << "  :%+----:                :==---@%:      ";
    Console::gotoXY(105, 14);
    cout << "    -------:    ....    .------+=    ... ";
    Console::gotoXY(105, 15);
    cout << "      :-----::---------------:. .::----- ";
    Console::gotoXY(105, 16);
    cout << "         :=---------------::::---------: ";
    Console::gotoXY(105, 17);
    cout << "         :----------------=-----------=  ";
    Console::gotoXY(105, 18);
    cout << "         :-+#-+------==+#-=-----------:  ";
    Console::gotoXY(105, 19);
    cout << "         --+%%+---=---#%#---------::..   ";
    Console::gotoXY(105, 20);
    cout << "        .##*------------=+*+---.         ";
    Console::gotoXY(105, 21);
    cout << "         *##+-----------###*----.        ";
    Console::gotoXY(105, 22);
    cout << "          ++------------=*= ------       ";
    Console::gotoXY(105, 23);
    cout << "          --------------------:..        ";
    Console::gotoXY(105, 24);
    cout << "         ------------------+#+           ";
    Console::gotoXY(105, 25);
    cout << "        --------=---=-------:            ";
    Console::gotoXY(105, 26);
    cout << "       ----------=-=---------.           ";
    Console::gotoXY(105, 27);
    cout << "    -=-=---------=-=-----------=         ";
    Console::gotoXY(105, 28);
    cout << "     -==--=------=-=--------===.         ";
    Console::gotoXY(105, 29);
    cout << "      .======---===+---======:           ";
}

int Menu::exitScreen() {
    printLogo();
    Console::setColor(WHITE, BLACK);
    printDoubleRectangle(59, 14, 20, 2);
    printRectangle(62, 17, 4, 2);
    printRectangle(70, 17, 5, 2);
    Console::gotoXY(60, 15);
    cout << "Do you want to quit?";

    int choice[2] = {0,0};
    int key = 0;
    int curChoice = 0;

    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(63, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NO ";
        }
        else {
            Console::gotoXY(63, 18);
            Console::setColor(WHITE, BLACK);
            cout << " NO ";
        }
        if (choice[1]) {
            Console::gotoXY(71, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " YES ";
        }
        else {
            Console::gotoXY(71, 18);
            Console::setColor(WHITE, BLACK);
            cout << " YES ";
        }
        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_RIGHT:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice == 0) curChoice++;
                else curChoice--;
                break;
            case KEY_LEFT:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice == 0) curChoice++;
                else curChoice--;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

void Menu::leaderBoard() {
    Console::setColor(WHITE, BLACK);
    cout << R"(
	                       _      ______          _____  ______ _____  ____   ____          _____  _____  
	                      | |    |  ____|   /\   |  __ \|  ____|  __ \|  _ \ / __ \   /\   |  __ \|  __ \ 
	                      | |    | |__     /  \  | |  | | |__  | |__) | |_) | |  | | /  \  | |__) | |  | |
	                      | |    |  __|   / /\ \ | |  | |  __| |  _  /|  _ <| |  | |/ /\ \ |  _  /| |  | |
	                      | |____| |____ / ____ \| |__| | |____| | \ \| |_) | |__| / ____ \| | \ \| |__| |
	                      |______|______/_/    \_\_____/|______|_|  \_\____/ \____/_/    \_\_|  \_\_____/                                                                 
	)";
    
    
    Console::gotoXY(5, 11);
    cout << "_________________________________________________________________________________________________________________________________________";
    
    for (int j = 0; j < 126; j += 25) {
        for (int i = 0; i < 22; i++) {
            Console::gotoXY(j + 10, i + 9);
            cout << "|";
        }
    }

    printRectangle(54,32,40,2);
    Console::gotoXY(55, 33);
    cout << "PRESS ANY BUTTON TO RETURN TO MAIN MENU!";

    int key = _getch();
    system("cls");
    return;
}