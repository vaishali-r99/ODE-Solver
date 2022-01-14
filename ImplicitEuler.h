#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include"scheme.h"
#include"newton.h"

class ImplicitEuler:public scheme
{


public:
        
        ImplicitEuler(double,double,double);
        
        void Solver() const override;

};




#endif