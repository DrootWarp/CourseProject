#include "MyProcess.h"
#include "GUI.h"


SIZE_T MyProcess::GetProcessMemory(DWORD processID)
{
	PROCESS_MEMORY_COUNTERS pmc;
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
	}

	return pmc.WorkingSetSize;
}

BOOL MyProcess::ShowProcessList()
{
	DWORD dwPriorityClass;
	DWORD dwProcessMemory;
	PROCESS_MEMORY_COUNTERS pmc;

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(hProcessSnap, &pe32);
	// Now walk the snapshot of processes, and
	// display information about each process in turn
	ShowProcessHad();
	do
	{
		dwProcessMemory = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
		dwProcessMemory = GetProcessMemory(pe32.th32ProcessID);
		GUI::printTableLine();
		wcout << "*" << setw(40) << left << pe32.szExeFile
			<< "*" << setw(15) << pe32.th32ProcessID
			<< "*" << setw(15) << dwProcessMemory/1536
			<< "*" << setw(15) << pe32.cntThreads
			<< "*" << setw(15) << pe32.pcPriClassBase
			<< "*" << endl;
		
	} while (Process32Next(hProcessSnap, &pe32));
	GUI::printTableLine();
	return(TRUE);
}

BOOL MyProcess::KillProcess(DWORD procID)
{
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(hProcessSnap, &pe32);
	while (Process32Next(hProcessSnap, &pe32)){

		if (procID == pe32.th32ProcessID){

			hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID);
			TerminateProcess(hProcess, 077);
			break;
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
			break;
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
		NULL,        // Command line
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

void MyProcess::ShowProcessHad()
{
	GUI::printTableLine();
	wcout << "*" << setw(40) << left << "PROCESS NAME "
		<< "*" << setw(15) << "Process ID    "
		<< "*" << setw(15) << "Process memory"
		<< "*" << setw(15) << "Thread count  "
		<< "*" << setw(15) << "Priority base "
		<< "*" << endl;
}
