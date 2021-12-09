 #include<iostream>
 #include<vector>
 #include "f1.h"

/*
This function is the ODE we wish to solve : dy/dt = -3y^2 
y = Value at the current time step (i)
t = Current time (i*dt)
r = Value of the function when (y,t) are substituted, which is returned to the Euler function 
*/

double f1(double y, double t)    
{   double r = -3*y*y;
    return r;
}

