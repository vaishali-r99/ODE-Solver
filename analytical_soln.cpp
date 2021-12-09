
// Computing the analytical solution
//The analytical solution calculated manually using integration for the given ODE: y=y0*e^(0.25*t^4-1.5*t)
//The two input parameters for the function are y0 and t values and returns the y value




#include<iostream>
#include<vector>
#include<cmath>




double analytical_soln(double y_0, double t)
{   double res;
    res = y_0 *(exp(0.25*pow(t,4)-1.5*t));
    return res;
}

