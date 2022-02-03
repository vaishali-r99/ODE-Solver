#ifndef ODE2_H
#define ODE2_H

#include "ODE.h"
class ODE2:public ODE
{
    public:
    ODE2() = default;

    
    double analytical(double, double) override;
    double f(double, double) override;
    double df(double, double) override;
};



#endif
