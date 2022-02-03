Initially the raw code produced the following output:
(using chrono)
Enter intial y y(0)=1
Enter the interval size h= 0.1
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver object
 The solution by Implicit Euler method is
Time    Analytical Solution     Implicit Scheme Solution
0       1       1
0.1     0.860729        0.869565
0.2     0.741115        0.756209
0.3     0.638921        0.658031
0.4     0.552335        0.573548
0.5     0.479805        0.501528
0.6     0.419958        0.440904
0.7     0.371586        0.390734
0.8     0.333671        0.350214
0.9     0.305448        0.318724
1       0.286505        0.295909
1.1     0.276934        0.281818
1.2     0.277593        0.277135
1.3     0.290551        0.283601
1.4     0.319947        0.304849
1.5     0.373673        0.34816
1.6     0.466919        0.428505
1.7     0.630038        0.578748
1.8     0.927187        0.878621
1.9     1.50384 1.55014
2       2.71828 3.3401

 Test case Passed. Implicit method is suitable for this case.Elapsed time: 0.015 seconds

_______________________________________________________________________________________________
Applying optimization 1: computation expenses:
 -replacing the math functions with simpler algebraic form
 -using multiplication in place of division
Eg: 	G = y - (_h*((y*pow(t,3))-(1.5*y))) - yi ;  
=>	t_c=t*t*t;
        G = y - (_h*t_c-(1.5*y))) - yi ;    //function G

ya=_y0*exp((pow(t,4)/4)-1.5*t); 
=>ya=_y0*exp(t_4*0.25)-1.5*t);

RESULT:
Enter intial y y(0)=1   
Enter the interval size h= 0.1
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver object
 The solution by Implicit Euler method is
Time    Analytical Solution     Implicit Scheme Solution
0       1       1
0.1     0.860708        0.869565
0.2     0.740818        0.756209
0.3     0.637628        0.658031
0.4     0.548812        0.573548
0.5     0.472367        0.501528
0.6     0.40657 0.440904
0.7     0.349938        0.390734
0.8     0.301194        0.350214
0.9     0.25924 0.318724
1       0.22313 0.295909
1.1     0.19205 0.281818
1.2     0.165299        0.277135
1.3     0.142274        0.283601
1.4     0.122456        0.304849
1.5     0.105399        0.34816
2       0.0497871       3.3401

 Test case Passed. Implicit method is suitable for this case.
 Elapsed time: 0.013 seconds
___________________________________________________________________________________________
Applying 2nd Optimization: reducing if-else 

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
replaced with switch case

Enter intial y y(0)=1
Enter the interval size h= 0.1
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver object
 The solution by Implicit Euler method is
Time    Analytical Solution     Implicit Scheme Solution
0       1       1
0.1     0.860708        0.869565
0.2     0.740818        0.756209
0.3     0.637628        0.658031
0.4     0.548812        0.573548
0.5     0.472367        0.501528
0.6     0.40657 0.440904
0.7     0.349938        0.390734
0.8     0.301194        0.350214
0.9     0.25924 0.318724
1       0.22313 0.295909
1.1     0.19205 0.281818
1.2     0.165299        0.277135
1.3     0.142274        0.283601
1.4     0.122456        0.304849
1.5     0.105399        0.34816
1.6     0.090718        0.428505
1.7     0.0780817       0.578748
1.8     0.0672055       0.878621
1.9     0.0578443       1.55014
2       0.0497871       3.3401

 Test case Passed. Implicit method is suitable for this case.
 Elapsed time: 0.012 seconds
__________________________________________________________________________________________________________________

Applying 3rd Optimization : Loop fusion

combined 2 for-loops into one loop in both Explicit and Implicit Euler functions

Enter intial y y(0)=1
Enter the interval size h= 0.1
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver object
 The solution by Implicit Euler method is
Time    Analytical Solution     Implicit Scheme Solution
0       1       1
0.1     0.860729        0.869565
0.2     0.741115        0.756209
0.3     0.638921        0.658031
0.4     0.552335        0.573548
0.5     0.479805        0.501528
0.6     0.419958        0.440904
0.7     0.371586        0.390734
0.8     0.333671        0.350214
0.9     0.305448        0.318724
1       0.286505        0.295909
1.1     0.276934        0.281818
1.2     0.277593        0.277135
1.3     0.290551        0.283601
1.4     0.319947        0.304849
1.5     0.373673        0.34816
1.6     0.466919        0.428505
1.7     0.630038        0.578748
1.8     0.927187        0.878621
1.9     1.50384 1.55014
2       2.71828 3.3401

 Test case Passed. Implicit method is suitable for this case.
 Elapsed time: 0.011 seconds
