#include "MyProcess.h"

BOOL MyProcess::GetProcessList()
{
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
		wcout << "\n  Process ID       = " << pe32.th32ProcessID
	          << "\n  Process memory   = " << pe32.dwSize
		      <<"\n   Thread count     = " << pe32.cntThreads
		      <<"\n   Priority base    = " << pe32.pcPriClassBase;
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return(TRUE);
}

BOOL MyProcess::KillProcess(DWORD procID)
{
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	pe32.dwSize = sizeof(PROCESSENTRY32);

	Process32First(hProcessSnap, &pe32);


	while (Process32Next(hProcessSnap, &pe32))
	{
		if (procID == pe32.th32ProcessID)
		{
			hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID);

			TerminateProcess(hProcess, 0);

			//ListView_DeleteItem(proc_list, iSelect);
		}
	}
	CloseHandle(hProcessSnap);
	CloseHandle(hProcess);
	return 0;
}

BOOL MyProcess::ChangePriority()
{
	return 0;
}
