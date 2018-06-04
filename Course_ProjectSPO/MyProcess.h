#pragma once

#include <Windows.h>
#include <string>
#include <tlhelp32.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <commctrl.h>
#include <Psapi.h>

using namespace std;

class MyProcess {
private:
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
public:
	MyProcess() {
		pe32.dwSize = sizeof(PROCESSENTRY32);
	}

	DWORD GetProcessMemory();
	BOOL ShowProcessList(DWORD);
	BOOL KillProcess(DWORD);
	BOOL ChangePriority(DWORD, DWORD);
	BOOL RunProcess();
	BOOL OpenTheProcessDirectory();
	

	~MyProcess() {
		CloseHandle(hProcessSnap);
		CloseHandle(hProcess);
	}
};
