#include"ThreadsResourse.h"
#include "MyProcess.h"

DWORD ThreadResourse::ThreadShowProcessList(LPVOID refreshTime)
{
	MyProcess Mp;
	Mp.ShowProcessList();
	return 0;
}

DWORD ThreadResourse::ThreadKillProcess(LPVOID)
{
	return 0;
}

DWORD ThreadResourse::ThreadRunProcess(LPVOID)
{
	return 0;
}

DWORD ThreadResourse::ThreadOpenTheProcessDirectory(LPVOID)
{
	return 0;
}

DWORD ThreadResourse::ThreadChangePriority(LPVOID)
{
	return 0;
}
