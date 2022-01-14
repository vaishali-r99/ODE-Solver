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





Example:(sprint 1)
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

