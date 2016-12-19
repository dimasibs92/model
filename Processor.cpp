#include "Processor.h"
Processor::Processor(int pn, int ln){
	pnumcores = pn;
	lnumcores = ln;
	pcores = new busy[pnumcores];
	lcores = new busy[lnumcores]; 
	for (int i=0;i<pnumcores;i++)
	{
		pcores[i].state = false;
		pcores[i].task = 0;
    }
	for (int i=0;i<lnumcores;i++)
	{
	 	lcores[i].state = false;
	 	lcores[i].task = 0;
    }
	if (list)
	printf ("Processor: DEBUG : Init processor with %d physical cores and %d logical cores\n",pnumcores,lnumcores);
}
Processor::~Processor()
{
	delete[] pcores;
	delete[] lcores;
}
int Processor::getLnc(){
	return lnumcores;
}
int Processor::getPnc(){
	return pnumcores;
}
void Processor::setLnc(int ln){
	lnumcores = ln;
	if (list)
	printf("Processor: DEBUG : Change logical cores on %d\n",lnumcores);
}
void Processor::setPnc(int pn){
	pnumcores = pn;
	if (list)
	printf("Processor: DEBUG : Change physical cores on %d\n",pnumcores);
}
bool Processor::getPCoreStateNum(int i,int num)
{
	if (pcores[i].task==num)
	return pcores[i].state;
	else
	return false;
}
bool Processor::getLCoreStateNum(int i,int num)
{
	if (lcores[i].task==num)
	return lcores[i].state;
	else
	return false;
}
bool Processor::getPCoreState(int i)
{
	return pcores[i].state;
}
bool Processor::getLCoreState(int i)
{
	return lcores[i].state;
}
void Processor::setPCoreState(int i,int num)
{
	if (!pcores[i].state)
	 {
	 	pcores[i].state = true;
	 	pcores[i].task = num;
	 }
	else
	 {
	 	pcores[i].state = false;
	 	pcores[i].task = 0;
	 }
	printf("Processor: DEBUG : Change state physical core %d of busy on %d\n",i,pcores[i].state);
}
void Processor::setLCoreState(int i,int num)
{
	if (!lcores[i].state)
	 {
	 	lcores[i].state = true;
	 	lcores[i].task = num;
	 }
	else
	 {
	 	lcores[i].state = false;
	 	lcores[i].task = 0;
	 }
	 printf("Processor: DEBUG : Change state logical core %d of busy on %d\n",i,lcores[i].state);
}	

