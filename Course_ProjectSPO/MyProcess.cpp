#include "MyProcess.h"


DWORD MyProcess::GetProcessMemory()
{
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc));
	return pmc.WorkingSetSize;
}

BOOL MyProcess::ShowProcessList(DWORD pID)
{
	DWORD dwPriorityClass;
	DWORD dwProcessMemory;
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
		if (pe32.th32ProcessID == pID)
		{
			KillProcess(pe32.th32ProcessID);
		}
		dwProcessMemory = GetProcessMemory();
		wcout <<"\n  PROCESS NAME    : " << pe32.szExeFile
			  <<"\n  Process ID      : " << pe32.th32ProcessID
	          <<"\n  Process memory  : " << dwProcessMemory
		      <<"\n  Thread count    : " << pe32.cntThreads
		      <<"\n  Priority base   : " << pe32.pcPriClassBase;
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

BOOL MyProcess::RunProcess()
{

	return 0;
}

BOOL MyProcess::OpenTheProcessDirectory()
{

	return 0;
}
