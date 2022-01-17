#include<iostream>
#include<vector>
#include<math.h>
#include"newton.h"

double newton(double _h, double yi, double y,double t)        
{
    double G,dG;
    double epsilon = 0.000000000000001;       // accuracy parameter considered in this case
                     
    double e = 1;   
               // error term used here in the Newton Iteration y_n+1 = y_n-G_n/dG_n
          //function df
    dG = 1 - (_h*(pow(t,3)-1.5));  
    //std::cout<<"\n dG "<<dG;   
    while(abs(e)>epsilon)
    {  
        G = y - (_h*((y*pow(t,3))-(1.5*y))) - yi ;    //function G
        e = (G/dG);
        y = y-e;
        //std::cout<<"\n y "<<y<<"\n G "<<G<<" \n e "<<e<<" \n";
    }

    return y;                   // return the value to Implicit Euler
}
