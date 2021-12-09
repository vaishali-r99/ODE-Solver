#include<iostream>
#include<vector>
#include "f1.h"
#include "euler1d.h"

/*
y0 = Initial value of the function at time 0 y(0) = y0
t = End time of the Euler scheme
dt = Time step size of the Euler scheme
y = Array of solutions that stores values at each time step
n = Number of time steps
time = Array that stores time values 
*/

void euler1d(double y0, double t, double dt, double y[]) // arrays are passed by reference by default
{
    y[0] = y0;                  //Initializing y
    int n = t/dt + 1;          // No. of time steps 
    double time[n];           //Initializing time
    time[0] = 0;
    for(int i = 0; i < n; i++)
    {
    time[i+1] = time[i] + dt;                    //Updating Time by dt
    y[i+1] = y[i] + f1(y[i], time[i])*dt;       //Explicit Euler's Scheme step
    }

}
