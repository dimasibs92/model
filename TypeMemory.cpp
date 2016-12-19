#include "TypeMemory.h"
TypeMemory::TypeMemory(int t)
{
	type = t;
}
int TypeMemory::getType()
{
	return type;
}
void TypeMemory::setFreq(int f)
{
	if (f<=maxfreq) {
	freq = f;
	if (list)
	printf ("TypeMemory: DEBUG :Set frequency of RAM on value: %d Mhz\n",f);
    }
	else
	{
	freq = freqram;
	if (list)
	printf ("TypeMemory: WARNING: Try set frequency of RAM above maximal value, set frequency of RAM on default value: %d Mhz\n",freqram);
    }
}
void TypeMemory::setFreq()
{
	if (type==0)
	 freq = freqram;
	else 
	{
	 if (list)
	 printf ("TypeMemory: ERROR!!! : Chose memory which don't need to change the frequency\n");
    }
}
void TypeMemory::setSpeed(int type)
{
	switch(type)
	{
		case 0: {speed = 0; break;	}
		case 1: {
		if (speedswap>maxspswap) {
		speed = maxspswap;
		if (list)
		printf ("TypeMemory: WARNING: Try set speed of swap above maximal value, set speed of swap on default value:%d Mb/s\n",speed);
		}
		else {
		printf ("%d  ",speedswap);
		speed = speedswap;
		if (list) 
		printf ("TypeMemory: DEBUG: Set max speed tranmit data for swap memory (cache system):%d Mb/s\n",speed); 
		}
		break;	
		}
		case 2: {
		if (speedssdpci>maxspssdpci) {
		speed = maxspssdpci;
		if (list)
		printf ("TypeMemory: WARNING: Try set speed of ssd installed on socket PCI-Ex above maximal value, set speed of ssd PCI-Ex on default value:%d Mb/s\n",speed);
		}
		else {
		speed = speedssdpci; 
		if (list)
		printf ("TypeMemory: DEBUG: Set max speed tranmit data for ssd installed on socket PCI-Ex:%d Mb/s\n",speed); 
		}
		break;
	    }
		case 3: {
		if (speedssdsata>maxspssdsata) {
		speed = maxspssdsata;
		if (list)
		printf ("TypeMemory: WARNING: Try set speed of ssd installed on SATA3 above maximal value, set speed of ssd SATA3 on default value:%d Mb/s\n",speed);
		}
		else {
		speed = speedssdsata; 
		if (list)
		printf ("TypeMemory: DEBUG: Set max speed tranmit data for ssd installed on SATA3 :%d Mb/s\n",speed); 
		}
		break;
	    }
		case 4: {
		if (speedhdd>maxsphdd) {
		speed = maxsphdd;
		if (list)
		printf ("TypeMemory: WARNING: Try set speed of hdd above maximal value, set speed of hdd on default value:%d Mb/s\n",speed);
		}
		else {
		speed = speedhdd; 
		if (list)
		printf ("TypeMemory: DEBUG: Set max speed tranmit data for hdd installed on SATA3 :%d Mb/s\n",speed); 
		}
		break;
	    }
	}
}
int TypeMemory::getFreq()
{
	return freq;
}
int TypeMemory::getSpeed()
{
	return speed;
}
