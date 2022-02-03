#ifndef ODE4_H
#define ODE4_H

#include "ODE.h"
#include<vector>

class ODE4:public ODE
{

    public:
    ODE4() = default;

  
    double analytical(double, double) override;
    double f(double, double) override;
    double df(double, double) override;
};



#endif
