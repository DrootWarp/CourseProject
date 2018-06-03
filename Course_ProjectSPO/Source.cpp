
#include"MyProcess.h"


using namespace std;

// Forward declarations:
BOOL GetProcessList();
void printError(TCHAR* msg);
CRITICAL_SECTION csection;

DWORD WINAPI Thread1(LPVOID LParam) {
	while (1) {

		system("cls");
		return 0;
	}
}

DWORD WINAPI Thread2(LPVOID LParam) {

	while (1)
	{
		EnterCriticalSection(&csection);
		GetProcessList();
		Sleep(1000);
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

BOOL GetProcessList()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	DWORD dwProcessMemory;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		//printError(TEXT("CreateToolhelp32Snapshot (of processes)"));
		return(FALSE);
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		//printError(TEXT("Process32First")); // show cause of failure
		CloseHandle(hProcessSnap);          // clean the snapshot object
		return(FALSE);
	}

	// Now walk the snapshot of processes, and
	// display information about each process in turn
	do
	{
		_tprintf(TEXT("\n\n====================================================="));
		_tprintf(TEXT("\n  PROCESS NAME:  %s"), pe32.szExeFile);
		//_tprintf(TEXT("\n-------------------------------------------------------"));

		// Retrieve the priority class.
		dwPriorityClass = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
		if (hProcess == NULL)
			_tprintf(TEXT("OpenProcess"));
		else
		{
			dwPriorityClass = GetPriorityClass(hProcess);
			if (!dwPriorityClass)
				_tprintf(TEXT("GetPriorityClass"));
			CloseHandle(hProcess);
		}
		wcout << "\n  Process ID        = " << pe32.th32ProcessID;
		wcout << "\n  Process memory        = " << pe32.dwSize;
		_tprintf(TEXT("\n  Thread count      = %d"), pe32.cntThreads);
		_tprintf(TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase);

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return(TRUE);
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