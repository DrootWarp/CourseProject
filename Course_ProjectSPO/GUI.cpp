#include "GUI.h"

void GUI::Menu()
{
	system("mode con cols=120 lines=30");
	system("cls");
	Paint paint;
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
				ShowProcessListMenu();
				return;
			}
			case 1: {
				system("cls");
				KillProcessMenu();
				return;
			}
			case 2: {
				system("cls");
				printf("Change");
				ChangePriorityMenu();
				return;
			}
			case 3: {
				system("cls");
				RunProcessMenu();
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
	Paint paint;
	MyProcess myProcess;
	int mod = 0;
	char a;
	char filler = '#';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Priority;
	DWORD Pid;

	paint.paintKillMenu('#');

	SetConsoleCursorPosition(hConsole, { 28, 11 });
	cout << "Input process PID : ";

	SetConsoleCursorPosition(hConsole, { 29, 13 });
	wcin >> Pid;

	system("cls");

	paint.paintPriorityMenu('*');

	SetConsoleCursorPosition(hConsole, { 31, 11 });
	cout << "Choose priority rate: ";

	SetConsoleCursorPosition(hConsole, { 33, 13 });
	cout << "High";

	SetConsoleCursorPosition(hConsole, { 33, 15 });
	cout << "Above normal";

	SetConsoleCursorPosition(hConsole, { 33, 17 });
	cout << "Normal";

	SetConsoleCursorPosition(hConsole, { 33, 19 });
	cout << "Below normal";

	SetConsoleCursorPosition(hConsole, { 33, 21 });
	cout << "Low";

	SetConsoleCursorPosition(hConsole, { 31, 13 });
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
			Menu();
			break;
		}
		case '\r': {
			switch (mod) {
			case 0: {
				system("cls");
				Priority = HIGH_PRIORITY_CLASS;
				myProcess.ChangePriority(Pid, Priority);
				return;
			}
			case 1: {
				system("cls");
				Priority = ABOVE_NORMAL_PRIORITY_CLASS;
				myProcess.ChangePriority(Pid, Priority);
				return;
			}
			case 2: {
				system("cls");
				Priority = NORMAL_PRIORITY_CLASS;
				myProcess.ChangePriority(Pid, Priority);
				return;
			}
			case 3: {
				system("cls");
				Priority = BELOW_NORMAL_PRIORITY_CLASS;
				myProcess.ChangePriority(Pid, Priority);
				return;
			}
			case 4: {
				system("cls");
				Priority = IDLE_PRIORITY_CLASS;
				myProcess.ChangePriority(Pid, Priority);
				return;
			}
			}
		}
		}
		switch (mod) {
		case 0: {
			SetConsoleCursorPosition(hConsole, { 31, 13 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 31, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 19 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 21 });
			cout << "  ";
			break;
		}
		case 1: {
			SetConsoleCursorPosition(hConsole, { 31, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 15 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 31, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 19 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 21 });
			cout << "  ";
			break;
		}
		case 2: {
			SetConsoleCursorPosition(hConsole, { 31, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 17 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 31, 19 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 21 });
			cout << "  ";
			break;
		}
		case 3: {
			SetConsoleCursorPosition(hConsole, { 31, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 19 });
			cout << "=>";
			SetConsoleCursorPosition(hConsole, { 31, 21 });
			cout << "  ";
			break;
		}
		case 4: {
			SetConsoleCursorPosition(hConsole, { 31, 13 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 15 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 17 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 19 });
			cout << "  ";
			SetConsoleCursorPosition(hConsole, { 31, 21 });
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
	int mod = 0;
	char a;
	Paint paint;
	MyProcess myProcess;
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
			Menu();
			break;
		}
		case '\r': {
			switch (mod) {
			case 0: {
				system("cls");
				system("mode con cols=120 lines=500");
				myProcess.ShowProcessList();
				return;
			}
			case 1: {
				system("cls");
				system("mode con cols=120 lines=500");
				myProcess.ShowProcessList();
				return;
			}
			case 2: {
				system("cls");
				system("mode con cols=120 lines=500");
				myProcess.ShowProcessList();
				break;
			}
			case 3: {
				system("cls");
				system("mode con cols=120 lines=500");
				myProcess.ShowProcessList();
				while ((a = _getch()) == 95 ) {
					system("cls");
					myProcess.ShowProcessList();
				}
				Menu();
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
	Paint paint;
	MyProcess myProcess;
	int mod = 0;
	char a;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Pid;

	paint.paintKillMenu('#');

	SetConsoleCursorPosition(hConsole, { 28, 11 });
	cout << "Input process PID : ";

	SetConsoleCursorPosition(hConsole, { 29, 13 });
	cin >> Pid;

	myProcess.KillProcess(Pid);
	Menu();
}

