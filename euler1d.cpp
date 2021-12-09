#include<iostream>
#include<vector>
#include "f1.h"
#include "euler1d.h"

void euler1d(double y0, double t, double dt, double x[])
{
    x[0] = y0; 
    int n = t/dt + 1;
    double time[n];
    time[0] = 0;
    for(int i = 0; i < n; i++)
    {
    time[i+1] = time[i] + dt;
    x[i+1] = x[i] + f1(x[i], time[i])*dt;
    }

}