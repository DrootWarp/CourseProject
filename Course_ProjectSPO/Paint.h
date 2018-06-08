#pragma once

#include "MyProcess.h"
#include "ThreadsResourse.h"

class Paint {
private:
public:
	void paintHeader(char);
	void printCharTimes(char,int);
	void paintFunctionsHeader(char filler);
	void paintShowMenu(char filler);
	void paintKillMenu(char filler);
	void paintPriorityMenu(char filler);
};