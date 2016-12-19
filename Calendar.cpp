#include "Calendar.h"
Calendar::Calendar(int* arg, bool list)
{
	index = 0;
	ctask = 0;
	freqram = arg[4];
    speedswap = arg[7];
    speedssdpci = arg[10];
    speedssdsata = arg[13];
    speedhdd = arg[16];
	p = new Processor(arg[0],arg[1]);
	mram = new Memory(arg[3],arg[2],new TypeMemory(0));
	mram->setMFreq(arg[4]);
	mswap = new Memory(arg[6],arg[5],new TypeMemory(1));
	mswap->setMSpeed();
	mpssd = new Memory(arg[9],arg[8],new TypeMemory(2));
	mpssd->setMSpeed();
	msssd = new Memory(arg[12],arg[11],new TypeMemory(3));
	msssd->setMSpeed();
	mhdd = new Memory(arg[15],arg[14],new TypeMemory(4));
	mhdd->setMSpeed();
	printf ("System info:\n");
	if (list)
	 printf ("Calendar: DEBUG : Init system\n");
	printf("Processor cores: %d+%d\n",p->getPnc(),p->getLnc());
	getPrCores(p);
	getMemory(mram);
	printf ("Ram memory of one cell: %d, count of cells: %d,freq: %d\n",mram->getMSize(),mram->getMCount(),mram->getMFreq());
	printf ("Swap memory one cell: %d, cells: %d , speed:%d\n",mswap->getMSize(),mswap->getMCount(),mswap->getMSpeed());
    printf ("SSD Pci-Ex one cell: %d, cells: %d , speed:%d\n",mpssd->getMSize(),mpssd->getMCount(),mpssd->getMSpeed());
    printf ("SSD Sata3 one cell: %d, cells: %d , speed:%d\n",msssd->getMSize(),msssd->getMCount(),msssd->getMSpeed());
    printf ("HDD one sector: %d, sectors: %d , speed:%d\n",mhdd->getMSize(),mhdd->getMCount(),mhdd->getMSpeed());
}
void Calendar::setMemory(Memory *m,int need,int num)
{
	int* a = new int[need];
	a = select_no_return(m->getMCount(),need);
	 for (int i=0;i<need;i++)
	 m->setMCell(a[i],num);
	 delete[] a;
}
int* Calendar::initProc(Processor *p,int num)
{
	int *pr = new int[2];
	for (int i=0;i<2;i++)
	 pr[i] = 0;
	for (int i=0;i<p->getPnc();i++)
	if (p->getPCoreStateNum(i,num))
	pr[0]++;
	for (int i=0;i<p->getLnc();i++)
	if (p->getLCoreStateNum(i,num))
	pr[1]++;
	return pr;
}
int* Calendar::initMem(Memory* memRam, Memory* memSwap, Memory* memPSsd, Memory* memSSsd, Memory* memHdd, int num)
{
	int* memsize = new int[types];
	int* mem = new int[types];
		for (int i=0;i<types;i++)
	 {
	 	mem[i] = 0;
	 	switch(i)
	 	{
	 		case 0: {mem[i] = memRam->getMCount(); break;}
	 		case 1: {mem[i] = memSwap->getMCount(); break;}
	 		case 2: {mem[i] = memPSsd->getMCount(); break;}
	 		case 3: {mem[i] = memSSsd->getMCount(); break;}
	 		case 4: {mem[i] = memHdd->getMCount(); break;}
	 	}
	 }
	for (int i=0;i<types;i++)
	{
		memsize[i]=0;
		for (int j=0;j<mem[i];j++)
			switch(i)
			{
			case 0: {if (memRam->getMCellNum(j,num)) memsize[i]+=memRam->getMSize(); break; }
			case 1: {if (memSwap->getMCellNum(j,num)) memsize[i]+=memSwap->getMSize(); break; }
			case 2: {if (memPSsd->getMCellNum(j,num)) memsize[i]+=memPSsd->getMSize(); break; }
			case 3: {if (memSSsd->getMCellNum(j,num)) memsize[i]+=memSSsd->getMSize(); break; }
			case 4: {if (memHdd->getMCellNum(j,num)) memsize[i]+=memHdd->getMSize(); break; }
			}
	}
	return memsize;
}
void Calendar::setProcessor(Processor *p,int pneed, int lneed,int num)
{
	int* pa = new int[pneed];
	int* la = new int[lneed];
	pa = select_no_return(p->getPnc(),pneed);
	 for (int i=0;i<pneed;i++)
	 p->setPCoreState(pa[i],num);
	 delete[] pa;
	la = select_no_return(p->getLnc(),lneed);
	 for (int i=0;i<lneed;i++)
	 p->setLCoreState(la[i],num);
	 delete[] la;
}
void Calendar::getMemory(Memory *m)
{
	for (int i=0;i<m->getMCount();i++)
	printf ("%d ",m->getMCell(i));
	printf ("\n");
}
void Calendar::getPrCores(Processor *p)
{
	printf ("Physical cores:\n");
	for (int i=0;i<p->getPnc();i++)
	printf ("%d ",p->getPCoreState(i));
	printf ("\n");
	printf ("Logical cores:\n");
	for (int i=0;i<p->getLnc();i++)
	printf ("%d ",p->getLCoreState(i));
	printf ("\n");
}
bool Calendar::chk_empty()
{
	return q.empty();
}
void Calendar::add(int i, int time)
{
	index = i;
	event temp;
	Task* t1 = new Task(index);
	t1->checkTask(tasks);
    temp.t = t1;
    printf ("num: %d ",temp.t->getN());
    printf ("%d\n",time);
    printf ("gl_time = %d\n",gl_time);
	temp.timestart = time;
	q.push(temp);
	index++;
	Task* t2 = new Task(index);
	t2->checkTask(tasks);
    temp.t = t2;
    int tt = 0;
	while(1) {
     if (tt>=gl_time+1 && tt<gl_time+10)
     break; 
	tt = gl_time+static_cast <int> (exp_rasp(ret_val()));
 	}
	temp.timestart = tt;
	q.push(temp);
	index++;
	Task* t3 = new Task(index);
	t3->checkTask(tasks);
    temp.t = t3;
    int tmt = tt;
    while(1) {
     if (tt>=tmt+gl_time+1 && tt<tmt+gl_time+10)
     break;
    tt = gl_time+tmt+static_cast <int> (exp_rasp(ret_val()));
	}
	temp.timestart = tt;
	q.push(temp);
}
void Calendar::runTask(int timestart)
{
	event temp;
	queue<event> tp = q;
	for(int j=0;j<tp.size();j++)
	 {
	 	temp = tp.front();
	 	if (temp.timestart==timestart)
	 	{
	 	printf ("break");
	 	break;
	 	}
	 	tp.pop();
	 }
	printf("find\n");
	printf("run %d\n",temp.t->getN());
	int cores = temp.t->getCores();
	int mems = temp.t->getMemory();
	printf ("need: %d cores %d mems\n",cores,mems);
	if (temp.t->getParal())
	{
		printf ("paral cores");
		if (p->getPnc()+p->getLnc()<cores)
		{
		 temp.t->setError();
		 //errorruntask = true;
	 	 return;
	    }
		else
		{
		if (cores>1)
			setProcessor(p,temp.t->getCores()/2,temp.t->getCores()/2,temp.t->getN());
		else
			setProcessor(p,1,1,temp.t->getN());
		}
    }
	else
	{
	printf ("not paral cores");
	if (p->getPnc()<cores)
	{
	 temp.t->setError();
	 //errorruntask = true;
	 return;
    }
	else
	setProcessor(p,temp.t->getCores(),0,temp.t->getN());
	}
	bool initmem = false;
	printf ("memory ram");
	if (mems>mram->getMSize()*mram->getMCount())
	{
	 setMemory(mram,mram->getMCount(),temp.t->getN());
	 mems-=mram->getMSize()*mram->getMCount();
    }
    else
    {
     int count = (mems/mram->getMSize());
     setMemory(mram,count,temp.t->getN());
     initmem = true;
    }
    printf ("memory swap");
    if (!initmem)
    {
    if (mems>mswap->getMSize()*mswap->getMCount())
    {
     setMemory(mswap,mswap->getMCount(),temp.t->getN());
	 mems-=mswap->getMSize()*mswap->getMCount();
    }
    else
    {
     int count = (mems/mswap->getMSize());
     setMemory(mswap,count,temp.t->getN());
     initmem = true;
    }
    }
    printf ("memory ssd");
    if (!initmem)
    {
    if (mems>mpssd->getMSize()*mpssd->getMCount())
    {
     setMemory(mpssd,mpssd->getMCount(),temp.t->getN());
	 mems-=mpssd->getMSize()*mpssd->getMCount();
    }
    else
    {
     int count = (mems/mpssd->getMSize());
     setMemory(mpssd,count,temp.t->getN());
     initmem = true;
    }
    }
    if (!initmem)
    {
    if (mems>msssd->getMSize()*msssd->getMCount())
    {
     setMemory(msssd,mpssd->getMCount(),temp.t->getN());
	 mems-=msssd->getMSize()*msssd->getMCount();
    }
    else
    {
     int count = (mems/msssd->getMSize());
     setMemory(msssd,count,temp.t->getN());
     initmem = true;
    }
    }
    if (!initmem)
    {
    if (mems>mhdd->getMSize()*mhdd->getMCount())
    {
     temp.t->setError();
     //errorruntask = true;
     return;
    }
    else
    {
     int count = (mems/mhdd->getMSize());
     setMemory(mhdd,count,temp.t->getN());
     initmem = true;
    }
    }
    printf ("set\n");
	int* pr = initProc(p,temp.t->getN());
	int* m = initMem(mram,mswap,mpssd,msssd,mhdd,temp.t->getN());
	printf ("init\n");
	temp.t->runTask(pr,m,temp.t->getNum());
	if(temp.t->getEndTask())
	 ctask++;
	 printf ("\nctask: %d",ctask);
}
void Calendar::clearTask(int timestart)
{
	printf ("Clear Task\n");
	event temp;
	int count=0;
	queue<event> l = q;
	queue<event> r;
	bool find = false;
	while(!l.empty()) {
        temp = l.front();
        count++;
      // printf ("%d",temp.t->getEndTask()); 
    if ((temp.t->getEndTask() && temp.timestart==timestart) || (temp.t->getError() && temp.timestart==timestart))
    {
    find = true;
	for (int i=0;i<p->getPnc();i++)
	 if (p->getPCoreStateNum(i,temp.t->getN()) && p->getPCoreState(i))
	  p->setPCoreState(i,0);
	for (int i=0;i<p->getLnc();i++)
	 if (p->getLCoreStateNum(i,temp.t->getN()) && p->getLCoreState(i))
	  p->setLCoreState(i,0);  	  
	for (int i=0;i<mram->getMCount();i++)
	 if (mram->getMCellNum(i,temp.t->getN()) && mram->getMCell(i))
	 mram->setMCell(i,0);
	for (int i=0;i<mswap->getMCount();i++)
	 if (mswap->getMCellNum(i,temp.t->getN()) && mswap->getMCell(i))
	 mswap->setMCell(i,0);
	for (int i=0;i<mpssd->getMCount();i++)
	 if (mpssd->getMCellNum(i,temp.t->getN()) && mpssd->getMCell(i))
	 mpssd->setMCell(i,0);
	for (int i=0;i<msssd->getMCount();i++)
	 if (msssd->getMCellNum(i,temp.t->getN()) && msssd->getMCell(i))
	 msssd->setMCell(i,0);
	  if (temp.t->getEndTask())
	    gl_time+=temp.t->getTimeTask();
	  if (temp.t->getError())
	    gl_time+=delay;
	for (int i=0;i<mhdd->getMCount();i++)
	 if (mhdd->getMCellNum(i,temp.t->getN()) && mhdd->getMCell(i))
	 mhdd->setMCell(i,0);
	printf("\n!!!!!!!!!!!\n");
    break;
	}
	l.pop();
   }
  printf ("rewrite\n");
  if (find)
  {
  int qsize = q.size();
  for (int i=0;i<qsize;i++)
  {
  	if (i!=count-1)
  	r.push(q.front());
    q.pop();
  }
  q = r;
  }
  clean(gl_time);
}
void Calendar::show()
{   
	event temp;
	queue<event> qt = q;
	while(!qt.empty())
	{
		temp = qt.front();
		printf ("number of task: %d time of start: %d\n",temp.t->getN(),temp.timestart);
		qt.pop();
	}
}
int Calendar::getIndex()
{
	return index;
}
void Calendar::setIndex(int i)
{
	index = i;
}
bool Calendar::getTimeTask(int time){
	queue<event> t = q;
	event tmp;
	while(!t.empty())
	{
		tmp = t.front();
		if (tmp.timestart==time)
		return true;
		t.pop();
	}
	return false;
} 
void Calendar::clean(int time)
{
	queue<event> r;
	event temp;
	int size = q.size();
	while (!q.empty())
	{
		temp = q.front();
		if (temp.timestart>time)
		{
		r.push(temp);
		}
		q.pop();
	}
	q = r;
	printf ("Clean events: %d \n",size-q.size());
}
void Calendar::clearAll()
{
	while(!q.empty())
	{
		q.pop();
	}
}
int Calendar::getCTask()
{
	return ctask;
}
