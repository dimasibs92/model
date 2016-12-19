#include <iostream>
#include "system.h"
#include "Calendar.h"
#include <time.h>
#include <fstream>
#define input 17
int main(int argc, char** argv) {
	extern bool list;
	extern int gl_time;
	srand(time(NULL));
	int arg[input];
	if (argc>=2)
	{
		ifstream ifs;
		ifs.open(argv[1]);
		for (int i=0;i<input;i++)
		{
			ifs >> arg[i]; 
		}
		ifs >> list;
		printf ("%d %d\n",arg[0],arg[1]);
    }
    else
    {
    	printf ("default\n");
    	arg[0] = 2; 	// count of physical cores of processor
    	arg[1] = 2;		// count of logical cores of processor 
    	arg[2] = 8;		// count of cells of ram
    	arg[3] = 256; 	// size of one ram
    	arg[4] = 1600; 	// frequency of one cell ram
    	arg[5] = 2;		// count of cells of swap
    	arg[6] = 512;	// size of one cell swap
    	arg[7] = 500;	// speed of transmit data from swap to ram
    	arg[8] = 32;    // count of cells of ssd pci-ex
    	arg[9] = 1024;  // size of one cell ssd pci-ex
    	arg[10] = 1000; // speed of transmit data from ssd pci-ex to ram
    	arg[11] = 32;	// count of cells of ssd sata3
    	arg[12] = 1024; // size of one cell ssd sata3 
		arg[13] = 500;	// speed of transmit data from ssd sata to ram
		arg[14] = 80;   // count of sectors of hdd
		arg[15] = 1024;	// size of one sector hdd
		arg[16] = 50;   // speed of transmit data from hdd to ram
		list = false; 
    }
    gl_time=0;
    Calendar* cal = new Calendar(arg,list);
    cal->add(1,gl_time);    
	cal->runTask(gl_time);
	cal->clearTask(gl_time);
	cal->show();
	gl_time++;	
	int i=0,t=0;
    while(i<200)
    {
     if (cal->getTimeTask(gl_time))
     {
      cal->runTask(gl_time); 
      cal->clearTask(gl_time);
	 }
	 else
	 {
	 printf ("after run and clean: %d\n",gl_time);
     i = cal->getIndex();
     
     cal->setIndex(i++);
     while(1) {
     if (t>=gl_time+1 && t<gl_time+10)
     break;
     t = gl_time+static_cast <int> (exp_rasp(ret_val()));
 	}
	 cal->add(i,t);
	cal->show();
	}
	gl_time++;
    }
    cal->clearAll();
    printf ("Count of complete tasks: %d",cal->getCTask());
	return 0;
}
