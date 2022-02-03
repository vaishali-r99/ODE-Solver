#ifndef SCHEME_H
#define SCHEME_H
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"


enum class SchemeType {
    Explicit,
    Implicit,
};


class scheme
{
    protected:

    double _y0 ;         // y(0)
    double _h ;          //time step
    double _t_end;      //end time
    SchemeType _type ;   //method
    /*
    std::unique_ptr<ODE> _myODE; 
    */

    public:
    scheme(double,double,double,SchemeType);

    virtual void Solver() const = 0;        

    virtual ~scheme() = default;
};
#endif //
