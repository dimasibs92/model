#include "Memory.h"

Memory::Memory (int s,int c,TypeMemory* t)
{
	size = s;
	count = c;
	cell = new busy[count];
	tpm = t;
	for (int i=0;i<count;i++)
	{
	cell[i].state = false;
	cell[i].task=0;
    }
	if (list)
	printf ("Memory: DEBUG : Initialize copy of class memory with type %d, size of cell = %d and count of cells = %d\n",tpm->getType(),size);
}
void Memory::setMSize(int s)
{
	size = s;
	if (list)
	printf ("Memory: DEBUG : Change the size of cell on = %d, type of memory=%d\n",size,tpm->getType());
}
void Memory::setMCount(int c)
{
	count = c;
	if (list)
	printf ("Memory: DEBUG : Change the count of cell on = %d, type of memory=%d\n",count,tpm->getType());
}
void Memory::setMFreq(int f)
{
	tpm->setFreq(f);
	if (list)
	printf("Memory: DEBUG : Try to change the frequency of ram on = %d\n",size);
}
void Memory::setMSpeed()
{
	tpm->setSpeed(getMType());
	if (list)
	printf("Memory %d: DEBUG : Try to change the speed of transmit data on = %d\n",getMType(),tpm->getSpeed());
}
int Memory::getMFreq()
{
	if (tpm->getFreq()>0)
	return tpm->getFreq();
	else
	 {
	 	if (list)
	 	printf("Memory: ERROR : The copy of class Memory don't complies type of RAM'");
	 	return 0;
	 }
}
int Memory::getMSize()
{
	return size;
}
int Memory::getMCount()
{
	return count;
}
int Memory::getMType()
{
	return tpm->getType();
}
bool Memory::getMCellNum(int i,int num)
{
	if (cell[i].task==num)
	return cell[i].state;
	else
	return false;
}
bool Memory::getMCell(int i)
{
	return cell[i].state;
}
void Memory::setMCellT(int i, int num)
{
	cell[i].state=true; 
	cell[i].task = num;
	if (list)
	printf ("Memory type of %d : DEBUG: Change state the cell # %d to %d\n",getMType(),i,cell[i].state);
}
void Memory::setMCellF(int i,int num)
{
	cell[i].state = false;
	cell[i].task=0;
	if (list)
	printf ("Memory type of %d : DEBUG: Change state the cell # %d to %d\n",getMType(),i,cell[i].state);
}
int Memory::getMSpeed()
{
	return tpm->getSpeed();
}
