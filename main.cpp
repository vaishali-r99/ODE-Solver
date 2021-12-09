/*
/* Input for the values of time step (h) and end time (t_end) is taken from the user
y_0 is initialized 
using exp_euler () fn, result is calculated and stored in y_result vector
using analytical_soln () fn, analytical solution is obtained and stored in analytical_result vector
err defined as the absolute value of difference between analytical solution and computed result
here in test case at each timestep reading, err is computed and a counter cnt is used check if the err>0.1 [assumption]
if the err criteria is true for more than half the results, then it is flaged as an inefficient solution and inputs should be changed.


*/


*/



#include<iostream>
#include<vector>
#include<cmath>
#include"exp_euler.h"
#include"analytical_soln.h"


int main()
{
    double t,h,y,t_end,y_0;
    std::cout<<"\n Please enter the time step: ";
    std::cin>>h;
    std::cout<<"\n Enter the end time:";
    std::cin>>t_end;
    std::cout<<"\n Enter the initial value:";
    std::cin>>y_0;
    
    std::vector<double> y_result;
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
        err= fabs(analytical_result[i]-y_result[i]);
        if( err>0.1)
         cnt++;

    }
    if(cnt>(y_result.size()/2))
        std::cout<<"\n Test case failed! Method not suitable for the given problem"; 
    else
         std::cout<<"\n Test case passed! Method suitable for the given problem";;


}


