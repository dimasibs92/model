#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h> 
#define pi 3.14159
#define LOFFSET log(RAND_MAX)
struct vect { int value; float p; 
};
double getLrand(double l);
double ret_val();
int* select_no_return(int count,int need);
double f(double x);
double method_reverse();
double method_otbr();
double exp_rasp(double l);
