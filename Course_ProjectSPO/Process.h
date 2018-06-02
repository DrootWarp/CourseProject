#pragma once

#include <Windows.h>
#include <string>

using namespace std;

class MyProcess {
private:
	DWORD processID;
	DWORD threadID;
	HANDLE processH;
	HANDLE threadH;
	wstring comLion;
public:
	DWORD getProcessId() const;
	HANDLE getProcessHandle() const;
	wstring getCommandLine() const;
	wstring getStatus() const;
	wstring getInfo() const;
	wstring getLoggerInfo() const;
};
