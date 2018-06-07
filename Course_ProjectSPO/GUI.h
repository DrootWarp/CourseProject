#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <fstream>

#include "MyProcess.h"
#include "ThreadsResourse.h"
#include "Paint.h"

using namespace std;

class GUI {
public:

	static void Menu();
	static void ChangePriorityMenu();
	static void printTableLine();
	static void ShowProcessListMenu();
	static void RunProcessMenu();
	static void KillProcessMenu();

};