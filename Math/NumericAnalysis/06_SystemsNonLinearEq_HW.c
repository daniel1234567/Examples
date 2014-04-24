#include <stdio.h>
#include <math.h>
#include "06_SystemsNonLinearEq.h"

/* James M. Rogers
   03 April 2014

  compile with
    gcc matrix.c 06_SystemsNonLinearEq.c 06_SystemsNonLinearEq_HW.c -lm
*/

#define E 2.71828182845904523536

long double F1 (long double x[]) {
  return 3*x[0]-cosl(x[1]*x[2])-0.5;
}

long double F2 (long double x[]) {
  return x[0]*x[0]-81.0*(x[1]+0.1)*(x[1] +0.1)+sinl(x[2])+1.06;
}

long double F3 (long double x[]) {
  return powl(E, -x[0]*x[1]) + 20.0*x[2] + (10*M_PI-3.0)/3.0;
}

long double F1X1 (long double x[]) {
  return 3.0;
}

long double F1X2 (long double x[]) {
  return x[2]*sinl(x[1]*x[2]);
}

long double F1X3 (long double x[]) {
  return x[1]*sinl(x[1]*x[2]);
}

long double F2X1 (long double x[]) {
  return 2*x[0];
}

long double F2X2 (long double x[]) {
  return -162.0*(x[1]+0.1);
}

long double F2X3 (long double x[]) {
  return cosl(x[2]);
}

long double F3X1 (long double x[]) {
  return -x[1] * powl(E, -x[0]*x[1]) ;
}

long double F3X2 (long double x[]) {
  return -x[0] * powl(E, -x[0]*x[1]) ;
}

long double F3X3 (long double x[]) {
  return 20.0;
}

int
main ()
{
  SystemNL s = System_New(3, "Example from handout.");

  System_AddFunc(s, 1, 0, F1);
  System_AddFunc(s, 2, 0, F2);
  System_AddFunc(s, 3, 0, F3);

  System_AddJacobian(s, 1, 1, F1X1);
  System_AddJacobian(s, 1, 2, F1X2);
  System_AddJacobian(s, 1, 3, F1X3);
  System_AddJacobian(s, 2, 1, F2X1);
  System_AddJacobian(s, 2, 2, F2X2);
  System_AddJacobian(s, 2, 3, F2X3);
  System_AddJacobian(s, 3, 1, F3X1);
  System_AddJacobian(s, 3, 2, F3X2);
  System_AddJacobian(s, 3, 3, F3X3);

  System_Solve(s);

  System_Dispose(s);
  return 0;
}
