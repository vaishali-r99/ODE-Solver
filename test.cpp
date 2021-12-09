#include<iostream>
#include<vector>
#include<cmath>
#include"exp_euler.h"
#include"analytical_soln.h"

void test()
{

std::vector<double> y_result;

double y_0 = 1;
double h = 1;
double t = 0;
double t_end = 20;

y_result=exp_euler(y_0,h,t,t_end);   

double err;
    int cnt=0;
    double t_a=0.0;
    double a_res;
    std::vector<double> analytical_result;
    while(t_a<=t_end)
    {   
        analytical_result.push_back(analytical_soln(y_0, t_a));
        t_a+=h;
    }
     std::cout<<"\n Exp. Euler Soln. \t Analytical soln. : ";
    for(auto i=0;i<y_result.size();i++)
    {
        std::cout<<"\n"<<y_result[i]<<"\t"<<analytical_result[i];
        err = fabs(analytical_result[i]-y_result[i]);
        if( err>0.1)
         cnt++;

    }
    if(cnt>(y_result.size()/2))
        std::cout<<"\n Test case failed! Method not suitable for the given problem"; 
    else
         std::cout<<"\n Test case passed! Method suitable for the given problem";

}
