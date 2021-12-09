#include<iostream>
#include<vector>
#include<cmath>




double analytical_soln(double y_0, double t)
{   double res;
    res = y_0 *(exp(0.25*pow(t,4)-1.5*t));
    return res;
}

