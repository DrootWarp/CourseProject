#include "MyProcess.h"


//SIZE_T MyProcess::GetProcessMemory()
//{
//	return pmc.WorkingSetSize;
//}

BOOL MyProcess::ShowProcessList()
{
	DWORD dwPriorityClass;
	DWORD dwProcessMemory;
	PROCESS_MEMORY_COUNTERS pmc;

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(hProcessSnap, &pe32);
	// Now walk the snapshot of processes, and
	// display information about each process in turn
	do
	{
		_tprintf(TEXT("\n\n====================================================="));

		// Retrieve the priority class.
		dwPriorityClass = 0;
		dwProcessMemory = 0;
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
			wcout << "\n  PROCESS NAME    : " << pe32.szExeFile
				  << "\n  Process ID      : " << pe32.th32ProcessID
				  << "\n  Process memory  : " << pe32.dwSize
				  << "\n  Thread count    : " << pe32.cntThreads
				  << "\n  Priority base   : " << pe32.pcPriClassBase;
		
	} while (Process32Next(hProcessSnap, &pe32));

	return(TRUE);
}

BOOL MyProcess::KillProcess(DWORD procID)
{
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(hProcessSnap, &pe32);
	while (Process32Next(hProcessSnap, &pe32)){

		if (procID == pe32.th32ProcessID){

			hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID);
			TerminateProcess(hProcess, 0);
			
		}
	}

	return 0;
}

BOOL MyProcess::ChangePriority(DWORD procID, DWORD priority)
{
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(hProcessSnap, &pe32);
	while (Process32Next(hProcessSnap, &pe32)) {

		if (procID == pe32.th32ProcessID) {

			hProcess = OpenProcess(PROCESS_SET_INFORMATION, 0, pe32.th32ProcessID);
			SetPriorityClass(hProcess, priority);

		}
	}

	return 0;
}

wchar_t* cw(const char *arry)
{
	wchar_t *w_s = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, arry, -1, w_s, 4096);
	return w_s;
}


BOOL MyProcess::RunProcess()
{
    wstring filePath = L"C:\\Program Files\\Nexus Mod Manager\\NexusClient.exe";
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL,   // No module name (use command line)
		filePath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	return 0;
}

BOOL MyProcess::OpenTheProcessDirectory()
{

	return 0;
}
