
#include "MyProcess.h"
#include "GUI.h"

using namespace std;

void printError(TCHAR* msg);
CRITICAL_SECTION csection;
DWORD PID;

DWORD WINAPI Thread1(LPVOID LParam) {
	while (1) {

		system("cls");
		return 0;
	}
}

DWORD WINAPI Thread2(LPVOID LParam) {

	MyProcess Mp;
	while (1)
	{
		EnterCriticalSection(&csection);
		Mp.ShowProcessList(PID);
		scanf_s("%d", &PID);
		Sleep(25000);

		LeaveCriticalSection(&csection);
	}

	ExitThread(0);
	return 0;
}


int main(void)
{
	InitializeCriticalSection(&csection);
	HANDLE Threads[2];
	Threads[0] = CreateThread(NULL, 0, Thread1, NULL, CREATE_SUSPENDED, NULL);
	Threads[1] = CreateThread(NULL, 0, Thread2, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(Threads[0]);
	ResumeThread(Threads[1]);

	system("pause");
	DeleteCriticalSection(&csection);
	::TerminateThread(Threads[0], 007);
	::TerminateThread(Threads[1], 007);
	return 0;
}

void printError(TCHAR* msg)
{
	DWORD eNum;
	TCHAR sysMsg[256];
	TCHAR* p;

	eNum = GetLastError();
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, eNum,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		sysMsg, 256, NULL);

	// Trim the end of the line and terminate it with a null
	p = sysMsg;
	while ((*p > 31) || (*p == 9))
		++p;
	do { *p-- = 0; } while ((p >= sysMsg) &&
		((*p == '.') || (*p < 33)));

	// Display the message
	_tprintf(TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg);
}