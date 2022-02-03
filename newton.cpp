#include<iostream>
#include<vector>
#include<math.h>
#include "newton.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"

double newton(double _h, double yi, double y,double t)        
{
    //double newton(double _h, double yi, double y,double t,ODE _ode) 
    double G,dG;
    double epsilon = 0.000000000000001;       // accuracy parameter considered in this case
    double t_c=t*t*t;                 
    double e = 1;   
               // error term used here in the Newton Iteration y_n+1 = y_n-G_n/dG_n
          //function df
    //dG = 1 - (h*_ode.df(y,t))      
    dG = 1 - (_h*t_c-1.5);  
    //dG = 1 - (_h*(pow(t,3)-1.5));

    while(abs(e)>epsilon)
    { // G = y - (_h*((y*pow(t,3))-(1.5*y))) - yi ;  
        G = y - (_h*(y*t_c-(1.5*y))) - yi ;    //function G
       // G = y - (_h*_ode.f(y,t)) - yi;
        e = (G/dG);
        y = y-e;
        //std::cout<<"\n y "<<y<<"\n G "<<G<<" \n e "<<e<<" \n";
    }

    return y;                   // return the value to Implicit Euler
}
