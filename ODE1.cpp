
#include "ODE.h"
#include "ODE1.h"
#include<iostream>
#include<math.h>

     ODE1::ODE1()
     {
          std::cout<<"Constructing an ODE of the form : dy/dt = constant * y";
     }
     
     double ODE1::f(double y, double t)
     {
          return _cons*y;
     }
     
     double ODE1::df(double y, double t)
     {
          return _cons;
     }

     double ODE1::analytical(double y, double t) 
     {
          return exp(t);
     }


     


