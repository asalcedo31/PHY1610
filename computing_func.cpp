#include <cmath>
int compute_denom(int i){
	int out = 1+i*i;
	return(out);
}
double f(double t){
	double numerator = sin(2*t);
	double denominator = compute_denom(t);
	double output = numerator/denominator;
	//std::cout << numerator << "\n"
	return(output);
}
double g(double t){
	double numerator = cos(3*t);
	double denominator = compute_denom(t);
	double output = numerator/denominator;
	return(output);
}