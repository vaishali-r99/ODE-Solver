/*
This is the main function that goes on to solve the ODE using Explicit Euler Scheme after accepting the following inputs:
y0 = Initial value of the integrated ODE y(t) ; y(0) = y0
t_end = End time of the Explicit Euler Scheme
dt = Time step size of the Explicit Euler Scheme


n = No. of time steps
time = Array that stores the time values
result = Array of values that is the solution to the ODE y(t)

*/



#include<iostream>
#include<vector>
#include<cmath>
#include"exp_euler.h"
#include"analytical_soln.h"


int main()
{
    double t,h,y,t_end,y_0;
    std::cout<<"\n Please enter the time step: ";
    std::cin>>h;
    std::cout<<"\n Enter the end time:";
    std::cin>>t_end;
    std::cout<<"\n Enter the initial value:";
    std::cin>>y_0;
    
    std::vector<double> y_result;
    y_result=exp_euler(y_0,h,t,t_end);


}


