#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include"scheme.h"

class ExplicitEuler:public scheme
{

public:
        
        ExplicitEuler(double,double,double);
        
        void Solver() const override;

};




#endif