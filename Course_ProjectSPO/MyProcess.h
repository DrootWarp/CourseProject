#pragma once

#include <Windows.h>
#include <string>
#include <tlhelp32.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <commctrl.h>

using namespace std;

class MyProcess {
private:
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
public:
	BOOL GetProcessList();
	BOOL KillProcess(DWORD);
	BOOL ChangePriority();

};
