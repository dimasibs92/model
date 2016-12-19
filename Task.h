#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "action.h"
extern bool list; 
using namespace std;
class Task
{
	private:
	int time; // variable for detect time of execution task
	int num; // variable of num of task
	action* act; // link on executing action
	bool error;
	bool p;
	public:
	Task(int n); // Constructor for initialize copy of Class Task
	int getTimeTask(); // return the time for end of task
	void runTask(int* pc, int* m,int n); // procedure for run of task
	bool getEndTask();
	void checkTask(int count);
	int getNum();
	int getN();
	int getCores();
	int getMemory();
	bool getParal();
	bool getError();
	void setError();
};
