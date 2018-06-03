#include "MyProcess.h"

BOOL MyProcess::GetProcessList()
{
	DWORD dwPriorityClass;
	DWORD dwProcessMemory;

	Process32First(hProcessSnap, &pe32);
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
		wcout <<"\n  Process ID       = " << pe32.th32ProcessID
	          <<"\n  Process memory   = " << pe32.dwSize
		      <<"\n   Thread count    = " << pe32.cntThreads
		      <<"\n   Priority base   = " << pe32.pcPriClassBase;

	} while (Process32Next(hProcessSnap, &pe32));

	//CloseHandle(hProcessSnap);

	return(TRUE);
}

BOOL MyProcess::KillProcess(DWORD procID)
{
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
	Process32First(hProcessSnap, &pe32);
	while (Process32Next(hProcessSnap, &pe32)) {
		if (procID == pe32.th32ProcessID)
			SetPriorityClass(hProcess, priority);
		

	}
	return 0;
}
