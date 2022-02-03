#ifndef ODE3_H
#define ODE3_H

#include "ODE.h"
#include<vector>

class ODE3:public ODE
{

    public:
    ODE3() = default;

    
    double analytical(double, double) override;
    double f(double, double) override;
    double df(double, double) override;
};



#endif
