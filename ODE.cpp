#include<iostream>
#include "ODE.h"
#include<vector>
ODE::ODE()
{
    std::cout<<"Constructing an abstract ODE";
}



    void ODE::setter()
    {

    double a;
    std::cout<<"Enter the choice of ODE you want to solve \n 1. constant * y \n 2. constant * y^p \n 3. constant * y * (polynomial in t) \n 4. constant * y^p * (polynomial in t)\n ";
    std::cin>>_choice;
    std::cout<<"Enter the constant";
    std::cin>>_cons;
    std::cout<<"Enter the order of y";
    std::cin>>_y_order;
    std::cout<<"Enter the order of t in the polynomial";
    std::cin>>_t_order;

    for(int i = 0;(i<=_t_order && _t_order >0);i++)
    {   std::cout<<"Enter the co-efficient of t^"<<i<<"\n";
        std::cin>>a;
        _cof.push_back(a);
    }


    }