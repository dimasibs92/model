#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
extern bool list;
class Processor
{
private:
int pnumcores; // variable detect the number of physical cores in processor
int lnumcores; // variable detect the number of logical cores in processor
busy* pcores;
busy* lcores;
public:
Processor(int pn,int ln); // constructor of class Processor. Input parameters: variable for detect the number of physical cores and variable for detect the number of logical cores
void setPnc(int pn); // procedure set the count of physical cores with input parameter
void setLnc(int ln); // procedure set the count of logical cores with input parameter
int getPnc(); // return the number of physical cores on copy of class Processor
int getLnc(); // return the number of logical cores on copy of class Processor 
bool getPCoreStateNum(int i,int num); // return the state of physical i-core processor
bool getLCoreStateNum(int i,int num); // return the state of logical i-core processor	
bool getPCoreState(int i); // return the state of physical i-core processor
bool getLCoreState(int i); // return the state of logical i-core processor	
void setPCoreState(int i,int num);
void setLCoreState(int i,int num);
~Processor();	
};
