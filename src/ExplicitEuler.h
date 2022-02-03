#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include"scheme.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"

class ExplicitEuler:public scheme
{

public:
        
        ExplicitEuler(double,double,double);
        
        void Solver() const override;

};




#endif
