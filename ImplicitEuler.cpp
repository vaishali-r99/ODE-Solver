#include<iostream>
#include<vector>
#include<math.h>
#include"ImplicitEuler.h"
#include"f.h"
#include"newton.h"
#include<fstream>



ImplicitEuler::ImplicitEuler(double y0,double h,double t_end)
:scheme(y0,h,t_end,SchemeType::Implicit)
{

    std::cout<<"Constructing Implicit Euler solver object";
}


void ImplicitEuler::Solver() const
{

std::vector<double> y,time,y_analytical; // y- stores the result vector, time- time vector, y_analytical- stores the analytical solution
//The analytical solution calculated manually using integration for the given ODE: y=y0*e^(0.25*t^4-1.5*t)
double yd,y_res,ya,t; //
int N; // size of vector solution
int cnt=0;  // counter to check for number of error terms
y_res = _y0; 
t = 0.0;
N = _t_end/_h + 1;
double err=0.0; // error
/*for (int i = 0; i<N; i++)

{   ya=_y0*exp((pow(t,4)/4)-1.5*t);     // analytical term
    y_analytical.push_back(ya);  
    t=t+_h;                   
    yd = newton(_h,y_res+_h*f(y_res,t),t);                  //newton solution
    time.push_back(t);
    y_res= y_res+_h*f(yd,t);                //implicit solution
    y.push_back(y_res);
}*/
for ( int i = 1; i<N; i++)

{   t=t+_h;
    ya=_y0*exp((pow(t,4)/4)-1.5*t);     // analytical term
    //ya=sqrt(pow(_y0,2)/(1-2*pow(_y0,2)*t));
    y_analytical.push_back(ya);                     
    yd = newton(_h,y_res+_h*f(y_res,t),t); //newton solution
    time.push_back(t);
    y_res= y_res+_h*f(yd,t);                //implicit solution
    y.push_back(y_res);
}    
std::ofstream file;
file.open ("results.txt", std::ios::app);

std::cout<<"The solution by Implicit Euler method is \n";
file<<"The solution by Implicit Euler method is \n";
std::cout<<"Analytical Solution \t"<<"Implicit Scheme Solution \n";
file<<"Analytical Solution \t"<<"Implicit Scheme Solution \n";
for (int i = 0; i<N; i++)
{   err=fabs(y[i]-y_analytical[i]);       //check for the error between the analytical solution and scheme result
    if(err>0.1)                    //if error> threshold value, increment counter
        cnt++;    
    std::cout<<y_analytical[i]<<"\t"<<y[i]<<"\n";
    file<<y_analytical[i]<<"\t"<<y[i]<<"\n";
}

if(cnt>=y_analytical.size()/2)                        //if more than half terms in the result vector have error above threshold, method is declared inefficient
{
    std::cout<<"\n Test Case Failed. Implicit method is not suitable for this case.";
}
else
{
    std::cout<<"\n Test case Passed. Implicit method is suitable for this case.";
}
cnt=0;

file.close();

}