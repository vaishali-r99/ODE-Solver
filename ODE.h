
#ifndef ODE_H
#define ODE_H
#include<vector>
class ODE
{

    protected:

    int _choice;
    double _y_order;
    double _t_order;
    double _cons;
    std::vector<double> _cof;
    

    public:
    ODE() = default;
    virtual double f(double , double ) = 0; //should it be constant? 

    virtual double df(double, double) = 0;

    virtual double analytical(double , double ) = 0; //should it be constant? 

    void setter();


    virtual ~ODE() = default;


};

#endif 