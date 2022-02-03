#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include"ExplicitEuler.h"
#include"f.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"




ExplicitEuler::ExplicitEuler(double y0,double h,double t_end)
:scheme(y0,h,t_end,SchemeType::Explicit)
{

    std::cout<<"Constructing Explicit Euler solver object";

}


void ExplicitEuler::Solver() const
{

std::vector<double> y,time, y_analytical; // y- stores the result vector, time- time vector, y_analytical- stores the analytical solution
//The analytical solution calculated manually using integration for the given ODE: y=y0*e^(0.25*t^4-1.5*t)
int N, cnt=0; //N-size of result vector, cnt- counter for error terms
double err=0.0,ya,t,y_res; // err-error , ya= term in analytical solution
y_res = _y0;
t = 0.0;
N = _t_end/_h + 1;
double t_4= t*t*t*t;

std::ofstream file;
file.open ("results.txt", std::ios::app);

// Display of results

std::cout<<"The solution by Explicit Euler method is \n";
file<<"The solution by Explicit Euler method is \n";
std::cout<<"Analytical Solution \t"<<"Explicit Scheme Solution \n";
file<<"Analytical Solution \t"<<"Explicit Scheme Solution \n";
for (int i = 0; i<N; i++)
{   ya=_y0*exp(t_4*0.25-1.5*t); //calculation of analytical solution
    //ya=sqrt(pow(_y0,2)/(1-2*pow(_y0,2)*t));
    y_analytical.push_back(ya);
    y_res=y_res+_h*f(y_res,t);
    // y_res=y_res+_h*_myODE.f(y_res,t);
    y.push_back(y_res);       // explicit euler solution
    //time.push_back(t);
    t=t+_h;
    err=y[i]-y_analytical[i];       //check for error
    if(err>0.1 || err<-0.1)                    //if error> threshold value, increment counter
        cnt++; 
    std::cout<<y_analytical[i]<<"\t"<<y[i]<<"\n";
    file<<y_analytical[i]<<"\t"<<y[i]<<"\n";
}
//if more than half terms in the result vector have error above threshold, method is declared inefficient
if(cnt>=y_analytical.size()*0.5)
{
    std::cout<<"\n Test Case Failed. Explicit method is not suitable for this case.";
}
else
{
    std::cout<<"\n Test case Passed. Explicit method is suitable for this case.";
}



file.close();
//before optimization
/*for (int i = 0; i<N; i++)
{   ya=_y0*exp(t_4*0.25-1.5*t); //calculation of analytical solution
    //ya=sqrt(pow(_y0,2)/(1-2*pow(_y0,2)*t));
    y_analytical.push_back(ya);
    y_res=y_res+_h*f(y_res,t);
    // y_res=y_res+_h*_myODE.f(y_res,t);
    y.push_back(y_res);       // explicit euler solution
    //time.push_back(t);
    t=t+_h;
}
std::ofstream file;
file.open ("results.txt", std::ios::app);

// Display of results

std::cout<<"The solution by Explicit Euler method is \n";
file<<"The solution by Explicit Euler method is \n";
std::cout<<"Analytical Solution \t"<<"Explicit Scheme Solution \n";
file<<"Analytical Solution \t"<<"Explicit Scheme Solution \n";
for (int i = 0; i<N; i++)
{   err=y[i]-y_analytical[i];       //check for error
    if(err>0.1 || err<-0.1)                    //if error> threshold value, increment counter
        cnt++; 
    std::cout<<y_analytical[i]<<"\t"<<y[i]<<"\n";
    file<<y_analytical[i]<<"\t"<<y[i]<<"\n";
}*/



}
