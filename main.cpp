#include <iostream>
#include<vector>
#include<math.h>
#include <memory>
#include<chrono>

#include "scheme.h"
#include"ExplicitEuler.h"
#include"ImplicitEuler.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"

void implement_solver(std::unique_ptr<scheme> &s)
{
    s->Solver();
}


int main()
{
    int choice;     //choice- to select the solving method
    double y0,h,t_end; 
    
    //tried with y0=1
    //y0=1;
    std::cout<<"Enter intial y y(0)=";
    std::cin>>y0;
    std::cout<<"Enter the interval size h= ";
    std::cin>>h;
    std::cout<<"Enter the end time T_end= ";
    std::cin>>t_end;
    std::cout<<"Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler ";
    std::cin>>choice;
    std::unique_ptr<scheme> myScheme;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    start = std::chrono::system_clock::now();
   /* if(choice==1)
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
        {std::cout<<"Choice does not exist";}*/
    switch(choice)
     {case 1:   {
                myScheme = std::make_unique<ExplicitEuler>(y0,h,t_end);
                implement_solver(myScheme);
                }
                break;
     case 2:
        {
            myScheme = std::make_unique<ImplicitEuler>(y0,h,t_end);
            implement_solver(myScheme);
        }
        break;
     default:
        {std::cout<<"Choice does not exist";}
     }
    end = std::chrono::system_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "\n Elapsed time: " << elapsed.count()/1000.0 << " seconds" << std::endl;    

      
    
}
