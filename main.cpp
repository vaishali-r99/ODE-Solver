#include <iostream>
#include<vector>
#include<math.h>
#include <memory>

#include "scheme.h"
#include"ExplicitEuler.h"
#include"ImplicitEuler.h"


void implement_solver(std::unique_ptr<scheme> &s)
{
    s->Solver();
}


int main()
{
    int choice;     //choice- to select the solving method
    double y0,h,t_end; 
    
    //tried with y0=1
    y0=1;
    std::cout<<"Enter the interval size h= ";
    std::cin>>h;
    std::cout<<"Enter the end time T_end= ";
    std::cin>>t_end;
    std::cout<<"Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler ";
    std::cin>>choice;
    std::unique_ptr<scheme> myScheme;
    if(choice==1)
        {
            myScheme = std::make_unique<ExplicitEuler>(y0,h,t_end);
            implement_solver(myScheme);
        }
    else if(choice==2)
        {
            myScheme = std::make_unique<ImplicitEuler>(y0,h,t_end);
            implement_solver(myScheme);
        }
    else
        {std::cout<<"Choice does not exist";}

      
    
}
