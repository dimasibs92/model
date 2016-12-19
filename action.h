#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TypeMemory.h"
#include "func.h"
#define llc 1 // count of cores processor needed to do easy task (Task #1)
#define llm 1024 // count of RAM memory needed to do easy task (Task #1)
#define lmc 2 // count of cores processor needed to do easy-medium task (Task #2)
#define lmm 2048 // count of RAM memory needed to do easy-medium task (Task #2)
#define mc 4 // count of cores processor needed to do medium task (Task #3)
#define mm 4096 // count of RAM memory needed to do medium task (Task #3)
#define hlc 8 // count of cores processor needed to do medium-hard task (Task #4)
#define hlm 8192 // count of RAM memory needed to do medium-task task (Task #4)
#define hhc 16 // count of cores processor needed to do hard task (Task #5)
#define hhm 16384 // count of RAM memory needed to do hard task (Task #5)
#define types 5
using namespace std;
extern bool list;
class action
{
	private:
	bool paral; // parallel action?
	bool end; //  end of action?
	bool error; // error of executing action?
	int time; // time of executing action
	int c;
	int m;
	int n;
	int count_delay;
	public:
	action(bool p);
	void setaction(int* p, int* mems, int n);
	void initResources(int count);
	int getTime();
	int getCores();
	int getMemory();
	int getNum();
	void action_temp(int *pc,int *mem,int n);
	bool getEnd();
	bool getError();
	int getDelay();
};
