
#include "ODE.h"
#include "ODE3.h"
#include<iostream>
#include<math.h>
#include<vector>

     ODE3::ODE3()
     {
        std::cout<<"Constructing an ODE of the form : dy/dt = constant * y * (polynomial in t)";
     }
     
     double ODE3::f(double y, double t)
     {  double t_up=0;
        for(int i = 0; i<=_t_order;i++)
        t_up += _cof[i]*pow(t,i);
        return _cons*y*t_up;
        
     }

      
     double ODE3::df(double y, double t)
     {      
            double t_up = 0;
            for(int i = 0; i<=_t_order;i++)
            t_up += _cof[i]*pow(t,i);
          return _cons*t_up;
     }


     double ODE3::analytical(double y, double t) 
     {
        double td=0;
        for(int i = 0;i<=_t_order;i++)
        td += _cof[i]*pow(t,i+1)/i+1;
        return exp(_cons*td);

     }



