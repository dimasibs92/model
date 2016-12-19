#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define maxfreq 3000
#define maxspswap 500
#define maxspssdpci 1000
#define maxspssdsata 500
#define maxsphdd 100
using namespace std;
extern bool list;
extern int freqram,speedswap,speedssdpci,speedssdsata,speedhdd;
class TypeMemory
{
  private:
  int type; // variable for detect type of memory
  int freq; // variable for detect frequency of memory (only use for RAM)
  int speed; // variable for detect speed of transmit data to RAM (use all types of memories except for RAM, RAM=0)
  public:
TypeMemory(int t); // constructor for initialize copy of class TypeMemory. Input parameter: type of memory (0 - RAM, 1 - swap memory(system cache), 2- SSD installed on socket PCI-Ex, 3 - SSD isntalled on SATA3, 4 - HDD)
int getType(); // return type of memory
void setFreq(int f); // function for set the frequency of memory (use only in RAM). Input parameter: variable for set the frequency on this value, if value more maxvalue, then set the maxvalue
void setFreq(); // function for set the frequency of RAM on default maxvalue Mhz 
void setSpeed(int type); // function for set the speed transmit of data on values defined in text file
int getFreq();	// return the frequency of memory (use only in RAM)
int getSpeed(); // return the speed of transmit data to RAM (use all types of memories except for RAM, RAM=0)
};
