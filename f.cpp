#include<iostream>
#include<vector>
#include<math.h>
#include"f.h"


double f(double y, double t)
{
    double fn;  // to calculate the function f(y,t) 

    fn=y*pow(t,3)-1.5*y;
    //fn=pow(y,3);
    return fn;
}

 