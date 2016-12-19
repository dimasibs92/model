#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "TypeMemory.h"
using namespace std;
struct busy {
	bool state;
	int task;
};
extern bool list;
class Memory {
	private:
	int size; // variable for size of cell memory
	int count; // variable for count of cells memory
	busy* cell; // array for detect state busy of cells memory
	TypeMemory* tpm; // link for detect type of memory
	public:
Memory(int s,int c,TypeMemory* t); // constructor of class Memory with input parameters: size of cell, type of memory and link on class TypeMemory
void setMFreq(int f); // procedure for set frequency of RAM
void setMSize(int s); // procedure for set size of cell memory 
void setMCount(int c); // procedure for set count of cells memory
void setMCellT(int i,int num); // procedure for setup true state for i-cell
void setMCellF(int i,int num); // procedure for setup false state for i-cell
void setMSpeed();
int getMSpeed();
int getMFreq(); // return frequency of memory
int getMType(); // return type of memory
int getMSize(); // return size of cell memory
int getMCount(); // return count of cells memory
bool getMCell(int i);
bool getMCellNum(int i,int num); // return the state of i-cell
};
