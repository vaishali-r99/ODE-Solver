#include <iostream>
#include<vector>
#include<math.h>
#include "scheme.h"
#include "ODE.h"
#include "ODE1.h"
#include "ODE2.h"
#include "ODE3.h"
#include "ODE4.h"


scheme::scheme(double y0,double h,double t_end,SchemeType Type)
: _y0(y0),_h(h),_t_end(t_end),_type(Type)
{
    std::cout<<"constructing an abstract scheme \n";
    /*
    
    _myODE.setter();
    if(_choice==1)
        {
            _myODE = std::make_unique<ODE1>();
            
        }
    else if(_choice==2)
        {
            _myODE = std::make_unique<ODE2>();
          
        }
    else if(_choice==3)
        {
            _myODE = std::make_unique<ODE3>();
          
        }    
    else if(_choice==4)
        {
            _myODE = std::make_unique<ODE4>();
          
        }    
    else
        {std::cout<<"Choice does not exist";}


    */

}

