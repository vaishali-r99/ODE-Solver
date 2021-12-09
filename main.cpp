 #include<iostream>
 #include<vector>
#include "f1.h"
#include "euler1d.h"

int main()
{
    double y0;
    double t_end, dt;

    std::cout<<"Enter the Initial value of the equation \n";
    std::cin>>y0;
    std::cout<<"Enter the time step \n";
    std::cin>>dt;

    std::cout<<"Enter the end time \n";
    std::cin>>t_end;
    int n = t_end/dt + 1;
    double result[n],time[n];
    time[0] = 0;
    for(int i = 0; i < n; i++)
    time[i+1] = time[i] + dt;
  
    euler1d(y0,t_end,dt,result);
    std::cout<<"The result is \n";
    for(int i = 0; i < n; i++)
    std::cout<<time[i]<<'\t'<<result[i]<<'\n';

}
