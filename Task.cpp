#include "Task.h"
Task::Task(int n)
{
	num = n;
	time = 0;
	bool error = false;
	p = false;
	if (rand()%2==0)
	{
		if (list)
		printf ("Task_%d: DEBUG :Task is not parallel\n",num);
	}
	else
	{
		p = true;
		if (list)
		printf ("Task_%d: DEBUG :Task is parallel\n",num);
	}
	act = new action(p);
}
int Task::getTimeTask()
{
	return time;
}
bool Task::getEndTask()
{
	if (act->getEnd())
	return act->getEnd();
	else
    return false;
}
void Task::checkTask(int count)
{
	act->initResources(count);
	time=0;
	switch(act->getNum())
	{
		case 0: {
		while(1) {
		if (time>=1 && time<=2)
		break;
		time = static_cast <int> (exp_rasp(ret_val()))+1;	
		}
		break; }
		case 1: {
		while(1) {
		if (time>=2 && time<=3)
		break;
		time = static_cast <int> (exp_rasp(ret_val()))+2;	
		}
		break;	}
		case 2: {
		while(1) {
		if (time>=3 && time<=4)
		break;
		time = static_cast <int> (exp_rasp(ret_val()))+3;	
		}
		break;	}
		case 3: {
		while(1) {
		if (time>=4 && time<=5)
		break;
		time = static_cast <int> (exp_rasp(ret_val()))+4;	
		}
		break;	}
		case 4: {
		while(1) {
		if (time>=5 && time<=6)
		break;
		time = static_cast <int> (exp_rasp(ret_val()))+5;	
		}
		break;	}
	}
}
int Task::getCores()
{
	return act->getCores();
}
int Task::getMemory()
{
	return act->getMemory();
}
void Task::runTask(int* pc, int* m,int n)
{
	if (list)
	printf ("Task %d: DEBUG : Try to run the action %d. For launch this task need %d cores and %d memory ",num,act->getNum(),act->getCores(),act->getMemory());
	act->setaction(pc,m,n);
	time+=act->getDelay();
}
int Task::getNum(){
	return act->getNum();
}
bool Task::getParal()
{
	return p;
}
int Task::getN()
{
	return num;
}
void Task::setError()
{
	error = true;
}
bool Task::getError()
{
	return error;
}
