
#include "ODE.h"
#include "ODE2.h"
#include<iostream>
#include<math.h>

     ODE2::ODE2()
     {
          std::cout<<"Constructing an ODE of the form : dy/dt = constant * y^p";
     }
     
     double ODE2::f(double y, double t)
     {
          return _cons*pow(y,_y_order);
     }

     double ODE2::df(double y, double t)
     {
          return _cons*_y_order*pow(y,_y_order-1);
     }

     double ODE2::analytical(double y, double t) 
     {
        double yd = exp(_cons*t*(_y_order-1)*(-1));
        return (1/yd,1/(_y_order-1));
     }



