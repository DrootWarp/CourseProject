#include "GUI.h"

void printCharTimes(char c, int t) {
	for (int i = 0; i < t; i++) cout << c;
}

void paintHeader(char filler) {
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

void paintShow(char filler){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, { 50, 13 });
		printCharTimes(filler, 1);
	}

void paintKill(char filler){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { 50, 15 });
	printCharTimes(filler, 1);
}

void paintChange(char filler) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { 50, 17 });
	printCharTimes(filler, 1);
}

void paintFunctionsHeader(char filler){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 9; i < 30; i++) {
		SetConsoleCursorPosition(hConsole, { 0, i });
		if (i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 ) {
			printCharTimes(filler, 50);
			SetConsoleCursorPosition(hConsole, { 70 , i });
			printCharTimes(filler, 50);
			continue;
		}
		printCharTimes(filler, 120);
	}
}


void GUI::Menu()
{
	system("mode con cols=120 lines=30");
	system("cls");
	int mod = 0;
	char a;
	char filler = '#';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hConsole, { 52, 4 });
	cout << "PROCESS MANAGER";

	SetConsoleCursorPosition(hConsole, { 52, 14 });
	cout << "Show process list";

	SetConsoleCursorPosition(hConsole, { 52, 16 });
	cout << "Kill process";

	SetConsoleCursorPosition(hConsole, { 52, 18 });
	cout << "Change priority";

	SetConsoleCursorPosition(hConsole, { 52, 20 });
	cout << "Run process";

	paintHeader(filler);
	paintFunctionsHeader('=');

	SetConsoleCursorPosition(hConsole, { 50, 13 });
	cout << "=>";

	while (true) {
		SetConsoleCursorPosition(hConsole, { 0, 0 });
		switch (a = _getch()) {
		case 80: {
			if (mod < 3) mod++;
			break;
		}
		case 72: {
			if (mod > 0) mod--;
			break;
		}
		case '\r': {
			switch (mod) {
			case 0: {
				system("cls");
				_getch();
				printf("Show");
				GUI::Menu();
				return;
			}
			case 1: {
				system("cls");
				_getch();
				printf("Kill");
				GUI::Menu();
				return;
			}
			case 2: {
				system("cls");
				_getch();
				printf("Change");
				GUI::Menu();
				return;
			}
			case 3: {
				system("cls");
				_getch();
				printf("Run");
				GUI::Menu();
				return;
			}
			}
		}
		}
		switch (mod) {
		case 0: {
			SetConsoleCursorPosition(hConsole, { 50, 13 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 50, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "  ";
			break;
		}
		case 1: {
			SetConsoleCursorPosition(hConsole, { 50, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 15 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 50, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "  ";
			break;
		}
		case 2: {
			SetConsoleCursorPosition(hConsole, { 50, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 17 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "  ";
			break;
		}
		case 3: {
			SetConsoleCursorPosition(hConsole, { 50, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "=>";
			break;
		}
		}
		//cout << ' ';
	}




}

void GUI::ChangePriorityMenu()
{
}

void GUI::printTableLine()
{
	for (short i = 0; i < 106; i++) printf_s("%c", '*');
	printf_s("\n");
}

void GUI::ShowProcessListMenu()
{
	system("mode con cols=120 lines=500");
}

void GUI::RunProcessMenu()
{
}

