# ODE solver
We have created an ODE solver for a given ODE using Explicit Euler Method and time step and time can be varied. 
For sprint 1, Following tasks were to be completed
-The project contains a comprehensive README.md file explaining how to use it, including an example.
-The user can give an ODE to solve, either at runtime (e.g. with std::function/lamda, if you know what this is already) or specify it directly in the code. Any additional parameters (e.g. the time step value) can be provided in any way.
-The solver prints or returns an std::vector of the solution.
-The project contains at least one unit test which compares one case with its analytic solution for correctness.

Work done in the code:
Computed the analytical values as well as the explicit euler solution values and calculated the error as absolute difference of the two. 
This error value is used to determine whether the method is efficient or not.

The ODE used in the following code is dy/dt= y*t^3 -1.5*y
the initial value y(0)=1;
Here, we compute the Explicit Euler Solution and the analytical solution

Input from the user: timestep h value and end time t_end value 
Output : euler and analytical solutions and the statement based on error determining whether test case passed or failed

Functions: 

double analytical_soln(double y_0, double t)

Computing the analytical solution
The analytical solution calculated manually using integration for the given ODE: y=y0*e^(0.25*t^4-1.5*t)
The two input parameters for the function are y0 and t values and returns the y value


std::vector<double> exp_euler(double y_0, double h, double t, double t_end)

Here the function exp_euler() calculates the Explicit Euler solution of the ODE.
The input parameters are y_0( y(0) value), h (time step), t and t_end
here the formula y(n+1)=y(n)+h.f(y(n),t(n)) is implemented
f(y(n),t(n)) or f is calculated using the given ODE equation: f=dy/dt=y*t^3-1.5*y
t is incremented by h till t_end to find the values at each timestep reading.
The result is stored in a vector y_res and returned as output


int main()

Input for the values of time step (h) and end time (t_end) is taken from the user
y_0 is initialized 
using exp_euler () fn, result is calculated and stored in y_result vector
using analytical_soln () fn, analytical solution is obtained and stored in analytical_result vector
err defined as the absolute value of difference between analytical solution and computed result
here in test case at each timestep reading, err is computed and a counter cnt is used check if the err>0.1 (assumption)
if the err criteria is true for more than half the results, then it is flaged as an inefficient solution and inputs should be changed. 


Example:
<1>
 Please enter the time step: 0.05

 Enter the end time:2

 Exp. Euler Soln.        Analytical soln. :
0.925           1
0.855631        0.927745
0.791501        0.860729
0.732272        0.798617
0.677645        0.741115
0.627351        0.687961
0.581146        0.638921
0.538806        0.593779
0.50012         0.552335
0.46489         0.514403
0.432928        0.479805
0.40406         0.448376
0.37812         0.419958
0.354953        0.394406
0.334419        0.371586
0.316391        0.351376
0.300762        0.333671
0.28744         0.318384
0.276359        0.305448
0.267479        0.294825
0.260792        0.286505
0.256328        0.280516
0.254162        0.276934
0.254427        0.275891
0.257328        0.277593
0.263158        0.282339
0.272329        0.290551
0.285406        0.302818
0.303158        0.319947
0.326632        0.343052
0.357253        0.373673
0.396978        0.413955
0.448506        0.466919
0.515605        0.53687
0.603593        0.630038
0.720067        0.755577
0.876034        0.927187
1.08767         1.16576
1.37911         1.50384
1.78697         1.99322
 Test case passed! Method suitable for the given problem


<2>
 Please enter the time step: 0.5

 Enter the end time:2

 Exp. Euler Soln.        Analytical soln. :
0.25    1
0.078125        0.479805
0.0585938       0.286505
0.113525        0.373673
 Test case failed! Method not suitable for the given problem

