#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include "task.h"
#include "Memory.h"
#include "Processor.h"
#include "func.h"
#define types 5
#define tasks 5
#define delay 5
struct event {
	Task *t; 
	int timestart; 
};
extern int gl_time;
using namespace std;
class Calendar
{
	private:
//	bool errorruntask;
	queue<event> q;
	Processor* p;
	Memory* mram;
	Memory* mswap;
	Memory* mpssd;
	Memory* msssd;
	Memory* mhdd;
	int index;
	int ctask;
	public:
	Calendar(int* arg, bool list);
	bool chk_empty();
	void add(int i, int time);
	void runTask(int timestart);
	bool checkTask(int num);
	void clearTask(int timestart);
	void show();
	void setMemory(Memory *m, int need,int num);
	void setProcessor(Processor *p,int pneed, int lneed,int num);
	void getPrCores(Processor *p);
	void getMemory(Memory *m);
	int* initProc(Processor *p,int num);
	int* initMem(Memory* memRam, Memory* memSwap, Memory* memPSsd, Memory* memSSsd, Memory* memHdd,int num);
	int getIndex();
	void clean(int time);
	void setIndex(int i);
	bool getTimeTask(int time);
	int getCTask();
	void clearAll(); 
};
