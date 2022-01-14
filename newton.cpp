#include<iostream>
#include<vector>
#include<math.h>
#include"newton.h"

double newton(double _h, double y,double t)        
{
    double G,dG;
    double epsilon = 0.1;       // accuracy parameter considered in this case
    double yi = y;                  
    double e = 0;    
    G= y*pow(t,3)-1.5*y ;    //function G
    dG= 3*y*pow(t,2);               // error term used here in the Newton Iteration y_n+1 = y_n-G_n/dG_n
          //function dG
    while(abs(e)>epsilon)
    {   
        e = (y-(_h*G+yi)/(1-_h*dG));
        y = y-e;
    }

    return y;                   // return the value to Implicit Euler
}
