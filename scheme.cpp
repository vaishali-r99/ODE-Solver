#include <iostream>
#include<vector>
#include<math.h>
#include "scheme.h"


scheme::scheme(double y0,double h,double t_end,SchemeType Type)
: _y0(y0),_h(h),_t_end(t_end),_type(Type)
{
    std::cout<<"constructing an abstract scheme \n";

}

