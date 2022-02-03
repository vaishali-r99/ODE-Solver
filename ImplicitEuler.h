#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include"scheme.h"
#include"newton.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"


class ImplicitEuler:public scheme
{


public:
        
        ImplicitEuler(double,double,double);
        
        void Solver() const override;

};




#endif
