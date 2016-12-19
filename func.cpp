#include "func.h"
double getLrand(double l)
{
   return (log(rand()+1)-LOFFSET)/(-l);
}
double ret_val()
{
	return (double)rand()/RAND_MAX;
}
int* select_no_return(int count,int need)
{
	int* n = new int[need]; 
	vect* v = new vect[count];
	for (int i=0;i<count;i++)
	{
		v[i].value = i;
		v[i].p = (float)1/count;
	}
    float sum=0;
    float cur=0;
    double s=0;
    int j=0;
 //   printf ("count = %d need = %d\n",count,need);
    while (need!=0)
    {
    s=0;sum=0;
    for (int i=0;i<count;i++)
    {
      s+=v[i].p;
    }
    cur = ret_val();
    for(int i=0;i<count;i++)
    {
    	sum+=v[i].p;
    	if (sum>=cur*s)
    	{
 //   		printf("%d - %f %f %f\n",i,sum,cur,s);
		v[i].p=v[count-1].p;
    			n[j] = v[i].value;
    		v[i].value = v[count-1].value;
    		j++;
    		need--;
    		count--;
    	    break;
//    	    }
    	}
    }
    }
    return n;
}
double f(double x)
{
	return 0.5*sin(x);
}
double method_reverse(){
	double nu = ret_val();
	return acos(1-2*nu);
}
double method_otbr()
{
	double psi = ret_val();
	double nw = ret_val();
	while(nw>f(psi*pi))
	{
		printf("%f , %f\n",nw,f(psi*pi));
		nw = ret_val();
	} 
	return nw;
}
double exp_rasp(double l)
{
//	while (n>0)
//	{
		return getLrand(l);
//		n--;
//	}
}
