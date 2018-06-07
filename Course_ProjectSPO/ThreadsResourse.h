#pragma once

#include<thread>
#include<iostream>
#include<Windows.h>


using namespace std;


class ThreadResourse {
private:
	HANDLE* hThreadArray;
public:
	DWORD WINAPI ThreadShowProcessList(LPVOID);
	DWORD WINAPI ThreadKillProcess(LPVOID);
	DWORD WINAPI ThreadRunProcess(LPVOID);
	DWORD WINAPI ThreadOpenTheProcessDirectory(LPVOID);
	DWORD WINAPI ThreadChangePriority(LPVOID);

};