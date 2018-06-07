#include "GUI.h"

void GUI::Menu()
{
	Paint paint;
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

    paint.paintHeader(filler);
	paint.paintFunctionsHeader('=');

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
				GUI::ShowProcessListMenu();
				return;
			}
			case 1: {
				system("cls");
				GUI::KillProcessMenu();
				return;
			}
			case 2: {
				system("cls");
				printf("Change");
				GUI::ChangePriorityMenu();
				return;
			}
			case 3: {
				system("cls");
				GUI::RunProcessMenu();
				return;
			}
			}
		}
		case 27: {
			exit(0);
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
	system("mode con cols=80 lines=30");
	system("cls");
	int mod = 0;
	char a;
	char filler = '#';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Priority;

	SetConsoleCursorPosition(hConsole, { 52, 12 });
	cout << "Choose priority rate: ";

	SetConsoleCursorPosition(hConsole, { 52, 14 });
	cout << "High";

	SetConsoleCursorPosition(hConsole, { 52, 16 });
	cout << "Above average";

	SetConsoleCursorPosition(hConsole, { 52, 18 });
	cout << "Average";

	SetConsoleCursorPosition(hConsole, { 52, 20 });
	cout << "Below average";

	SetConsoleCursorPosition(hConsole, { 52, 22 });
	cout << "Low";

	SetConsoleCursorPosition(hConsole, { 47, 11 });
	cout << "=>";
	while (true) {
		SetConsoleCursorPosition(hConsole, { 0, 0 });
		switch (a = _getch()) {
		case 80: {
			if (mod < 5) mod++;
			break;
		}
		case 72: {
			if (mod > 0) mod--;
			break;
		}
		case 8: {
			GUI::Menu();
			break;
		}
		case '\r': {
			switch (mod) {
			case 0: {
				system("cls");
				GUI::ShowProcessListMenu();
				return;
			}
			case 1: {
				system("cls");
				_getch();
				printf("Kill");
				return;
			}
			case 2: {
				system("cls");
				printf("Change");
				GUI::ChangePriorityMenu();
				return;
			}
			case 3: {
				system("cls");
				_getch();
				printf("Run");
				return;
			}
			case 4: {
				system("cls");
				_getch();
				printf("Run");
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
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "  ";
			break;
		}
		case 4: {
			SetConsoleCursorPosition(hConsole, { 50, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 50, 19 });
			cout << "=>";
			break;
		}
		}
		//cout << ' ';
	}
}

void GUI::printTableLine()
{
	for (short i = 0; i < 106; i++) printf_s("%c", '*');
	printf_s("\n");
}

void GUI::ShowProcessListMenu()
{
	system("mode con cols=80 lines=30");
	Paint paint;
	int mod = 0;
	char a;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hConsole, { 30, 11 });
	cout << "Choose refresh time: ";

	SetConsoleCursorPosition(hConsole, { 36, 13 });
	cout << "Fast";

	SetConsoleCursorPosition(hConsole, { 36, 15 });
	cout << "Normally";

	SetConsoleCursorPosition(hConsole, { 36, 17 });
	cout << "Slow";

	SetConsoleCursorPosition(hConsole, { 36, 19 });
	cout << "Stop";

	paint.paintShowMenu('%');

	SetConsoleCursorPosition(hConsole, { 34, 12 });
	cout << "=>";

	while (true) {
		system("mode con cols=120 lines=500");
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
		case 8: {
			GUI::Menu();
			break;
		}
		case '\r': {
			switch (mod) {
			case 0: {
				system("cls");
				MyProcess Mp;
				Mp.ShowProcessList();
				return;
			}
			case 1: {
				system("cls");
				_getch();
				MyProcess Mp;
				Mp.ShowProcessList();
				return;
			}
			case 2: {
				system("cls");
				printf("Change");
				MyProcess Mp;
				Mp.ShowProcessList();
				return;
			}
			case 3: {
				system("cls");
				MyProcess Mp;
				Mp.ShowProcessList();
				_getch();
				return;
			}
			}
		}
		}
		switch (mod) {
		case 0: {
			SetConsoleCursorPosition(hConsole, { 34, 12 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 34, 14 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 16 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 18 });
			cout << "  ";
			break;
		}
		case 1: {
			SetConsoleCursorPosition(hConsole, { 34, 12 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 14 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 34, 16 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 18 });
			cout << "  ";
			break;
		}
		case 2: {
			SetConsoleCursorPosition(hConsole, { 34, 12 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 14 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 16 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 34, 18 });
			cout << "  ";
			break;
		}
		case 3: {
			SetConsoleCursorPosition(hConsole, { 34, 12 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 14 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 16 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 34, 18 });
			cout << "=>";
			break;
		}
		}
		//cout << ' ';
	}
}

void GUI::RunProcessMenu()
{
	system("mode con cols=120 lines=30");
	system("cls");
	int mod = 0;
	char a;
	char filler = '#';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD FilePath;

	SetConsoleCursorPosition(hConsole, { 52, 12 });
	cout << "Input app path : ";

	SetConsoleCursorPosition(hConsole, { 52, 14 });
	cin >> FilePath;
}

void GUI::KillProcessMenu()
{
	system("mode con cols=80 lines=30");
	system("cls");
	int mod = 0;
	char a;
	char filler = '#';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Pid;

	SetConsoleCursorPosition(hConsole, { 52, 12 });
	cout << "Input process PID : ";

	SetConsoleCursorPosition(hConsole, { 52, 14 });
	cin >> Pid;

	MyProcess MP;
	MP.KillProcess(Pid);
}

