
/* Here the function exp_euler() calculates the Explicit Euler solution of the ODE.
    The input parameters are y_0( y(0) value), h (time step), t and t_end
    here the formula y(n+1)=y(n)+h.f(y(n),t(n)) is implemented
    f(y(n),t(n)) or f is calculated using the given ODE equation: f=dy/dt=y*t^3-1.5*y
    t is incremented by h till t_end to find the values at each timestep reading.
    The result is stored in a vector y_res and returned as output
*/

#include<iostream>
#include<vector>
#include<cmath>



std::vector<double> exp_euler(double y_0, double h, double t, double t_end)
{   std::vector<double> y_res;
    
    double y=y_0;
    double f;
    int size = static_cast<int>(t_end/h +1);
    double yn;
    for(auto i=1;i<size;i++)
    {   f = y*pow(t,3)-1.5*y;
        yn=y+h*f;
        t=t+h;
        y_res.push_back(yn);
        y=yn;
    }
    return y_res;
}
