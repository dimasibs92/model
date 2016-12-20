#include "action.h"

action::action(bool p)
{
 count_delay=0;
 paral = p;
 end = false;
 error = false;
}
void action::initResources(int count)
{
	n = rand()%count;
	switch(n)
	{
		case 0: { c = llc; m = llm; break; 	}
		case 1: { c = lmc; m = lmm; break;	}
		case 2: { c = mc; m = mm;   break;	}
		case 3: { c = hlc; m = hlm; break;	}
		case 4: { c = hhc; m = hhm; break;	}
	}
}
void action::setaction(int* p, int* mems, int n)
{
	if(list)
	printf ("Setter_action: DEBUG :call act_%d\n",n);
	action_temp(p,mems,n);
}
void action::action_temp(int *pc,int *mems,int n)
{
	printf ("Launch action %d\n",n);
	int cores; // temp variable for cores of processor
	int memory; // temp variable for different types of memory
	int i=0;
	int temp=0;
	memory = -m;
	while(memory<0)
	{
		if (types==i)
		{
		error = true;
		if (list)
		printf ("act_%d: ERROR!!! : No memory\n",n);
		break;
	    }
		memory=mems[i]-abs(memory);
		temp=0;
		switch(i)
		{
			case 1: {
			while(1)	{
			if (temp>=1 && temp<(int)speedswap*10/freqram) 
				break;	
				printf ("swap %d",temp);
				temp=static_cast <int> (exp_rasp((double) speedswap/freqram));
			}}  
			case 2: {
			while(1)	{
			if (temp>=1 && temp<(int)speedssdpci*5/freqram) 
				break;
				printf ("ssd pci %d",temp);	
				temp=static_cast <int> (exp_rasp((double) speedssdpci/freqram));
			}}
			case 3: {
			while(1)	{
			if (temp>=1 && temp<(int)speedssdsata*10/freqram) 
				break;	
				printf ("ssd sata %d",temp);
				temp=static_cast <int> (exp_rasp((double) speedssdsata/freqram));
			}}
			case 4: {
			while(1)	{
			if (temp>1 && temp<((int)speedhdd*100/freqram)+5) 
				break;	
				printf ("hdd %d",temp);
				temp=static_cast <int> (exp_rasp((double) speedhdd/freqram));
			}}
		}
		count_delay+=temp;
		i++;
	}
	if (!error)
	{
	cores = pc[0]-c;
	if (paral)
	{
		cores = pc[1]-cores;
	}
	if (cores<0)
	 {
	 error = true;
	 if (list)
	 printf("act_%d: ERROR!!! : No cores\n",n);
     }
    }
    if (!error)
    {
     end = true;
    if (list)
     printf("act_%d: DEBUG :Action complete",n);
    }
}
bool action::getEnd()
{
	return end;
}
int action::getNum()
{
	return n;
}
int action::getCores()
{
	return c;
}
int action::getMemory()
{
	return m;
}
bool action::getError()
{
	return error;
}
int action::getDelay()
{
	return count_delay;
}
