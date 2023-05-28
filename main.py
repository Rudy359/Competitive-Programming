c = [0, 0, 0, 0] # Dummy objective function

A = [
[3, 5, 3, 4],
[4, 3, 2, 1],
[1, -1, 0, 2],
[2, 2, -1, -3]
]

b = [2, 5, 1, -4]

import numpy as np
from scipy.optimize import linprog

# Coefficients of the linear inequalities
c = [0, 0, 0, 0]  # Dummy objective function
A = [[3, 5, 3, 4], [4, 3, 2, 1], ...]  # Coefficients of x, y, z, w for each inequality
b = [2, ..., ]  # Right-hand side of each inequality

# Bounds for variables
x_bounds = (None, None)
y_bounds = (None, None)
z_bounds = (None, None)
w_bounds = (None, None)

# Solve the system of linear inequalities
res = linprog(c, A_ub=A, b_ub=b, bounds=[x_bounds, y_bounds, z_bounds, w_bounds])

if res.success:
    print("The system of linear inequalities is feasible.")
    print("Solution:")
    print("x =", res.x[0])
    print("y =", res.x[1])
    print("z =", res.x[2])
    print("w =", res.x[3])
else:
    print("The system of linear inequalities is infeasible.")
