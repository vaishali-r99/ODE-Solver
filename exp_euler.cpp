#include<iostream>
#include<vector>
#include<cmath>



std::vector<double> exp_euler(double y_0, double h, double t, double t_end)
{   std::vector<double> y_res;
    
    double y=y_0;
    double f;
    int size = t_end/h +1;
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
