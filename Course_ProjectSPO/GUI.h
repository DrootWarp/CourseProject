#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <fstream>


using namespace std;

class GUI {
public:
	static void Menu();
	static void ChangePriorityMenu();
	static void printTableLine();
	static void ShowProcessListMenu();
	static void RunProcessMenu();

};