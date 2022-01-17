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
    int i = 0;   

    while(abs(e)>epsilon)
    {   
        G= y*pow(t,3)-1.5*y ;    //function G
        dG=  1 - _h*(pow(t,3)-1.5);               // error term used here in the Newton Iteration y_n+1 = y_n-G_n/dG_n
        e = G/dG
        y = y-e;
        i=i+1;
        if(i>=100)
        break;
    }

    return y;                   // return the value to Implicit Euler
}
