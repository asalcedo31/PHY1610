#ifndef COMPUTING_FUNC_H
#define COMPUTING_FUNC_H
int compute_denom(int i); // computes the denominator used by f and g
double f(double t); // computes sin(2*t)/(1+t*t)
double g(double t); // computes cos(3*t)/(1+t*t)
void printToFile(double *in_store_t, double *in_store_x, double *in_store_y, int in_arraysize); // recieves three arrays of length <=in_arraysize and prints the ith element of each array in a space delimited table saved to a file called lissajous.txt
#endif