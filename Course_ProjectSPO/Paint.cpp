#include "Paint.h"

void Paint::printCharTimes(char c, int t) {
	for (int i = 0; i < t; i++) cout << c;
}

void Paint::paintHeader(char filler) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < 9; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i == 3 || i == 4 || i == 5) {
			printCharTimes(filler, 51);
			SetConsoleCursorPosition(hConsole, { 68, i });
			printCharTimes(filler, 52);
			continue;
		}
		printCharTimes(filler, 120);
	}
}


void Paint::paintFunctionsHeader(char filler) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 9; i < 30; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21) {
			printCharTimes(filler, 50);
			SetConsoleCursorPosition(hConsole, { 70 , i });
			printCharTimes(filler, 50);
			continue;
		}
		printCharTimes(filler, 120);
	}
}

void Paint::paintShowMenu(char filler) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < 30; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i > 10 && i < 20) {
			printCharTimes(filler, 28);
			SetConsoleCursorPosition(hConsole, { 52 , i });
			printCharTimes(filler, 28);
			continue;
		}
		printCharTimes(filler, 80);
	}
}

void Paint::paintKillMenu(char filler) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < 30; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i > 10 && i < 16) {
			printCharTimes(filler, 28);
			SetConsoleCursorPosition(hConsole, { 52 , i });
			printCharTimes(filler, 28);
			continue;
		}
		printCharTimes(filler, 80);
	}
}

void Paint::paintPriorityMenu(char filler)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < 30; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i > 8 && i < 26) {
			printCharTimes(filler, 28);
			SetConsoleCursorPosition(hConsole, { 55 , i });
			printCharTimes(filler, 28);
			continue;
		}
		printCharTimes(filler, 80);
	}
}
