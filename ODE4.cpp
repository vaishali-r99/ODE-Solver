
#include "ODE.h"
#include "ODE4.h"
#include<iostream>
#include<math.h>
#include<vector>

     ODE4::ODE4()
     {
        std::cout<<"Constructing an ODE of the form : dy/dt = constant * y^p * (polynomial in t)";
     }
     
     double ODE4::f(double y, double t)
     {  double t_up=0;
            for(int i = 0; i<=_t_order;i++)
            t_up += _cof[i]*pow(t,i);
            return _cons*pow(y,_y_order)*t_up;
     }

     double ODE4::df(double y, double t)
     {      
            double t_up=0;
            for(int i = 0; i<=_t_order;i++)
            t_up += _cof[i]*pow(t,i);
          return _cons*_y_order*pow(y,_y_order-1)*t_up;
     }

     double ODE4::analytical(double y, double t) 
     {

        double td=0; double yd = 0;
        for(int i = 0;i<=_t_order;i++)
        td += _cof[i]*pow(t,i+1)/i+1;
        double yd = exp(_cons*t*(_y_order-1)*(-1));
        return (1/yd,1/(_y_order-1));

     }



