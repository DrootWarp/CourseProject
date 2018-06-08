#pragma once

#include <Windows.h>
#include <string>
#include <tlhelp32.h>
#include <iostream>
#include <tchar.h>
#include <wchar.h>
#include <stdio.h>
#include <commctrl.h>
#include <Psapi.h>
#include <conio.h>
#include <iomanip>

#include "ThreadsResourse.h"

using namespace std;

class MyProcess {
private:
	ThreadResourse resourse;
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
public:
	MyProcess() {
		pe32.dwSize = sizeof(PROCESSENTRY32);
	}

	SIZE_T GetProcessMemory(DWORD);
	BOOL ShowProcessList();
	BOOL KillProcess(DWORD);
	BOOL ChangePriority(DWORD, DWORD);
	BOOL RunProcess();
	BOOL OpenTheProcessDirectory();
	void ShowProcessHad();

	~MyProcess() {
		CloseHandle(hProcess);
		CloseHandle(hProcessSnap);
	}
};
