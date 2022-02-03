#ifndef ODE1_H
#define ODE1_H

#include "ODE.h"
class ODE1:public ODE
{
    public:
    ODE1() = default;

    
    double analytical(double, double) override;
    double f(double, double) override;
    double df(double, double) override;
};



#endif
