# ODE solver
We have created an ODE solver for a given ODE using Explicit Euler Method and Implicit Euler Method.The user can select the method they wish to use. Time step and End time can be varied. 

Following tasks were to be completed:
For sprint 1-

-The project contains a comprehensive README.md file explaining how to use it, including an example.
-The user can give an ODE to solve, either at runtime (e.g. with std::function/lamda, if you know what this is already) or specify it directly in the code. Any additional parameters (e.g. the time step value) can be provided in any way.
-The solver prints or returns an std::vector of the solution.
-The project contains at least one unit test which compares one case with its analytic solution for correctness.

For sprint 2-
-The user can select different ode solvers / schemes at runtime.
-Every solver should give correct solutions for provided examples. All these examples should be accompanied by unit tests.
-The solvers should be using the same class interface.
-The README.md file should explain how one could extend the code to include a new solver

Work done in the code:
Sprint 1: 
-Computed the analytical values as well as the explicit euler solution values and calculated the error as absolute difference of the two. 
-This error value is used to determine whether the method is efficient or not.

Sprint 2:

- Implicit Euler scheme is added
- Two classes are used for the explicit and implicit schemes derived from an abstract class (scheme)
- User can select the solving scheme at the run-time
- The solvers use the same class interface (done using smart pointer)
- Test cases used to check whether the method gives suitable results or not.
- Writing the output to a file

The ODE used in the following code is dy/dt= y*t^3 -1.5*y
the initial value y(0)=1;
Here, we compute the Explicit Euler Solution, Implicit Euler Solution and the Analytical solution

Input from the user: timestep h value, end time t_end value and choice of solver to be used
Output : Explicit Euler or Implicit Euler solution and the statement based on error determining whether test case passed or failed

Description:

Multiple Inheritance used

Class scheme: an abstract class (Parent class)
Class ExplicitEuler: child class 
Class ImplicitEuler: child class

Further if more solving schemes are to be added, define other child classes similar to the above two schemes.
If Heun's Method is to be added as another method, following should be added:

class HeunsMethod:public scheme
{


public:
        
       HeunsMethod(double,double,double,SchemeType);
        
       void Solver() const override;

};


_________________________________________________________________________________
HeunsMethod::HeunsMethod(double y0,double h,double t_end,SchemeType Type)
:scheme(y0,h,t_end,SchemeType::Explicit)
{

    std::cout<<"Constructing Implicit Euler solver object";
}


void HeunsMethod::Solver() const
{

std::vector<double> y,time;


int N;
y[0] = _y0;
time[0] = 0;
N = _t_end/_h + 1;
std::ofstream file;
file.open ("results.txt", std::ios::app);

for (int i = 0; i<N; i++)

{
    time.push_back(time[i]+_h);
    y.push_back(y[i]+(_h/2)*(f(y[i])+f(y[i]+(_h*f(y[i])))));
}
    
std::cout<<"The solution by Heun's Method method is \n";
file<<"The solution by Heun's method is \n";
std::cout<<"Time \t"<<"y value \n";
file<<"Time \t"<<"y value \n";
for (int i = 0; i<N; i++)
{
    std::cout<<time[i]<<"\t"<<y[i]<<"\n";
    file<<time[i]<<"\t"<<y[i]<<"\n";
}


file.close();

}


Example:
CASE1: 
Enter the interval size h= 0.1
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver objectThe solution by Implicit Euler method is
Analytical Solution     Implicit Scheme Solution
0.860729        0.891395
0.741115        0.79424
0.638921        0.707591
0.552335        0.630836
0.479805        0.563564
0.419958        0.505512
0.371586        0.456559
0.333671        0.416782
0.305448        0.38659
0.286505        0.366985
0.276934        0.360087
0.277593        0.370301
0.290551        0.407256
0.319947        0.494908
0.373673        0.711808
0.466919        1.65325
0.630038        0.552912
0.927187        2.69429
1.50384 1.71599
2.71828 0.449485
0       0

 Test case Passed. Implicit method is suitable for this case.

CASE 2:
Enter the interval size h= 0.05
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 1
constructing an abstract scheme 
Constructing Explicit Euler solver objectThe solution by Explicit Euler method is
Analytical Solution     Explicit Scheme Solution
1       0.925
0.927745        0.855631
0.860729        0.791501
0.798617        0.732272
0.741115        0.677645
0.687961        0.627351
0.638921        0.581146
0.593779        0.538806
0.552335        0.50012
0.514403        0.46489
0.479805        0.432928
0.448376        0.40406
0.419958        0.37812
0.394406        0.354953
0.371586        0.334419
0.351376        0.316391
0.333671        0.300762
0.318384        0.28744
0.305448        0.276359
0.294825        0.267479
0.286505        0.260792
0.280516        0.256328
0.276934        0.254162
0.275891        0.254427
0.277593        0.257328
0.282339        0.263158
0.290551        0.272329
0.302818        0.285406
0.319947        0.303158
0.343052        0.326632
0.373673        0.357253
0.413955        0.396978
0.466919        0.448506
0.53687 0.515605
0.630038        0.603593
0.755577        0.720067
0.927187        0.876034
1.16576 1.08767
1.50384 1.37911
1.99322 1.78697
2.71828 2.36774

 Test case Passed. Explicit method is suitable for this case.

CASE 3:

Enter the interval size h= 0.2
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 1
constructing an abstract scheme 
Constructing Explicit Euler solver objectThe solution by Explicit Euler method is
Analytical Solution     Explicit Scheme Solution
1       0.7
0.741115        0.49112
0.552335        0.35007
0.419958        0.260172
0.333671        0.208762
0.286505        0.187886
0.277593        0.196454
0.319947        0.245331
0.466919        0.372707
0.927187        0.695621
2.71828 1.59993

 Test Case Failed. Explicit method is not suitable for this case.


CASE 4: 

Enter the interval size h= 0.5
Enter the end time T_end= 2
Enter your choice for solving the ODE 1. Explicit Euler 2. Implicit Euler 2
constructing an abstract scheme 
Constructing Implicit Euler solver objectThe solution by Implicit Euler method is
Analytical Solution     Implicit Scheme Solution
0.479805        0.923949
0.286505        4.2181
0.373673        3.65966
2.71828 1.33264
0       0

 Test Case Failed. Implicit method is not suitable for this case.



